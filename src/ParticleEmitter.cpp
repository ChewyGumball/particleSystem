#include <algorithm>

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

	if(emitting)
	{
		int particlesToEmit = std::min(static_cast<int>(tick) * particlesPerSecond, maximumParticles - static_cast<int>(particles.size()));

		while(particlesToEmit > 0)
		{
			particles.push_back(generator->newParticle(position, orientation));
			particlesToEmit--;
		}
	}

	for(auto &manipulator : manipulators)
	{
		manipulator->manipulate(particles, tick);
	}

	for(Particle &particle : particles)
	{
		particle.update(tick);
	}
}