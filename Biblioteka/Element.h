// klasa abstrakcyjna
#ifndef ELEMENT_H
#define ELEMENT_H 
#include <string>
using std::string;

enum Type { BOOK, FILM, MUSIC };

/**
 * Klasa Element jest klasa bazowa abstrakcyjna wszystkich przedmiotow mozliwych do wypozyczenia.
 * @param index Jest to numer ID elementu.
 * @param info Zawiera informacje o tym czy dany element jest dostepny do wypozyczenia. 
 */
class Element
{
protected: 
	int ID;
	string info;

public:

	/** Konstruktor potrzebny do tworzenia obiektow klas pochonych.
	*@param	i ID elementu.
	*@param in Informacja o dostepnosci.
	*/
	Element(int i, string info) : ID(i), info(info) {}

	/** Metoda virtualna wyswietlajca poszczegolne elementy.
	*/
	virtual void showItem() = 0;

	/** sdUzywana do zapisywania danych w pliku elementow.
	*/
	virtual string saveItem() = 0;

	/** Metoda virtualna wyswietlajca element jesli jest on dostepny do wypozyczenia.
	*/
	virtual void showAvailable() = 0;

	/** Metoda virtualna wyswietlajca poszczegolne elementy jesli sa one zgodne z podanym typem.
	*/
	virtual void byType(Type){}

	/** Metoda virtualna potrzebna do wyswietlania ksiazek na podstawie gatunkow.
	*/
	virtual void byGenre(string){}

	/** Metoda virtualna przerzukujaca elementy pod katem szukanej frazy.
	*/
	virtual void search(string){}

	/** Metoda virtualna zwracajaca typ elemntu.
	*/
	virtual Type getType()=0;

	/** Metoda virtualna potrzebna do wyswietlania posortowanych filmow na podstawie ich ocen.
	*/
	virtual float getRaiting() {
		return 0;
	} // przeciazone w Film

	/** Metoda virtualna potrzebna do uzyskawinia informacji o dostepnosci elementu.
	*/
	virtual string getAvailable() =0;

	/** Metoda virtualna potrzebna do wyswietlania ksiazek na podstawie gatunkow.
	*/
	virtual void printByRate(float){} // przeciazone w Film

	/** Metoda potrzebna do uzyskania dostepu do ID elementu.
	*/
	int returnId() {
		return ID;
	} // zwraca id

	/** Metoda zmieniajaca dostepnosc elementow.
	*/
	void changeAvailable()
	{
		if (info == "Available")
			info = "No available";
		else
			info = "Available";
	}
	
	
};
#endif