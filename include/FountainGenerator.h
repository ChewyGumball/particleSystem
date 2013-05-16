#pragma once
#include <random>

#include <glm/gtc/quaternion.hpp>

#include "ParticleGenerator.h"
#include "GLMUtilities.h"

class  FountainGenerator : public ParticleGenerator
{
private:
	glm::vec3 position;
	glm::vec3 direction;
	glm::vec3 binormal;
	
	std::default_random_engine randomEngine;
	std::uniform_real_distribution<float> randomDeviation;

public:
	FountainGenerator(float fountainAngle, glm::vec3 &pos, glm::vec3 &dir)
		: position(pos), direction(dir), binormal(perpendicular(direction)),
		  randomDeviation(std::uniform_real_distribution<float>(-fountainAngle / 2.0f, fountainAngle / 2.0f))
	{}
	virtual ~FountainGenerator() {}

	virtual Particle newParticle(glm::vec3 &emmitterPosition, glm::quat &emmitterOrientation);
};