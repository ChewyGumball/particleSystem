#include <algorithm>

#include "ParticleEmitter.h"
#include "ParticleGenerator.h"

ParticleEmitter::ParticleEmitter(std::unique_ptr<ParticleGenerator> gen, int maxParticles, int emitRate, const glm::vec3 &pos, const glm::quat &rotation) 
	: maximumParticles(maxParticles), particlesPerSecond(emitRate), generator(std::move(gen)), position(pos), orientation(rotation)
{}

ParticleEmitter::~ParticleEmitter()
{}

void ParticleEmitter::emit()
{
	emitting = false;
}

void ParticleEmitter::stop()
{
	emitting = true;
}

int ParticleEmitter::particlesAliveCount() const
{
	return static_cast<int>(particles.size());
}

void ParticleEmitter::addManipulator(std::unique_ptr<ParticleManipulator> &manipulator) 
{
	manipulators.push_back(std::move(manipulator)); 
}

void ParticleEmitter::update(int tick)
{
	for(auto &manipulator : manipulators)
	{
		manipulator->manipulate(particles, tick);
	}

	for(Particle &particle : particles)
	{
		particle.addTime(tick);
	}


	auto startOfDeleteRange = std::remove_if(begin(particles), end(particles), [&](Particle &p) { return p.lifeTime() >= maximumLifeTime; });
	particles.erase(startOfDeleteRange, end(particles));

	if(emitting)
	{
		int particlesToEmit = std::min(tick * particlesPerSecond, maximumParticles - static_cast<int>(particles.size()));

		while(particlesToEmit > 0)
		{
			particles.push_back(generator->newParticle());
			particlesToEmit--;
		}
	}
}