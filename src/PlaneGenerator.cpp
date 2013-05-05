#include <glm/gtx/quaternion.hpp>

#include "PlaneGenerator.h"

Particle PlaneGenerator::newParticle(glm::vec3 &emmitterPosition, glm::quat &emmitterOrientation)
{
	return Particle(0, emmitterPosition, glm::vec3(1.0,0.0,0.0));
}