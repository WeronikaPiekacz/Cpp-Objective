#include <iostream>
#include <vector>
#include "functions.h"
#include "Element.h"
#include "Person.h"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <Windows.h>


int main()
{
	system("MODE CON COLS=120 LINES=30");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	std::string element_index;
	std::string user_id;

	std::string file_elements = "items.csv";
	std::string file_users = "user.csv";
	std::vector<Element*> element; // kontener na dane
	std::vector <Person> person; // kontener na osoby
	
	load_items(file_elements, element);// otwarcie pliku i zaladowanie danymi z pliku txt
	load_users(file_users, person);
		
	std::string choice = "CHOICE";

	while (choice != "QUIT")
	{

		SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "Enter: ADD, SHOW, DELETE, AVAILABLE, BORROW, RETURN, SEARCH or QUIT\n";
		std::getline(std::cin, choice);
		SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN|FOREGROUND_RED);
		std::for_each(choice.begin(), choice.end(), [](char& c) { c = ::toupper(c); });
		std::transform(choice.begin(), choice.end(),choice.begin(), ::toupper);
		system("cls");

		if (choice == "ADD")
			add(person, element, file_elements, file_users);

		else if (choice == "SHOW")
			show(person, element);

		else if (choice == "AVAILABLE")
			for (auto e : element)
				e->showAvailable();

		else if (choice == "BORROW")
			borrow_item(person, element, file_elements, file_users);

		else if (choice == "DELETE")
			delete_(person, element, file_elements, file_users);

		else if (choice == "RETURN")
			return_items(person, element, file_elements, file_users);

		else if (choice == "SEARCH")
		{
			std::cout << "What do you looking for?  ";
			std::getline(std::cin, choice);
			for (auto e : element)
				e->search(choice);

		}
		else if(choice!="QUIT")
			std::cout << "Try again:"<<std::endl;
		std::cout << std::endl;
	}


	for (int i = person.size(); i > 0; i--)
		person.pop_back();
	person.clear();

	for (auto e : element) {
		delete e;
	}
	element.clear();
	
	return 0;
}
