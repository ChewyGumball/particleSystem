#include <algorithm>
#include <iterator>

#include "ParticleEmitter.h"
#include "ParticleGenerator.h"

void ParticleEmitter::startEmitting() {	emitting = true; }

void ParticleEmitter::stopEmitting() { emitting = false; }

unsigned int ParticleEmitter::particlesAliveCount() const { return particles.size(); }

const std::vector<Particle>& ParticleEmitter::particleList() const { return particles; }

void ParticleEmitter::addManipulator(std::shared_ptr<ParticleManipulator> manipulator) 
{
	manipulators.push_back(manipulator); 
}

void ParticleEmitter::update(float tick)
{
	//Remove particles which have exceeded their maximum life time
	auto startOfDeleteRange = std::remove_if(begin(particles), end(particles), [&](Particle &p) 
	{
		return p.lifeTime >= maximumLifeTime; 
	});
	particles.erase(startOfDeleteRange, end(particles));

	//Update timer with the update tick
	timeSinceLastEmit += tick;

	//Don't emit if there are already the maximum number of particles by resetting the timer
	if(particles.size() >= maximumParticles)
	{
		timeSinceLastEmit = 0.0f;
	}

	//Emit new particles
	if(emitting && timeSinceLastEmit >= secondsPerParticle)
	{
		//Find the number of particles to emit
		unsigned int newParticles = std::min(static_cast<unsigned int>(timeSinceLastEmit / secondsPerParticle), maximumParticles - particles.size());
		//Have the generator create the new particles
		while(newParticles > 0)
		{
			particles.push_back(generator->newParticle(particleLabel, position, orientation));
			newParticles--;
		}
		//Reset timer
		timeSinceLastEmit = 0.0f;
	}

	//Have manipulators manipulate the live particles
	for(auto &manipulator : manipulators)
	{
		manipulator->manipulate(particles, maximumLifeTime);
	}

	//Have particles update their position, rotation, and lifetime
	for(Particle &particle : particles)
	{
		particle.update(tick);
	}
}