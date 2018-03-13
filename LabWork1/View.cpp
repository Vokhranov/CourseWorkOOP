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
		HELLO = "������, ����� ���������� � ���� ���������!";
		NACKLACES_ARE_BUILDED = "���� �������� ������.";
		STONES_IN_NECKLACE = "�������� �������� ����� �����: ";
		FINAL_COST = "������������� ��������� ������ ��������: ";
		FINAL_MASS = "��� ������ �������� � �������: ";
		STONES_ARE_SORTED = "����� � �������� ������������� �� ����.";
		GIVE_ME_RANGE_OF_TRANSPARECY = "����������, ������������ �������� ������������ ��� ������ � ����� ��������, ������� �� ������ ����������. ��... ��...: ";
		END = "���������� ��� �� ������������� ����� ���������. �������� :) ";
		WRONG_INPUT = "��������, �� ����� ������������ ������� ";
		CHOOSE_NECKLACE = "�������� ��������, � ������� ������ �������� (������� �����) ��� ������� 0, ����� ��������� ���������:";
		NECKLACE_MENU = "\n��� �� ������ �������? �������: \n1 - �������� �������� \n2 - �������� ���� �������� \n3 - �������� ����� �������� \n4 - ���������� ������ � �������� �� ���� \n5 - ����� ����� � ��������, ������� ������������� ���������� ��������� ������������ \n6 - ������� ������ �������� \n0 - ����� �� ��������� \n";
		JSON_IS_NOT_OPENED = "��������, ���-�� ����� �� ���, ���� JSON �� ����������� ";
		PARCE_ERROR = "������, JSON-���� �� ����� ���� ���������������, ��������� ���. ";
		NEW_LINE = "";
		JSON_INVALID = "������������ ���� Json. ����������, ��������� ��� ���� ��� ������. ";
		NO_ELEM_IN_JSON = "� JSON-����� ��� ������� � ����� ������� ";
		NECKLACE_NOT_FOUND = "��� �������� � ����� ������� ";
		NO_NECKLACES = "��������, �������� ���. ";
		NO_STONES = "��������, ������ ���. ";


		V_MASS = "���";
		V_PRICE = "����";
		V_TRANSPARRENCY = "������������";
		V_CARATES = "�����";
		V_NECKLACE = "��������";
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