#pragma once
#include <string>

class Stone {

public:
	Stone();
	Stone(std::string name, double mass, double price, int transparency);
	~Stone();

	std::string GetName();
	double GetMass();
	double GetPrice();
	int GetTransparency();

	/*void SetMass(double & mass);
	void SetPrice(double & price);
	void SetTransparency(double & transparency);*/

protected:
	std::string name;
	double mass;
	double price;
	int transparency;
};

