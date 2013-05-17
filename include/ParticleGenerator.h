#pragma once

#include "Particle.h"

//The abstract base class for particle generators
class ParticleGenerator
{
public:
	virtual ~ParticleGenerator() {}

	virtual Particle newParticle(glm::vec3 &emmitterPosition, glm::quat &emmitterOrientation) = 0;
};