#pragma once

#include <vector>
#include "PreciousStone.h"
#include "SemipreciousStone.h"
#include <algorithm>
#include "rapidjson\document.h"

class Necklace {

public:
	Necklace();
	~Necklace();
	double GetCommonPrice();
	double GetCommonMass();
	std::vector<Stone*> GetStonesIncluded();
	bool BuildNecklace(rapidjson::Value & document);
	void SortStonesByPrice();
	std::vector<Stone*> FindStonesByTransparency(int from, int to);

private:
	void AddPreciousStone(std::string name, double mass, double price, int transparency, double priceOfCut);
	void AddSemipreciousStone(std::string name, double mass, double price, int transparency, double strength);
	double commonPrice;
	double commonMass;
	std::vector<Stone*> stonesIncluded;
};
