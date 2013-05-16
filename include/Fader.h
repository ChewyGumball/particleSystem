#pragma once

#include <functional>

#include "ParticleManipulator.h"

class  Fader : public ParticleManipulator
{	
private:
	const float fadeAmount;
	const std::function<float(const float&,const Particle&,const float&)> fadeFunction;

public:
	explicit Fader(float fade, const std::function<float(const float&,const Particle&,const float&)> &fader = [](float &maximumLife, const Particle &particle, const float &baseFadeAmount) { return particle.opacity; })
		: fadeAmount(fade), fadeFunction(fader) {}
	virtual ~Fader() {}

	virtual void manipulate(std::vector<Particle> &particles, float maximumLife);
};