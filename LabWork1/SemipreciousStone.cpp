#include "SemipreciousStone.h"


SemipreciousStone::SemipreciousStone(std::string name, double mass, double price, int transparency, double strength)
	: Stone(name, mass, price, transparency) {
	SemipreciousStone::strength = strength;
}


SemipreciousStone::~SemipreciousStone() {
}


double SemipreciousStone::GetStrength() {
	return strength;
}