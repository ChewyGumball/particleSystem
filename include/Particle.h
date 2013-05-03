#pragma once

#include <glm/glm.hpp>

class Particle
{
private:

	int _lifeTime;

	float _opacity;

	float _rotation;
	float _angularVelocity;
	
	glm::vec2 _scale;

	glm::vec3 _position;
	glm::vec3 _velocity;

public:
	
	Particle(const glm::vec3 &position, const glm::vec3 &velocity, float rotation = 0.0f, float angularVelocity = 0.0f);
	~Particle();
	
	int lifeTime() const;
	void addTime(int time);

	const glm::vec3& position() const;
	void position(const glm::vec3& pos);

	const glm::vec3& velocity() const;
	void  velocity(glm::vec3& vel);

	const glm::vec2& scale() const;
	void scale(glm::vec2& sc);

	float opacity() const;
	void opacity(float op);

	float rotation() const;
	void rotation(float rot);
	
	float angularVelocity() const;
	void angularVelocity(float vel);
};