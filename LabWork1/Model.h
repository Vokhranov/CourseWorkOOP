#pragma once
#include "View.h"
#include "Necklace.h"
#include "PreciousStone.h"
#include "SemipreciousStone.h"
#include <fstream>
#include "rapidjson\document.h"   //Включено в проект (project's include path)

class Model {

public:
	Model(View & view);
	~Model();
	bool CreateNecklaces();
	std::vector<Necklace*> usersNecklaces;
private:
	View & view;
	rapidjson::Document ParceJson(std::string wayToJsonFile);
};

