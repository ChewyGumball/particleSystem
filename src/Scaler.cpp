#include "Scaler.h"

void Scaler::manipulate(std::vector<Particle> &particles, float maximumLife)
{
	for(Particle &p : particles)
	{
		p.scale = fadeFunction(maximumLife, p, baseScale);
	}
}