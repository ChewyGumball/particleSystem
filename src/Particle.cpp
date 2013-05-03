#include "Particle.h"


Particle::Particle(const glm::vec3 &position, const glm::vec3 &velocity, float rotation, float angularVelocity) 
	: _lifeTime(0), _position(position), _velocity(velocity), _rotation(rotation), _angularVelocity(angularVelocity) 
{}
Particle::~Particle(){}

int Particle::lifeTime() const { return _lifeTime; }
void Particle::addTime(int time) { _lifeTime += time; }

const glm::vec3& Particle::position() const { return _position; }
void Particle::position(const glm::vec3& pos) { _position = pos; }


const glm::vec3& Particle::velocity() const { return _velocity; }
void  Particle::velocity(glm::vec3& vel) {_velocity = vel; }

const glm::vec2&  Particle::scale() const { return _scale; }
void  Particle::scale(glm::vec2& sc) { _scale = sc; }

float  Particle::opacity() const { return _opacity; }
void  Particle::opacity(float op) { _opacity = op; }

float Particle::rotation() const { return _rotation; }
void Particle::rotation(float rot) { _rotation = rot; } 

float  Particle::angularVelocity() const { return _angularVelocity; }
void  Particle::angularVelocity(float vel) { _angularVelocity = vel; }
