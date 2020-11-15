#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include "Element.h"
#include "Person.h"
#include "Book.h"
#include "Film.h"
#include "Music.h"

/** Funkcja potrzebna do uzyskania indexu vectora danego uzytkownika na podstawie ID.
*/
int return_index_user(int ID, std::vector<Person> person); // zwraca index wektora nie id z txt int to id osoby w pliku txt

/** Funkcja potrzebna do uzyskania indexu vectora danego przedmiotu na podstawie ID.
*/
int return_index_ele(int ID, std::vector<Element*> person); // zwraca index wektora element nie id przedmiotu z txt int to id przedmiotu w pliku txt
																	
/** Funkcja zamieniajaca typ wyliczeniowy na string.
*/
std::string type_to_string(const Type type);

/** Funkcja pobierajaca dane z pliku elementow wprowadzajaca je do programu (vectora).
*@param	name_file Nazwa pliku zawierajace dane elementow.
*@param element Vector elementow do przechowywania danych.
*/
void load_items(const std::string name_file, std::vector<Element*>& element); 

/** Funkcja zapisujace dane przechowywane w vectorze do pliku elementow.
*@param	name_file Nazwa pliku zawierajace dane elementow.
*@param element Vector elementow do przechowywania danych.
*/
void save_items(const std::string name_file,const std::vector<Element*> element) noexcept; 

/** Funkcja pobieraj�ca dane z pliku osob wprowadzajaca je do programu (vectora).
*/
void load_users(const std::string file_name, std::vector<Person>& person); 

/** Funkcja zapisujace dane przechowywane w vectorze do pliku osob.
*/
void save_users(const std::string name_file,const std::vector <Person> person) noexcept;

/** Funkcja dodjaca element lub osobe do bazy elementow lub osob oraz zpisujaca je w oryginalnym pliku.
*/
void add(std::vector<Person>& person, std::vector<Element*>& element,const std::string file_elements,const std::string file_users);

/** Funkcja wyswietlajaca imie mi nazwisko danej osoby na podstawie id.
*/
void show_user(const int ID,const std::vector<Person> person) noexcept;

/** Funkcja wyswietlajaca ID, Imie oraz nazwisko wszystkich osob.
*/
void show_users(const std::vector<Person> person) noexcept; // wyswietla wszsytkie osoby tylko z id imienia i nazwiska

/** Funkcja wyswietlajaca uzytkownikow lub liste elementow w zaleznosci od wyboru. Pozawala na wyswietlenie wszystkich elemntow jak i rowniez wybranych. Mozna wyswietlic plyty, ksiazki oraz filmy jak i konkretne gatunki ksiazek lub posortowane filmy na podstawie ich ocen.
*/
void show(std::vector<Person> person, const std::vector<Element*> element);

/** Funkcja sprawdza imie oraz nazwisko uzytkownika zwracajac jego ID.
*/
int person_id(const std::vector<Person> person);

/** Funkcja umozliwia wypozyczenie uzytkownikowi wybranego przedmiotu.
*/
void borrow_item(std::vector<Person>& person, std::vector<Element*>& element, const std::string file_elements, const std::string file_users);

/** Funkcja ktora jest uzywana w funkcji borrow, odpowiada za wypozyczenie przedmiotu bez koniecznosci pisanie jej dwa razy w funcji borrow.
*/
void borrowed_repeat(std::vector<Element*>& , std::vector<Person>& , int ID_person, int& element_index );

/** Funkcja pozwalajaca na zwracanie przez uzytkownika wypozyczonych przedmiotow.
*/
void return_items(std::vector<Person>&, std::vector<Element*>&, std::string file_elements, std::string file_users);

/** Funkcja pozwalajaca na usuniecie elementow lub uzytkownikow z plikow danych oraz vectorow, bez zmieniania jego ID.
*/
void delete_(std::vector<Person>&, std::vector<Element*>&, const std::string file_elements, const std::string file_users);

/** Funkcja sortujaca filmy na podstawie ocen.
*/
void sort_by_rate(const std::vector<Element*> element) noexcept;


#endif
