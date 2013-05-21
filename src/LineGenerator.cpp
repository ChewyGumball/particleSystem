#include <glm/gtx/quaternion.hpp>

#include "LineGenerator.h"

Particle LineGenerator::newParticle(unsigned int label, glm::vec3 &emmitterPosition, glm::quat &emmitterOrientation)
{
	return Particle(label, 
					emmitterPosition + glm::rotate(emmitterOrientation, position), 
					glm::rotate(emmitterOrientation, direction));
}