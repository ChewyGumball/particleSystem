#include <glm/gtx/transform.hpp>
#include <glm/gtx/quaternion.hpp>

#include "FountainGenerator.h"

Particle FountainGenerator::newParticle(glm::vec3 &emmitterPosition, glm::quat &emmitterOrientation)
{
	glm::vec3 randomDirection = glm::vec3(glm::rotate(randomDeviation(randomEngine), direction) * glm::rotate(randomDeviation(randomEngine), binormal) * glm::vec4(direction, 1.0f));
	return Particle(0, emmitterPosition + glm::rotate(emmitterOrientation, position), glm::rotate(emmitterOrientation, randomDirection));
}