#pragma once
#include "Stone.h"

class PreciousStone : public Stone {

public:
	PreciousStone(std::string name, double mass, double price, int transparency, double priceOfCut);
	~PreciousStone();
	double GetPriceOfCut();

private:
	double priceOfCut;
};

