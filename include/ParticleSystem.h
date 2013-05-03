#pragma once

#include <vector>
#include <glm/glm.hpp>

#include "ParticleEmitter.h"

class ParticleSystem
{
private:
	glm::vec4 position;

	std::vector<ParticleEmitter> emitters;

public:

	ParticleSystem();
	~ParticleSystem();

	ParticleSystem(ParticleSystem &other);
	ParticleSystem(ParticleSystem &&other);
	ParticleSystem& operator=(ParticleSystem rhs);
};