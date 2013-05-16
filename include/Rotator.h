#pragma once

#include <functional>

#include "ParticleManipulator.h"

class Rotator : public ParticleManipulator
{	
private:
	const float angularAcceleration;
	const std::function<float(const float&,const Particle&,const float&)> fadeFunction;

public:
	explicit Rotator(float angularAccel, const std::function<float(const float&,const Particle&,const float&)> &fader = [](const float &maximumLife, const Particle &particle, const float &baseAcceleration){ return particle.angularVelocity; })
		: angularAcceleration(angularAccel), fadeFunction(fader) {}
	virtual ~Rotator() {}

	virtual void manipulate(std::vector<Particle> &particles, float maximumLife);
};