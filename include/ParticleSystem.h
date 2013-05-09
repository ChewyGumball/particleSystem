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

	ParticleSystem(ParticleSystem &other);
	ParticleSystem(ParticleSystem &&other);
	ParticleSystem& operator=(ParticleSystem rhs);

	void addEmitter(ParticleEmitter *emitter);

	void update(float tick);
	const std::vector<Particle> particles() const;
};