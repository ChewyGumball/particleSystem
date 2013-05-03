#pragma once

#include "Particle.h"

class ParticleGenerator
{
public:
	ParticleGenerator();
	virtual ~ParticleGenerator();

	virtual Particle newParticle() = 0;
};