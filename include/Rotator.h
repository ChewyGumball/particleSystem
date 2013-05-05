#pragma once

#include <functional>

#include "ParticleManipulator.h"

class  Rotator : public ParticleManipulator
{	
private:
	const float angularAcceleration;
	const std::function<float(float, float)> fadeFunction;

public:
	explicit Rotator(float angularAccel, const std::function<float(float,float)> &fader = [](float tick, float baseAcceleration){ return baseAcceleration; })
		: angularAcceleration(angularAccel), fadeFunction(fader) {}
	virtual ~Rotator() {}

	virtual void manipulate(std::vector<Particle> &particles, float tick);
};