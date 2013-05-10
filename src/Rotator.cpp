#include "Rotator.h"

void Rotator::manipulate(std::vector<Particle> &particles, float maximumLife)
{
	for(Particle &p : particles)
	{
		p.angularVelocity = fadeFunction(maximumLife, p.lifeTime, angularAcceleration);
	}
}