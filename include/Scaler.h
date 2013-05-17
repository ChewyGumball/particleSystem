#pragma once

#include <functional>

#include "ParticleManipulator.h"

//Changes the scale of particles
class Scaler : public ParticleManipulator
{	
private:
	const glm::vec2 baseScale;
	std::function<glm::vec2(const float&, const Particle&, const glm::vec2&)> fadeFunction;

public:
	explicit Scaler(const glm::vec2 &scale, const std::function<glm::vec2(const float&, const Particle&, const glm::vec2&)> &fader = [](const float &maxLife, const Particle &p, const glm::vec2& s){ return s; })
		: baseScale(scale), fadeFunction(fader) {}
	virtual void manipulate(std::vector<Particle> &particles, float maximumLife);
};