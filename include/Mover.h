#pragma once

#include <functional>

#include <glm/glm.hpp>

#include "ParticleManipulator.h"

class Mover : public ParticleManipulator
{	
private:
	const glm::vec3 acceleration;
	const std::function<glm::vec3(float,float,glm::vec3)> fadeFunction;

public:
	explicit Mover(const glm::vec3 &accel, const std::function<glm::vec3(float,float,glm::vec3&)> &fader = [](float maximumLife, float currentLife, glm::vec3 &baseAcceleration){ return baseAcceleration; }) 
		: acceleration(accel), fadeFunction(fader) {}
	virtual ~Mover() {}

	virtual void manipulate(std::vector<Particle> &particles, float maximumLife);
};