#ifndef BOOK_H
#define BOOK_H 
#include <string>
#include "Element.h"
using std:: string;

class Book : public Element
{	
	//int index;
	Type type;
	string title;
	string author;
	//string info;
	string genre;

public:

	// konstruktor ladujący
	Book(int, Type, string, string, string, string);
	Book(int index);// konstruktor zapisujący
	~Book();

	virtual string saveItem();	
	virtual void showAvailable();
	virtual void showItem();
	virtual void search(string);
	virtual void byType(Type);
	virtual void byGenre(string);
	virtual Type getType();
	virtual string getAvailable();
};
#endif