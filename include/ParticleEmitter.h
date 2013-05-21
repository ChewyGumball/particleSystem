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
	std::shared_ptr<ParticleGenerator> generator;
	
	unsigned int particleLabel;
	glm::vec3 position;
	glm::quat orientation;

	//Emitters shouldn't be copied so these functions are declared private instead of using
	//	the default implementation which is public
	ParticleEmitter(const ParticleEmitter &) {}
	ParticleEmitter& operator=(const ParticleEmitter &) { return *this; }

public:
	//Emits emitRate particles per second, up to a maximum of maxParticles
	//	Each particle lives for maximumLife seconds and is generated from gen, the input particle generator
	ParticleEmitter(std::shared_ptr<ParticleGenerator> gen, unsigned int maxParticles, int emitRate, float maximumLife, int label = 0, const glm::vec3 &pos = glm::vec3(), const glm::quat &orient = glm::quat())
		: emitting(true), maximumParticles(maxParticles), secondsPerParticle(1.0f/static_cast<float>(emitRate)), maximumLifeTime(maximumLife), timeSinceLastEmit(0.0f), generator(gen), 
		  particleLabel(label), position(pos), orientation(orient)
	{}
	virtual ~ParticleEmitter() {}

	void startEmitting();
	void stopEmitting();

	unsigned int particlesAliveCount() const;

	void addManipulator(std::shared_ptr<ParticleManipulator> manipulator);

	const std::vector<Particle>& particleList() const;
	void update(float tick);
};