#include "Accelerator.h"

void Accelerator::manipulate(std::vector<Particle> &particles, float maximumLife)
{
	for(Particle &p : particles)
	{
		p.velocity = fadeFunction(maximumLife, p, acceleration);
	}
}