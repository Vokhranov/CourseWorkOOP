#include "PreciousStone.h"


PreciousStone::PreciousStone(std::string name, double mass, double price, int transparency, double priceOfCut)
	: Stone(name, mass, price, transparency) {
	PreciousStone::priceOfCut = priceOfCut;
}

PreciousStone::~PreciousStone() {
}


double PreciousStone::GetPriceOfCut() {
	return priceOfCut;
}