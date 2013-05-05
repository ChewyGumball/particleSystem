#pragma once

#include <functional>

#include "ParticleManipulator.h"

class  Fader : public ParticleManipulator
{	
private:
	const float fadeAmount;
	const std::function<float(float,float)> fadeFunction;

public:
	explicit Fader(float fade, const std::function<float(float,float)> &fader = [](float tick, float baseFadeAmount) { return baseFadeAmount; })
		: fadeAmount(fade), fadeFunction(fader) {}
	virtual ~Fader() {}

	virtual void manipulate(std::vector<Particle> &particles, float tick);
};