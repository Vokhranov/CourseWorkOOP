#include <iostream>
#include "ProgramController.h"
#include "Model.h"
#include "View.h"

int main() {
	setlocale(LC_ALL, "RUS");
	int lang;
	std::cout << "Choose language / Выберите язык: \n1 - English \n2 - Русский " << std::endl;
	std::cin >> lang;

	View view(lang);
	Model model(view);
	ProgramController controller(model, view);

	try {
		controller.ProcessingUser();
	}
	catch (const char *error) {
		std::cout << "Error has been occured: " << error << std::endl;
		
	}
	
	
	system("pause");
	return 0;
}