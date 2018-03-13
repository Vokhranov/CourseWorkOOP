#include "View.h"
#include <iostream>

View::View(int key) {

	if (key != 2) {
		HELLO = "Hello, welcome to our program! ";
		NACKLACES_ARE_BUILDED = "Your necklaces are ready.";
		STONES_IN_NECKLACE = "Necklace includes such stones: ";
		FINAL_COST = "Final cost of your necklace is: ";
		FINAL_MASS = "The weight of your necklace in carats is: ";
		STONES_ARE_SORTED = "Stones in Necklace are sorted by price.";
		GIVE_ME_RANGE_OF_TRANSPARECY = "Please give a range of transparency for stones in your necklace you want to be displayed. From... to...: ";
		END = "Thank you for using our program. Goodbye :) ";
		WRONG_INPUT = "Sorry, you've typed wrong command ";
		CHOOSE_NECKLACE = "Choose necklace, you want to work with (type a number) or type 0 to end the program:";
		NECKLACE_MENU = "\nWhat do you want to do? Commands: \n1 - Show necklace \n2 - Get price of necklace \n3 - Get mass of necklace \n4 - Sort stones in necklace by price \n5 - Find stones in necklace which sutisfy some range of transparency \n6 - choose another necklace \n0 - Exit the program \n";
		JSON_IS_NOT_OPENED = "Sorry, something went wrong, JSON file can not be opened ";
		PARCE_ERROR = "Error, JSON file can not be parsed, check it. ";
		NEW_LINE = "";
		JSON_INVALID = "JSON file is invalid. Please check all fields for errors. ";
		NO_ELEM_IN_JSON = "There is no object in JSON file with such number ";
		NECKLACE_NOT_FOUND = "There is no necklace with such number ";
		NO_NECKLACES = "Sorry, there are no necklaces. ";
		NO_STONES = "Sorry, there are no stones. ";


		V_MASS = "mass";
		V_PRICE = "price";
		V_TRANSPARRENCY = "transparrency";
		V_CARATES = "carates";
		V_NECKLACE = "Necklace";
	}
	else {
		HELLO = "Привет, добро пожаловать в нашу программу!";
		NACKLACES_ARE_BUILDED = "Ваши ожерелья готовы.";
		STONES_IN_NECKLACE = "Ожерелье включает такие камни: ";
		FINAL_COST = "Окончательная стоимость вашего ожерелья: ";
		FINAL_MASS = "Вес вашего ожерелья в каратах: ";
		STONES_ARE_SORTED = "Камни в ожерелье отсортировано по цене.";
		GIVE_ME_RANGE_OF_TRANSPARECY = "Пожалуйста, предоставьте диапазон прозрачности для камней в вашем ожерелье, которое вы хотите отобразить. От... до...: ";
		END = "Благодарим вас за использование нашей программы. Прощайте :) ";
		WRONG_INPUT = "Извините, вы ввели неправильную команду ";
		CHOOSE_NECKLACE = "Выберите ожерелье, с которым хотите работать (введите число) или введите 0, чтобы закончить программу:";
		NECKLACE_MENU = "\nЧто вы хотите сделать? Команды: \n1 - Показать ожерелье \n2 - Получить цену ожерелья \n3 - Получить массу ожерелья \n4 - Сортировка камней в ожерелье по цене \n5 - Найти камни в ожерелье, которые удовлетворяют некоторому диапазону прозрачности \n6 - выбрать другое ожерелье \n0 - Выйти из программы \n";
		JSON_IS_NOT_OPENED = "Извините, что-то пошло не так, файл JSON не открывается ";
		PARCE_ERROR = "Ошибка, JSON-файл не может быть проанализирован, проверьте его. ";
		NEW_LINE = "";
		JSON_INVALID = "Недопустимый файл Json. Пожалуйста, проверьте все поля для ошибок. ";
		NO_ELEM_IN_JSON = "В JSON-файле нет объекта с таким номером ";
		NECKLACE_NOT_FOUND = "Нет ожерелья с таким номером ";
		NO_NECKLACES = "Простите, ожерелей нет. ";
		NO_STONES = "Простите, камней нет. ";


		V_MASS = "вес";
		V_PRICE = "цена";
		V_TRANSPARRENCY = "прозрачность";
		V_CARATES = "карат";
		V_NECKLACE = "Ожерелье";
	}
	
}


View::~View() {
}


void View::Print(int value) {
	std::cout << value << std::endl;
}

void View::Print(double value) {
	std::cout << value << std::endl;
}

void View::Print(std::string value) {
	std::cout << value << std::endl;
}

void View::PrintVectorOfStones(std::vector<Stone*> vectorOfStones) {
	if (vectorOfStones.size() != 0) {
		std::cout << std::endl;
		for (unsigned int i = 0; i < vectorOfStones.size(); i++)
			std::cout << vectorOfStones[i]->GetName() << ":   " << V_MASS << "  = " << vectorOfStones[i]->GetMass() << " " << V_CARATES << ",   " << V_PRICE << " = $" << vectorOfStones[i]->GetPrice() << ",   " << V_TRANSPARRENCY << " = " << vectorOfStones[i]->GetTransparency() << std::endl;
	}
	else
		std::cout << NO_STONES << std::endl;

}

void View::ShowAllNecklaces(std::vector<Necklace*> vectorOfNecklaces) {
	if (vectorOfNecklaces.size() != 0)
		for (unsigned int i = 0; i < vectorOfNecklaces.size(); i++) {
			std::cout << std::endl << V_NECKLACE << " " << i + 1 << ": ";
			View::PrintVectorOfStones(vectorOfNecklaces[i]->GetStonesIncluded());
		}
	else
		std::cout <<NO_NECKLACES << std::endl;
}