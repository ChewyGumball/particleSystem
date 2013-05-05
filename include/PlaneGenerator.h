#pragma once

#include <glm/gtc/quaternion.hpp>

#include "ParticleGenerator.h"

class  PlaneGenerator : public ParticleGenerator
{
private:


public:
	virtual Particle newParticle(glm::vec3 &emmitterPosition, glm::quat &emmitterOrientation);
};