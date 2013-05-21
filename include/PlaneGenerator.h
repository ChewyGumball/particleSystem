#pragma once
#include <random>

#include <glm/gtc/quaternion.hpp>

#include "ParticleGenerator.h"
#include "GLMUtilities.h"

//Generates particles randomly within a circle on a plane
class  PlaneGenerator : public ParticleGenerator
{
private:
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec3 binormal;
	glm::vec3 tangent;

	std::default_random_engine randomEngine;
	std::uniform_real_distribution<float> randomDistance;
	std::uniform_real_distribution<float> randomDirection;

public:
	PlaneGenerator(const glm::vec3 &pos, const glm::vec3 &norm, const float &maxDistance)
		: position(pos), normal(norm), binormal(perpendicular(norm)), tangent(glm::cross(normal, binormal)), 
		randomDistance(std::uniform_real_distribution<float>(-maxDistance, maxDistance)),
		randomDirection(std::uniform_real_distribution<float>(-1.0f, 1.0f))
	{}
	virtual ~PlaneGenerator() {}

	virtual Particle newParticle(unsigned int label, glm::vec3 &emmitterPosition, glm::quat &emmitterOrientation);
};