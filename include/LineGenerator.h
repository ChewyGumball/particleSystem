#pragma once

#include <glm/gtc/quaternion.hpp>


#include "ParticleGenerator.h"

class  LineGenerator : public ParticleGenerator
{
private:
	glm::vec3 position;
	glm::vec3 direction;

public:
	LineGenerator(glm::vec3 &pos, glm::vec3 dir) : position(pos), direction(dir) {}
	virtual ~LineGenerator() {}

	virtual Particle newParticle(glm::vec3 &emmitterPosition, glm::quat &emmitterOrientation);
};