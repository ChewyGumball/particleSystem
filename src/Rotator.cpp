#include "Rotator.h"

void Rotator::manipulate(std::vector<Particle> &particles, float tick)
{
	float scaledAcceleration = fadeFunction(tick, angularAcceleration);
	for(Particle &p : particles)
	{
		p.angularVelocity += scaledAcceleration;
	}
}