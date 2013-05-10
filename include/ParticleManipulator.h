#pragma once

#include <vector>

#include "Particle.h"

class ParticleManipulator
{
public:
	virtual ~ParticleManipulator() {}

	virtual void manipulate(std::vector<Particle> &particles, float maximumLife) = 0;
};

