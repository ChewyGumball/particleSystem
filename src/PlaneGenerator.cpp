#include <glm/gtx/quaternion.hpp>

#include "PlaneGenerator.h"

Particle PlaneGenerator::newParticle(glm::vec3 &emmitterPosition, glm::quat &emmitterOrientation)
{
	glm::vec3 direction = glm::normalize((randomDirection(randomEngine) * binormal) + (randomDirection(randomEngine) * tangent));
	return Particle(0, emmitterPosition + glm::rotate(emmitterOrientation, direction * randomDistance(randomEngine)), glm::rotate(emmitterOrientation, normal));
}