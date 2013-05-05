#pragma once

#include <glm/gtc/quaternion.hpp>


#include "ParticleGenerator.h"

class  FountainGenerator : public ParticleGenerator
{
public:
	virtual Particle newParticle(glm::vec3 &emmitterPosition, glm::quat &emmitterOrientation);
};