#include <stdlib.h>
#include <time.h>

#include <glm/gtx/transform.hpp>
#include <glm/gtx/quaternion.hpp>

#include "FountainGenerator.h"

namespace
{
	bool initialized;
	void seedRandom()
	{
		if(!initialized)
		{
			srand(time(0));
			initialized = true;
		}
	}

	glm::vec3 randomDirection(float maxAngle, glm::vec3 &direction)
	{
		glm::vec3 perpendicular;
		if(direction.x == 0 && direction.y == 0)
		{
			perpendicular = glm::vec3(direction.x, -direction.z, direction.y);
		}
		else
		{
			perpendicular = glm::vec3(direction.y, -direction.x, direction.z);
		}

		float angle = ((float)rand() * maxAngle / RAND_MAX) - (maxAngle / 2);
		float angle2 = ((float)rand() * maxAngle / RAND_MAX) - (maxAngle / 2);

		return glm::vec3(glm::rotate(angle2, direction) * glm::rotate(angle, perpendicular) * glm::vec4(direction, 1.0f));
	}
}
FountainGenerator::FountainGenerator(float fountainAngle, glm::vec3 &pos, glm::vec3 &dir) : position(pos), direction(dir), deviation(fountainAngle) 
{
	seedRandom();
}
Particle FountainGenerator::newParticle(glm::vec3 &emmitterPosition, glm::quat &emmitterOrientation)
{
	return Particle(0, emmitterPosition + glm::rotate(emmitterOrientation, position), glm::rotate(emmitterOrientation, randomDirection(deviation, direction)));
}