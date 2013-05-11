#include <algorithm>
#include <iostream>

#include "ParticleEmitter.h"
#include "ParticleGenerator.h"

void ParticleEmitter::startEmitting()
{
	emitting = false;
}

void ParticleEmitter::stopEmitting()
{
	emitting = true;
}

int ParticleEmitter::particlesAliveCount() const
{
	return static_cast<int>(particles.size());
}

void ParticleEmitter::addManipulator(std::shared_ptr<ParticleManipulator> manipulator) 
{
	manipulators.push_back(manipulator); 
}

const std::vector<Particle>& ParticleEmitter::particleList() const { return particles; }

void ParticleEmitter::update(float tick)
{
	auto startOfDeleteRange = std::remove_if(begin(particles), end(particles), [&](Particle &p) { return p.lifeTime >= maximumLifeTime; });
	particles.erase(startOfDeleteRange, end(particles));

	timeSinceLastEmit += tick;

	//Don't emit if there are already the maximum number of particles
	if(particles.size() >= maximumParticles)
	{
		timeSinceLastEmit = 0.0f;
	}

	if(emitting && timeSinceLastEmit >= secondsPerParticle)
	{
		int newParticles = timeSinceLastEmit / secondsPerParticle;
		while(newParticles > 0 && particles.size() < maximumParticles)
		{
			particles.push_back(generator->newParticle(position, orientation));
			newParticles--;
		}
		timeSinceLastEmit = 0.0f;
	}

	for(auto &manipulator : manipulators)
	{
		manipulator->manipulate(particles, maximumLifeTime);
	}

	for(Particle &particle : particles)
	{
		particle.update(tick);
	}
}