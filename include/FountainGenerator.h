#pragma once

#include <glm/gtc/quaternion.hpp>


#include "ParticleGenerator.h"

class  FountainGenerator : public ParticleGenerator
{
private:
	glm::vec3 position;
	glm::vec3 direction;
	float deviation;

public:
	FountainGenerator(float fountainAngle, glm::vec3 &pos, glm::vec3 &dir);
	virtual Particle newParticle(glm::vec3 &emmitterPosition, glm::quat &emmitterOrientation);
};