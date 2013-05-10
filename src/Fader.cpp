#include "Fader.h"

void Fader::manipulate(std::vector<Particle> &particles, float maximumLife)
{
	for(Particle &p : particles)
	{
			p.opacity = fadeFunction(maximumLife, p, fadeAmount);
	}
}