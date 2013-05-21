#pragma once
namespace
{
	//Generates a perpendicular vector NOT using cross product and thus
	//	needs only a single vector as input
	glm::vec3 perpendicular(const glm::vec3 &v)
	{
		if(v.x == 0.0f && v.y == 0.0f) return glm::vec3(v.x, -v.z, v.y);
		else return glm::vec3(-v.y, v.x, v.z);
	}
}