#pragma once

#include "Model.h"
#include "View.h"

class ProgramController {

public:
	ProgramController(Model & model, View & view);
	~ProgramController();
	void ProcessingUser();

private:
	Model & model;
	View & view;
};

