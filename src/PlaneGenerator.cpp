#include <glm/gtx/quaternion.hpp>

#include "PlaneGenerator.h"

Particle PlaneGenerator::newParticle(unsigned int label, glm::vec3 &emmitterPosition, glm::quat &emmitterOrientation)
{
	//Create a random direction on the plane
	glm::vec3 direction = glm::normalize((randomDirection(randomEngine) * binormal) + (randomDirection(randomEngine) * tangent));
	
	return Particle(label, 
					emmitterPosition + glm::rotate(emmitterOrientation, direction * randomDistance(randomEngine)), 
					glm::rotate(emmitterOrientation, normal));
}