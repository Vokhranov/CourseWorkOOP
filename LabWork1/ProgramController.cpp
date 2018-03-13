#include "ProgramController.h"
#include <iostream>


ProgramController::ProgramController(Model & model, View & view)
	: model(model), view(view) {
}


ProgramController::~ProgramController() {
}


void ProgramController::ProcessingUser() {

	bool globalFlag = true, necklaceFlag = true;
	
	view.Print(view.HELLO);
	if (!model.CreateNecklaces())
		return;
	view.Print(view.NACKLACES_ARE_BUILDED);
	view.ShowAllNecklaces(model.usersNecklaces);
	view.Print(view.NEW_LINE);
	int necklace, command;
	
	while (globalFlag) {
		necklaceFlag = true;
		view.Print(view.CHOOSE_NECKLACE);
		std::cin >> necklace;
		necklace --;
		if (necklace == -1) {
			view.Print(view.END);
			return;
		}
		else if (necklace > (model.usersNecklaces.size() - 1) || necklace < -1) {
			view.Print(view.NECKLACE_NOT_FOUND);
			necklaceFlag = false;
		}

		while (necklaceFlag) {
			view.Print(view.NECKLACE_MENU);
			std::cin >> command;
			
			switch (command) {
			case 1: {
				view.Print(view.STONES_IN_NECKLACE);
				view.PrintVectorOfStones(model.usersNecklaces[necklace]->GetStonesIncluded());
				break;
			}
			case 2: {
				view.Print(view.FINAL_COST);
				view.Print(model.usersNecklaces[necklace]->GetCommonPrice());
				break;
			}
			case 3: {
				view.Print(view.FINAL_MASS);
				view.Print(model.usersNecklaces[necklace]->GetCommonMass());
				break;
			}
			case 4: {
				model.usersNecklaces[necklace]->SortStonesByPrice();
				view.Print(view.STONES_ARE_SORTED);
				break;
			}
			case 5: {
				view.Print(view.GIVE_ME_RANGE_OF_TRANSPARECY);
				int from, to;
				std::cin >> from >> to;
				view.PrintVectorOfStones(model.usersNecklaces[necklace]->FindStonesByTransparency(from, to));
				break;
			}
			case 6: {
				necklaceFlag = false;
				break;
			}
			case 0: {
				view.Print(view.END);
				return;
			}
			default:
				view.Print(view.WRONG_INPUT);
				return;
			}
		}		
	}
}
