#pragma once

#include <functional>

#include "ParticleManipulator.h"

class  Fader : public ParticleManipulator
{	
private:
	const float fadeAmount;
	const std::function<float(float,Particle&,float)> fadeFunction;

public:
	explicit Fader(float fade, const std::function<float(float,Particle&,float)> &fader = [](float maximumLife, Particle &particle, float baseFadeAmount) { return particle.opacity; })
		: fadeAmount(fade), fadeFunction(fader) {}
	virtual ~Fader() {}

	virtual void manipulate(std::vector<Particle> &particles, float maximumLife);
};