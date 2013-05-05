#pragma once

#include "Particle.h"

class  ParticleGenerator
{
public:
	virtual ~ParticleGenerator() {}

	virtual Particle newParticle(glm::vec3 &emmitterPosition, glm::quat &emmitterOrientation) = 0;
};