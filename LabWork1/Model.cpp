#include "Model.h"


Model::Model(View & view)
	: view(view) {
}


Model::~Model() {
	if (usersNecklaces.size() != 0) {
		for (unsigned int i = 0; i < usersNecklaces.size(); i++) {
			delete usersNecklaces[i];
		}
	}
}


bool Model::CreateNecklaces() {
	std::string wayToJsonFile = "DataFiles\\necklaces.json";
	rapidjson::Document document;
	document = ParceJson(wayToJsonFile);
	if (!document.IsObject() || !document.HasMember("necklaces") || !document["necklaces"].IsArray()) {
		view.Print(view.JSON_INVALID);
		return false;
	}
	
	for (rapidjson::SizeType i = 0; i < document["necklaces"].Size(); i++) {
		if (!document["necklaces"][i].IsObject()) {
			view.Print(view.JSON_INVALID);
			return false;
		}
		Necklace *necklace = new Necklace();
		if (!necklace->BuildNecklace(document["necklaces"][i])) {
			view.Print(view.JSON_INVALID);
			return false;
		}
		Model::usersNecklaces.push_back(necklace);
	}	
	return true;
}

rapidjson::Document Model::ParceJson(std::string wayToJsonFile) {
	
	std::string parceString;
	std::string buff;
	std::ifstream neckFile(wayToJsonFile);

	if (!neckFile.is_open())
		throw "JSON FILE IS NOT OPENED";
	

	while (std::getline(neckFile, buff)) {
		parceString += buff;
	}

	parceString.erase(std::remove(parceString.begin(), parceString.end(), '\t'), parceString.end());
	parceString.erase(std::remove(parceString.begin(), parceString.end(), ' '), parceString.end());

	rapidjson::Document document;
	if (document.Parse(parceString.c_str()).HasParseError())
		throw "JSON FILE PARCE ERROR";
	else
		return document;
}
