#include "Person.h"
#include <iostream>
#include <fstream>
#include "functions.h"

using std::cout;
using std::string;
using std::endl;
using std::cin;
using std::getline;



Person::Person(int i,string fName, string sName, std::vector <int> vec)
	: id(i), first_name(fName), last_name(sName), borrowed(vec) {} // constructor

Person::Person(int i, string fName, string sName)
	: id(i), first_name(fName), last_name(sName) {} // constructor


Person::Person(int i) 
{
	id = i;
	cout << "Enter first name: ";
	getline(cin, first_name); 
	cout << "Enter last name: ";
	getline(cin, last_name); 
	cout << "New user's ID: " << i << endl;
}

string Person::saveUser()
{
	//string intiger = std::to_string(index);
	string sVector;
	for (auto e : borrowed)
	{
		sVector += std::to_string(e) + ' ';
	}
	return (std::to_string(id) + "|" + first_name + ' ' + last_name + '|'+ sVector  + "|" );
}

void Person::borrow(int item_id)
{
	borrowed.push_back(item_id);
}

void Person::showUserElement(const std::vector<Element*> el, bool &check)
{
	std::cout << first_name << " " << last_name << std::endl;
	std::cout << "Borrowed items" << std::endl;
	if (borrowed.empty() == false)
	{
		for (int i = 0; i < borrowed.size(); i++)
		{
			el[return_index_ele(borrowed[i], el)]->showItem();
			check = true;
		}
	}
	else
	{
		std::cout << "This user hasn't got any items yet." << std::endl;
		check = false;
	}
}

Person::~Person() {}


