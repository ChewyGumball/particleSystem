#include "Fader.h"

void Fader::manipulate(std::vector<Particle> &particles, float tick)
{
	float scaledFadeAmount = fadeFunction(tick, fadeAmount);
	for(Particle &p : particles)
	{
		p.opacity += scaledFadeAmount;
	}
}