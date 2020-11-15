#pragma once
#include "Element.h"
#include <string>
using std::string;

class Music : public Element
{
	Type type;
	string title;
	string singer;
	string producent;
	//string info;

public:
	// konstruktor laduj�cy
	Music(int, Type, string, string, string, string);
	Music(int index);// konstruktor zapisuj�cy
	~Music();

	virtual void showItem();
	virtual string saveItem();
	virtual void showAvailable();
	virtual void search(string);
	virtual void byType(Type);
	virtual Type getType();
	virtual string getAvailable();
};
