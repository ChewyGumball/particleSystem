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
	int maximumParticles;
	int particlesPerSecond;
	int maximumLifeTime;

	std::vector<Particle> particles;
	std::vector<std::shared_ptr<ParticleManipulator>> manipulators;
	std::unique_ptr<ParticleGenerator> generator;

	glm::vec3 position;
	glm::quat orientation;

	ParticleEmitter(const ParticleEmitter &) {}
	ParticleEmitter& operator=(const ParticleEmitter &) { return *this; }

public:

	ParticleEmitter(std::unique_ptr<ParticleGenerator> gen, int maxParticles, int emitRate, const glm::vec3 &pos = glm::vec3(), const glm::quat &orient = glm::quat())
		: emitting(true), maximumParticles(maxParticles), particlesPerSecond(emitRate), generator(std::move(gen)), position(pos), orientation(orient)
	{}
	virtual ~ParticleEmitter() {}

	void startEmitting();
	void stopEmitting();

	int particlesAliveCount() const;

	void addManipulator(std::shared_ptr<ParticleManipulator> manipulator);

	const std::vector<Particle>& particleList() const;
	void update(float tick);
};