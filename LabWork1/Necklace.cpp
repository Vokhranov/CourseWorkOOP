#include "Necklace.h"
#include <iostream>


Necklace::Necklace() {
	Necklace::commonMass = 0;
	Necklace::commonPrice = 0;
}


Necklace::~Necklace() {

	for (unsigned int i = 0; i < stonesIncluded.size(); i++) {
		delete stonesIncluded[i];
	}
	std::cout << "done" << std::endl;
}


double Necklace::GetCommonMass() {
	return commonMass;
}

double Necklace::GetCommonPrice() {
	return commonPrice;
}

std::vector<Stone*> Necklace::GetStonesIncluded() {
	return Necklace::stonesIncluded;
}

void Necklace::AddPreciousStone(std::string name, double mass, double price, int transparency, double priceOfCut) {
	PreciousStone *stone = new PreciousStone(name, mass, price, transparency, priceOfCut);
	Necklace::stonesIncluded.push_back(stone);
	Necklace::commonPrice += price + priceOfCut;
	Necklace::commonMass += mass;
}

void Necklace::AddSemipreciousStone(std::string name, double mass, double price, int transparency, double strength) {
	SemipreciousStone *stone = new SemipreciousStone(name, mass, price, transparency, strength);
	Necklace::stonesIncluded.push_back(stone);
	Necklace::commonPrice += price + round(pow(strength, -1) * 73.4 * 10) / 10;
	Necklace::commonMass += mass;
}

bool Necklace::BuildNecklace(rapidjson::Value & thisNecklace) {
	
	if (!thisNecklace.HasMember("preciousStones") || !thisNecklace.HasMember("semipreciousStones"))
		return false;

	const rapidjson::Value& precStone = thisNecklace["preciousStones"];
	const rapidjson::Value& semiprecStone = thisNecklace["semipreciousStones"];
	
	std::string name;
	double mass, price, priceOfCut,	strength;
	int transparency;

	for (rapidjson::SizeType i = 0; i < thisNecklace["preciousStones"].Size(); i++) {
		if (!precStone[i]["name"].IsString() || !precStone[i]["mass"].IsDouble() || !precStone[i]["price"].IsDouble()
			|| !precStone[i]["transparency"].IsInt() || !precStone[i]["priceOfCut"].IsDouble())
			return false;
		name = precStone[i]["name"].GetString();
		mass = precStone[i]["mass"].GetDouble();
		price = precStone[i]["price"].GetDouble();
		transparency = precStone[i]["transparency"].GetInt();
		priceOfCut = precStone[i]["priceOfCut"].GetDouble();

		AddPreciousStone(name, mass, price, transparency, priceOfCut);
	}
	for (rapidjson::SizeType i = 0; i < thisNecklace["semipreciousStones"].Size(); i++) {
		if (!semiprecStone[i]["name"].IsString() || !semiprecStone[i]["mass"].IsDouble() || !semiprecStone[i]["price"].IsDouble()
			|| !semiprecStone[i]["transparency"].IsInt() || !semiprecStone[i]["strength"].IsDouble())
			return false;
		name = semiprecStone[i]["name"].GetString();
		mass = semiprecStone[i]["mass"].GetDouble();
		price = semiprecStone[i]["price"].GetDouble();
		transparency = semiprecStone[i]["transparency"].GetInt();
		strength = semiprecStone[i]["strength"].GetDouble();

		AddSemipreciousStone(name, mass, price, transparency, strength);
	}
	return true;
}

std::vector<Stone*> Necklace::FindStonesByTransparency(int from, int to) {
	std::vector<Stone*> relevantStones;

	for (unsigned int i = 0; i < stonesIncluded.size(); i++) {
		if (stonesIncluded[i]->GetTransparency() >= from && stonesIncluded[i]->GetTransparency() <= to)
			relevantStones.push_back(stonesIncluded[i]);
	}
	return relevantStones;
}

bool cmp(Stone *stoneOne, Stone *stoneTwo) {
	return stoneOne->GetPrice() < stoneTwo->GetPrice();
}

void Necklace::SortStonesByPrice() {
	std::sort(stonesIncluded.begin(), stonesIncluded.end(), cmp);
}