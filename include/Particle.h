#pragma once

#include <glm/glm.hpp>

struct  Particle
{
	unsigned int label;

	float lifeTime;
	
	float opacity;
	float rotation;
	float angularVelocity;

	glm::vec2 scale;
	
	glm::vec3 position;
	glm::vec3 velocity;

	Particle(unsigned int label, const glm::vec3 &position, const glm::vec3 &velocity, float rotation = 0.0f, float angularVelocity = 0.0f, const glm::vec2 &scale = glm::vec2(1,1), float opacity = 1.0)
		:  label(label), lifeTime(0.0), opacity(opacity), rotation(rotation), angularVelocity(angularVelocity), scale(scale), position(position), velocity(velocity)
	{}
	/* Convenience constructors for different combinations of parameters - would use constructor delegation if compiler supported it

	Particle(const glm::vec3 &position, const glm::vec3 &velocity, float rotation, float angularVelocity, float opacity);
	Particle(const glm::vec3 &position, const glm::vec3 &velocity, const glm::vec2 &scale, float opacity);
	Particle(const glm::vec3 &position, const glm::vec3 &velocity, const glm::vec2 &scale);
	Particle(const glm::vec3 &position, const glm::vec3 &velocity, float opacity);
	//*/

	~Particle() {}



	void update(float tick);
};