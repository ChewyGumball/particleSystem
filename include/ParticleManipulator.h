#pragma once

#include <vector>

#include "Particle.h"

class ParticleManipulator
{
public:
	ParticleManipulator();
	virtual ~ParticleManipulator();

	virtual void manipulate(std::vector<Particle> &particles, int tick) = 0;
};

