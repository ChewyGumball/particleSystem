// particleSystem.cpp : Defines the entry point for the console application.
//

#include "ParticleSystem.h"


void ParticleSystem::addEmitter(ParticleEmitter *emitter)
{
	emitters.push_back(emitter);
}

void ParticleSystem::update(float tick)
{
	for(auto &emitter: emitters)
	{
		emitter->update(tick);
	}
}

const std::vector<Particle> ParticleSystem::particles() const
{
	std::vector<Particle> collectedParticles;

	for(const ParticleEmitter* const emitter: emitters)
	{
		const std::vector<Particle> &emitterParticles = emitter->particleList();
		collectedParticles.insert(end(collectedParticles), begin(emitterParticles), end(emitterParticles));
	}

	return collectedParticles;
}
