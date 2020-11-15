#pragma once
#include <string>
#include "Element.h"
using std::string;

class Film : public Element
{

	//int index;
	Type type;
	string title;
	string director;
	//string info;
	float rating; // from 0-5 include 0.5

public:
	// konstruktor laduj�cy
	Film(int, Type, string, string, float, string);
	Film(int index);// konstruktor zapisuj�cy
	~Film();

	virtual void showItem();
	virtual string saveItem();
	virtual void showAvailable();
	virtual void search(string);
	virtual void byType(Type);
	virtual float getRaiting(); // zwraca ocene
	virtual Type getType(); // zwraca typ przedmiotu
	virtual void printByRate(float); // wyswietla filmy wedlug oceny
	virtual string getAvailable();
};

