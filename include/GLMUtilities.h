#pragma once
namespace
{
	glm::vec3 perpendicular(const glm::vec3 &v)
	{
		if(v.x == 0.0f && v.y == 0.0f) return glm::vec3(v.x, -v.z, v.y);
		else return glm::vec3(-v.y, v.x, v.z);
	}
}