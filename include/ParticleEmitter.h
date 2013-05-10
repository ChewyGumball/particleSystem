#pragma once

#include <vector>
#include <memory>

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

#include "Particle.h"
#include "ParticleManipulator.h"
#include "ParticleGenerator.h"

class ParticleEmitter
{
private:
	bool emitting;
	unsigned int maximumParticles;
	float secondsPerParticle;
	float maximumLifeTime;

	float timeSinceLastEmit;

	std::vector<Particle> particles;
	std::vector<std::shared_ptr<ParticleManipulator>> manipulators;
	std::unique_ptr<ParticleGenerator> generator;

	glm::vec3 position;
	glm::quat orientation;

	ParticleEmitter(const ParticleEmitter &) {}
	ParticleEmitter& operator=(const ParticleEmitter &) { return *this; }

public:

	ParticleEmitter(std::unique_ptr<ParticleGenerator> gen, unsigned int maxParticles, int emitRate, float maximumLife, const glm::vec3 &pos = glm::vec3(), const glm::quat &orient = glm::quat())
		: emitting(true), maximumParticles(maxParticles), secondsPerParticle(1.0f/static_cast<float>(emitRate)), maximumLifeTime(maximumLife), timeSinceLastEmit(0.0f), generator(std::move(gen)), position(pos), orientation(orient)
	{}
	virtual ~ParticleEmitter() {}

	void startEmitting();
	void stopEmitting();

	int particlesAliveCount() const;

	void addManipulator(std::shared_ptr<ParticleManipulator> manipulator);

	const std::vector<Particle>& particleList() const;
	void update(float tick);
};