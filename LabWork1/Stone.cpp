#include "Stone.h"


Stone::Stone() {
}

Stone::Stone(std::string name, double mass, double price, int transparency) {
	Stone::name = name;
	Stone::mass = mass;
	Stone::price = price;
	Stone::transparency = transparency;
}


Stone::~Stone() {
}

std::string Stone::GetName() {
	return name;
}

double Stone::GetMass() {
	return mass;
}

double Stone::GetPrice() {
	return price;
}

int Stone::GetTransparency() {
	return transparency;
}
