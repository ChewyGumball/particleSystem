#include <glm/gtx/quaternion.hpp>

#include "LineGenerator.h"

Particle LineGenerator::newParticle(glm::vec3 &emmitterPosition, glm::quat &emmitterOrientation)
{
	return Particle(0, 
					emmitterPosition + glm::rotate(emmitterOrientation, position), 
					glm::rotate(emmitterOrientation, direction));
}