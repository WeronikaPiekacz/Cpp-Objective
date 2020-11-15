#include "Film.h"
#include "functions.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using std::cout;
using std::string;
using std::endl;
using std::cin;
using std::getline;



Film::Film(int i, Type a, string b, string c, float r, string d)
	: Element(i,d), type(a), title(b), director(c), rating(r) {} // constructor


Film::Film(int i) : Element(i, "Available") // konstruktor zapisuj�cy do pliku 
{
	string rate;
	type = FILM;
	cout << "Enter film title: ";
	getline(cin, title);
	cout << "Enter film director: ";
	getline(cin, director);
	cout << "Enter film rate (0-5): ";
	getline(cin, rate);
	rating = atof(rate.c_str());
}


Film::~Film() {}


void Film::showItem()
{
	std::cout << " " << std::right << std::setw(3) << std::setfill(' ') << ID << ". ";
	std::cout << std::left << std::setw(7) << std::setfill(' ') << type_to_string(type);
	std::cout << std::left << std::setw(35) << std::setfill(' ') << title;
	std::cout << std::left << std::setw(30) << std::setfill(' ') << director;
	std::cout << std::left << std::setw(22) << std::setfill(' ') << rating;
	std::cout << std::left << std::setw(12) << std::setfill(' ') << info << std::endl;

	//cout << index << ", " << type_to_string(type) << std::setw(7 - type_to_string(type).length()) << " " << title << ", " << director << ", "  << rating << ", " << info << endl;
}

// ad_1
string Film::saveItem()
{
	return (std::to_string(ID) + '|' + type_to_string(type) + '|' + title + '|' + director + '|' + std::to_string(rating) + '|' + info);
}


void Film::showAvailable()
{
	if (info == "Available")
		showItem();
}

void Film::search(string word)
{
	//std::transform(word.begin(), word.end(), word.begin(), ::toupper);
	std::for_each(word.begin(), word.end(), [](char& c) { c = ::toupper(c); });
	string t = title, d = director;
	std::for_each(t.begin(), t.end(), [](char& c) { c = ::toupper(c); });
	std::for_each(d.begin(), d.end(), [](char& c) { c = ::toupper(c); });
	size_t find_title = t.find(word);
	size_t find_director = d.find(word);
	if (find_title != std::string::npos || find_director != std::string::npos)
		showItem();
}

void Film::byType(Type type)
{
	if (type == FILM)
		showItem();
}

float Film::getRaiting()
{
	return rating;
}

Type Film::getType()
{
	return type;
}

void Film::printByRate(float r)
{
	if (rating == r)
		showItem();

}

string Film::getAvailable()
{
	return info;
}
