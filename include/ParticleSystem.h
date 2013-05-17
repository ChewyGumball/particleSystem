#pragma once

#include <vector>

#include <glm/glm.hpp>

#include "ParticleEmitter.h"

class ParticleSystem
{
private:
	std::vector<ParticleEmitter*> emitters;

public:

	ParticleSystem() {}
	~ParticleSystem() {}
	
	void addEmitter(ParticleEmitter *emitter);

	void update(float tick);
	const std::vector<Particle> particles() const;
};