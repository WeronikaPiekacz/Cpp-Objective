#include "Book.h"
#include"functions.h"
#include <iostream>
#include <fstream>
#include <sstream>

using std::cout;
using std::string;
using std::endl;
using std::cin;
using std::getline;



Book::Book(int i, Type a, string b, string c, string g, string d)
	 :Element(i, d), type(a), title(b), author(c), genre(g) {} // constructor


Book::Book(int i): Element (i, "Available")// konstruktor zapisujący do pliku 
{	
	type = Type::BOOK;
	cout << "Enter book title: ";
	getline(cin, title);
	cout << "Enter author: ";
	getline(cin, author);
	cout << "Enter genre: ";
	getline(cin, genre);
}


Book::~Book(){}


void Book::showItem()
{
	std::cout << " " << std::right << std::setw(3) << std::setfill(' ') << ID  << ". ";
	std::cout << std::left << std::setw(7) << std::setfill(' ') << type_to_string(type);
	std::cout << std::left << std::setw(35) << std::setfill(' ') << title;
	std::cout << std::left << std::setw(30) << std::setfill(' ') << author;
	std::cout << std::left << std::setw(22) << std::setfill(' ') << genre;
	std::cout << std::left << std::setw(12) << std::setfill(' ') << info << std::endl;
	
}

// ad_1
string Book::saveItem()
{
	//string intiger = std::to_string(index);
	return (std::to_string(ID) + "|" + type_to_string(type) + '|' + title + '|' + author + "|" + genre + '|'+ info);
}


void Book::showAvailable()
{
	if (info == "Available")
		showItem();
}

void Book::search(string word)
{
	std::for_each(word.begin(), word.end(), [](char& c) { c = ::toupper(c); });
	string t = title, a = author, g=genre;

	std::for_each(t.begin(), t.end(), [](char& c) { c = ::toupper(c); });
	std::for_each(a.begin(), a.end(), [](char& c) { c = ::toupper(c); });
	std::for_each(g.begin(), g.end(), [](char& c) { c = ::toupper(c); });
	size_t find_title = t.find(word);
	size_t find_author = a.find(word);
	size_t find_genre = g.find(word);
	if (find_title != std::string::npos || find_author != std::string::npos || find_genre != std::string::npos)
		showItem();
}

void Book::byType(Type type)
{
	if (type == Type::BOOK)
		showItem();
}

void Book::byGenre(string word)
{
	size_t find_genre = genre.find(word);
	if (find_genre != std::string::npos)
		showItem();
}

Type Book::getType()
{
	return type;
}

string Book::getAvailable()
{
	return info;
}
