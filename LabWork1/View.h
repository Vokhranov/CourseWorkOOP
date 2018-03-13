#pragma once
#include <string>
#include <vector>
#include "Necklace.h"
#include "PreciousStone.h"
#include "SemipreciousStone.h"

class View {

private:
	std::string V_MASS;
	std::string V_PRICE;
	std::string V_TRANSPARRENCY;
	std::string V_CARATES;
	std::string V_NECKLACE;

public:
	View(int key);
	~View();
	void View::Print(int value);
	void View::Print(double value);
	void View::Print(std::string value);
	void View::PrintVectorOfStones(std::vector<Stone*> vectorOfStones);
	void View::ShowAllNecklaces(std::vector<Necklace*> vectorOfNecklaces);

	std::string HELLO;
	std::string NACKLACES_ARE_BUILDED;
	std::string STONES_IN_NECKLACE;
	std::string FINAL_COST;
	std::string FINAL_MASS;
	std::string STONES_ARE_SORTED;
	std::string GIVE_ME_RANGE_OF_TRANSPARECY;
	std::string END;
	std::string WRONG_INPUT;
	std::string CHOOSE_NECKLACE;
	std::string NECKLACE_MENU;
	std::string JSON_IS_NOT_OPENED;
	std::string PARCE_ERROR;
	std::string NEW_LINE;
	std::string JSON_INVALID;
	std::string NO_ELEM_IN_JSON;
	std::string NECKLACE_NOT_FOUND;
	std::string NO_NECKLACES;
	std::string NO_STONES;
};