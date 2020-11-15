#include "Music.h"
#include "functions.h"
#include <iostream>
#include <fstream>
#include <sstream>

using std::cout;
using std::string;
using std::endl;
using std::cin;
using std::getline;



Music::Music(int i, Type a, string b, string c, string e, string d)
	: Element(i, d), type(a), title(b), singer(c), producent(e) {} // constructor


Music::Music(int i) : Element(i, "Available")// konstruktor zapisuj�cy do pliku 
{
	type = Type::MUSIC;
	cout << "Enter CD title: ";
	getline(cin, title);
	cout << "Enter singer: ";
	getline(cin, singer);
	cout << "Enter producent: ";
	getline(cin, producent);
}

Music::~Music() {}


void Music::showItem()
{
	std::cout << " " << std::right << std::setw(3) << std::setfill(' ') << ID << ". ";
	std::cout << std::left << std::setw(7) << std::setfill(' ') << type_to_string(type);
	std::cout << std::left << std::setw(35) << std::setfill(' ') << title;
	std::cout << std::left << std::setw(30) << std::setfill(' ') << singer;
	std::cout << std::left << std::setw(22) << std::setfill(' ') << producent;
	std::cout << std::left << std::setw(12) << std::setfill(' ') << info << std::endl;
}


string Music::saveItem()
{
	return (std::to_string(ID) + '|' + type_to_string(type) + '|' + title + '|' + singer + '|' + producent +'|' + info);
}


void Music::showAvailable()
{
	if (info == "Available")
		showItem();
}

void Music::search(string word)
{
	std::for_each(word.begin(), word.end(), [](char& c) { c = ::toupper(c); });
	string t = title, s = singer, p = producent;
	std::for_each(t.begin(), t.end(), [](char& c) { c = ::toupper(c); });
	std::for_each(s.begin(), s.end(), [](char& c) { c = ::toupper(c); });
	std::for_each(p.begin(), p.end(), [](char& c) { c = ::toupper(c); });
	size_t find_title = title.find(word);
	size_t find_singer = singer.find(word);
	size_t find_producent = producent.find(word);
	if (find_title != std::string::npos || find_singer != std::string::npos || find_producent != std::string::npos)
		showItem();
}

void Music::byType(Type word)
{
	if (word == Type::MUSIC)
		showItem();
}

Type Music::getType()
{
	return type;
}
string Music::getAvailable()
{
	return info;
}
