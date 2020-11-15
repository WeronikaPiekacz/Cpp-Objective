#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <vector>
#include "Element.h"

using std::string;

class Person 
{
public:
	int id;
	string first_name;
	string last_name;
	std::vector <int> borrowed;

	Person(int ,string, string, std::vector<int>);
	Person(int, string, string);
	Person(int id);//do wprowadzenia osoby

	string saveUser();
	void borrow(int);
	void showUserElement(const std::vector<Element*> element, bool &check);
	~Person();
};


#endif#pragma once
