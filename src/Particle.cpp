#include "Particle.h"

void Particle::update(float tick) 
{
	lifeTime += tick;
	position += tick * velocity;
	rotation += tick * angularVelocity;
}

