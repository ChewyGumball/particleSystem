#include <glm/gtx/transform.hpp>
#include <glm/gtx/quaternion.hpp>

#include "FountainGenerator.h"

Particle FountainGenerator::newParticle(unsigned int label, glm::vec3 &emmitterPosition, glm::quat &emmitterOrientation)
{
	//Rotation perpendicular to the fountain direction
	glm::mat4 perpendicularRotation =  glm::rotate(randomDeviation(randomEngine), binormal);
	//Rotation around the fountain direction
	glm::mat4 parallelRotation = glm::rotate(randomDeviation(randomEngine), direction);

	//Combine previous two rotations to create a random direction within the fountain's cone
	glm::vec3 randomDirection = glm::vec3(parallelRotation * perpendicularRotation * glm::vec4(direction, 1.0f));

	return Particle(label, 
					emmitterPosition + glm::rotate(emmitterOrientation, position), 
					glm::rotate(emmitterOrientation, randomDirection));
}