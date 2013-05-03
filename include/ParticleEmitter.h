#pragma once

#include <vector>
#include <memory>

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

#include "Particle.h"
#include "ParticleManipulator.h"

class ParticleGenerator;

class ParticleEmitter
{
private:
	bool emitting;
	int maximumParticles;
	int particlesPerSecond;
	int maximumLifeTime;

	std::vector<Particle> particles;
	std::vector<std::unique_ptr<ParticleManipulator>> manipulators;
	std::unique_ptr<ParticleGenerator> generator;

	glm::vec3 position;
	glm::quat orientation;
	
public:

	ParticleEmitter(std::unique_ptr<ParticleGenerator> gen, int maxParticles, int emitRate, const glm::vec3 &pos = glm::vec3(), const glm::quat &orientation = glm::quat());
	virtual ~ParticleEmitter();

	void emit();
	void stop();

	int particlesAliveCount() const;

	void addManipulator(std::unique_ptr<ParticleManipulator> &manipulator);
	
	void update(int tick);
};