#include <glm/gtx/quaternion.hpp>

#include "FountainGenerator.h"

Particle FountainGenerator::newParticle(glm::vec3 &emmitterPosition, glm::quat &emmitterOrientation)
{
	return Particle(0, emmitterPosition, glm::vec3(1.0,0.0,0.0));
}