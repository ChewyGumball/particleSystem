#include "Mover.h"

void Mover::manipulate(std::vector<Particle> &particles, float tick)
{
	glm::vec3 scaledAcceleration = fadeFunction(tick, acceleration);
	for(Particle &p : particles)
	{
		p.velocity += scaledAcceleration;
	}
}