#pragma once
#include "Stone.h"

class SemipreciousStone : public Stone {

public:
	SemipreciousStone(std::string name, double mass, double price, int transparency, double strength);
	~SemipreciousStone();
	double GetStrength();

private:
	double strength;
};

