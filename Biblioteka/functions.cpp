#include <functional>
#include "functions.h"
using std::getline;

int return_index_user(int ide, std::vector<Person> person)
{	
	for (int i = 0; i < person.size(); i++)
		if (person[i].id == ide)
			return i;
		
	return -1;
}

int return_index_ele(int idx, std::vector<Element*> element)
{
	int i = 0;
	for (auto e : element)
	{
		if (e->returnId() == idx)
			return i;
		i++;
	}
	return -1;
}

std::string type_to_string(const Type type)
{
	switch (type)
	{
		case BOOK: return "BOOK";
		case FILM: return "FILM";
		case MUSIC: return "MUSIC";

	}
}
void load_items(const std::string name_file, std::vector<Element*>& vec)
{
	string b, b1, b2, b3, b4, b5;
	float f4;
	int id;
	std::fstream file;
	for (auto e : vec) {
		delete e;
	}
	vec.clear();
	file.open(name_file, std::ios::in);
	if (file.good() == true)
	{
		while (!file.eof())
		{
			if (getline(file, b, '|') && getline(file, b1, '|'))
			{
				

				if (b1 == "BOOK")
					if (getline(file, b2, '|') && getline(file, b3, '|') && getline(file, b4, '|') && getline(file, b5))
						vec.push_back(new Book(atoi(b.c_str()), BOOK, b2, b3, b4, b5));	

				if (b1 == "FILM")
					if (getline(file, b2, '|') && getline(file, b3, '|') && getline(file, b4, '|') && getline(file, b5))
					{
						f4 = atof(b4.c_str());
						vec.push_back(new Film(atoi(b.c_str()), FILM, b2, b3, f4, b5));
					}

				if (b1 == "MUSIC")
					if (getline(file, b2, '|') && getline(file, b3, '|') && getline(file, b4, '|') && getline(file, b5))
						vec.push_back(new Music(atoi(b.c_str()), MUSIC, b2, b3, b4, b5));
			}
				
		}
		file.close();
	}
	else std::cout << "Something wrong with file :c" << std::endl;

}

void save_items(const std::string name_file, const std::vector<Element*> vec ) noexcept
{
	int i = 0;
	std::fstream file;
	file.open(name_file, std::ios::out | std::ios::trunc | std::ios::ate);
	if (file.good() == true)
	{
		for (auto e : vec)
			file << e->saveItem() << '\n';
		file.close();
	}
}

// id|1name lname|borrowed items del ','' // wzor szablonu pliku user.txt
void load_users(const std::string file_name, std::vector<Person>& vec)
{
	string id, fname, lname, num;
	int num_;
	std::fstream file;
	for (int i = vec.size(); i > 0; i--)
		vec.pop_back();
	vec.clear();
	file.open(file_name, std::ios::in);
	if (file.good() == true)
	{
		while(!file.eof())
		{	
;
			if(getline(file, id, '|') && getline(file, fname, ' ') && getline(file, lname, '|')) //wczytuje id imie i nazwisko osoby
			{
				std::vector<int> v; // wektor int czyli takiego typu jak wektor borrowed
				getline(file, num, '|');
				std::istringstream iss(num);
				while(iss>>num) 
				{
					num_ = atoi(num.c_str());
					v.push_back(num_);
				}
				vec.push_back(Person(atoi(id.c_str()), fname, lname, v)); // zapisuje id osoby imie nazwisko i jej wektor wypozyczen
				getline(file, num);
			}
		}
		file.close();
	}
	else std::cout << " Something goes wrong :c";

}

void save_users(const std::string name_file, const std::vector <Person> vec) noexcept
{
	int i = 0;
	std::fstream file;
	file.open(name_file, std::ios::out | std::ios::trunc | std::ios::ate);
	if (file.good() == true)
	{
		for (auto e : vec)
			file << e.saveUser() << '\n';
		file.close();
	}
}

void add(std::vector<Person>& person, std::vector<Element*>& element, const std:: string file_elements, const std::string file_users)
{
	string choice;
	std::cout << "What do you want to add?" << std::endl;
	std::cout << "USER, ITEM" << std::endl;
	getline(std::cin, choice);
	std::transform(choice.begin(), choice.end(),choice.begin(), ::toupper);
	if (choice == "USER")
	{
		person.push_back(Person(person[person.size()-1].id + 1));
		save_users(file_users, person);
	}
	if (choice == "ITEM")
	{
		std::cout << "What type of item do you want to add?" << std::endl;
		std::cout << "BOOK, MUSIC or FILM " << std::endl;
		getline(std::cin, choice);
		std::transform(choice.begin(), choice.end(),choice.begin(), ::toupper);
		if (choice == "BOOK")
			element.push_back(new Book(element[element.size()-1]->returnId() + 1));
		if (choice == "FILM")
			element.push_back(new Film(element[element.size()-1]->returnId() + 1));
		if (choice == "MUSIC")
			element.push_back(new Music(element[element.size()-1]->returnId() + 1));
		save_items(file_elements, element );
	}
}

void show_user(const int v_idx, const std::vector<Person> per) noexcept
{
	std::cout<< per[v_idx].first_name << " " << per[v_idx].last_name << std::endl;
}

void show_users(std::vector<Person> people) noexcept
{
	std::cout << " " << std::left << std::setw(5) << std::setfill(' ') << " ID";
	std::cout << std::left << std::setw(12) << std::setfill(' ') << "FIRST NAME";
	std::cout << std::left << std::setw(30) << std::setfill(' ') << "LAST NAME" << std::endl;

	for(int i = 0; i < people.size(); i++)
	{
		std::cout <<" "<< std::right << std::setw(3) << std::setfill(' ') << people[i].id<<". ";
		std::cout << std::left << std::setw(12) << std::setfill(' ') << people[i].first_name;
		std::cout << std::left << std::setw(30) << std::setfill(' ') << people[i].last_name << std::endl;
	}
}

void show(std::vector<Person> person, const std::vector<Element*> element)
{
	string choice;
	bool check;
	int temp;
	std::cout << "What do you want see?" << std::endl;
	std::cout << "USER or ITEM" << std::endl;
	getline(std::cin, choice);
	std::transform(choice.begin(), choice.end(),choice.begin(), ::toupper);
	if (choice == "USER")
	{
		show_users(person);
		std::cout << "Do you want to show user's borrows?" << std::endl;
		std::cout << "YES or NO" << std::endl;
		getline(std::cin, choice);
		std::transform(choice.begin(), choice.end(),choice.begin(), ::toupper);
		if (choice == "YES")
		{
			std::cout << "Enter user ID: ";
			getline(std::cin, choice);
			temp = return_index_user(atoi(choice.c_str()), person);
			while (temp == -1)
			{
				std::cout << "Wrong ID. Try again: ";
				getline(std::cin, choice);
				temp = return_index_user(atoi(choice.c_str()), person);
			}
			person[return_index_user(atoi(choice.c_str()), person)].showUserElement(element,check);
		}
	}
	if (choice == "ITEM")
	{
		std::cout << "You want to see all resources or specific type of items? " << std::endl;
		std:: cout << "ALL or SPEC:  ";
		getline(std::cin, choice);
		std::transform(choice.begin(), choice.end(),choice.begin(), ::toupper);
		if (choice == "ALL")
			for (auto e : element)
				e->showItem();	
		if (choice == "SPEC")
		{	
			while (choice != "BOOK" && choice != "MUSIC" && choice != "FILM")
			{
				std::cout << "Which type?" << std::endl;
				std::cout << "BOOK, MUSIC or FILM: ";
				getline(std::cin, choice);
				std::transform(choice.begin(), choice.end(),choice.begin(), ::toupper);
				if (choice == "BOOK")
				{
					std::cout << "Do you want to show all books or some specific genre?" << std::endl;
					std::cout << "ALL or SPEC:  " ;
					getline(std::cin, choice);
					std::transform(choice.begin(), choice.end(),choice.begin(), ::toupper);
					if(choice == "ALL")
					{
						for (auto e :element)
							e->byType(BOOK);
						break;
					}
					if(choice == "SPEC")
					{
						std::cout << "Enter genre:  ";
						getline(std::cin, choice);
						std::transform(choice.begin(), choice.end(),choice.begin(), ::toupper);
						for (auto e :element)
							e->byGenre(choice);
						break;
					}
				}
				if (choice == "FILM")
				{
					for (auto e :element)
						e->byType(FILM);
					std::cout << "\nDo you want to sort films by rating ???" << std::endl;
					std::cout << "YES or NO: ";
					getline(std::cin, choice);
					std::transform(choice.begin(), choice.end(),choice.begin(), ::toupper);
					if (choice == "YES")
					{
						sort_by_rate(element);
						break;
					}
					if (choice == "NO")
						break;
				}
					
				if (choice == "MUSIC")
				{
					for (auto e :element)
						e->byType(MUSIC);
					std::cout << std::endl;
				}

			}	
		}
	}
}

int person_id(const std::vector<Person>person)
{
	string choice, firstName, lastName;
	int ID, temp=-1;//temp do sprawdzenia czy nie ma dwoch uzytkownikow o tej samej nazwie

	std::cout << "Enter your first name: ";
	getline(std::cin, firstName);
	std::for_each(firstName.begin(), firstName.end(), [](char& c) { c = ::toupper(c); });
	std::cout << "Enter your last name: ";
	getline(std::cin, lastName);
	std::for_each(lastName.begin(), lastName.end(), [](char& c) { c = ::toupper(c); });
	for (int i = 0; i < person.size(); i++)
	{
		string f = person[i].first_name, l = person[i].last_name;
		std::for_each(f.begin(), f.end(), [](char& c) { c = ::toupper(c); });
		std::for_each(l.begin(), l.end(), [](char& c) { c = ::toupper(c); });
		if (f == firstName && l == lastName)
		{
			ID = person[i].id;
			++temp;
		}
	}
	if (temp == 0)
		return ID;
	else if (temp >0 )
		return 0;
	else
		return -1;
		
}

void borrow_item(std::vector<Person>& person, std::vector<Element*>& element, const std::string file_elements, const std::string file_users)
{
	int ID_item, element_index, ID_person;
	std::string choice;
	std::cout << "Have you library card?\nYES or NO: ";
	getline(std::cin, choice);
	std::transform(choice.begin(), choice.end(),choice.begin(), ::toupper);
	if (choice == "YES")
	{
		//moznaby zaimplementowac funkcje ktora by wyporzyczala na bazie imienia i nazwiska
		std::cout << "What is your ID?  ";
		getline(std::cin, choice);
		ID_person = std::atoi(choice.c_str());
		while (return_index_user(ID_person,person)==-1)
		{
			std::cout << "Wrong ID. What is your ID?  ";
			getline(std::cin, choice);
			ID_person = std::atoi(choice.c_str());
		}
		borrowed_repeat(element, person, ID_person, element_index);
		element[element_index]->changeAvailable();
	}
	if (choice == "NO")
	{
		ID_person = person[person.size()-1].id + 1;
		person.push_back(Person(person[person.size()-1].id + 1));
		borrowed_repeat(element, person, ID_person, element_index);
		element[element_index]->changeAvailable();
	}
	save_users(file_users,person);
	save_items(file_elements, element);
	getline(std::cin, choice);
}

void borrowed_repeat(std::vector<Element*>& element, std::vector<Person>& person, int ID_person, int &element_index)
{
	int ID_item, person_index;
	for (auto e : element)
		e->showAvailable();	
	person_index = return_index_user(ID_person, person);
	show_user(person_index, person);	
	std::cout << "What do you want borrow (ID)?  ";
	std::cin >> ID_item;
	element_index = return_index_ele(ID_item, element);
	while (element_index==-1 || element[element_index]->getAvailable() != "Available")
	{
		std::cout << "Wrong ID. Try again  ";
		std::cin >> ID_item;
		element_index = return_index_ele(ID_item, element);
	}
	person[person_index].borrow(ID_item);
}

void return_items(std::vector<Person>& person, std::vector<Element*>& element, const std::string file_elements, const std::string file_users)
{
	std::string choice="";
	string id_item_s; // id przedmiotu jako string
	int element_index;	// id przedmiotu jako int
	bool incorrect = true; // uzywany do komunikatow
	bool check;
	//bool correct_name = false; // uzywany do sprawdzania logowania
	int id_person = person_id(person);

	if (id_person==-1)
		std::cout << "We dont have user with this name.\n";
	else
	{
		if (!id_person)
		{
			std::cout << "We have two users with this name. Enter your ID: ";
			getline(std::cin, choice);
			id_person = atoi(choice.c_str());
		}	
		int person_index = return_index_user(id_person, person);
		while (person_index == -1)
		{
			std::cout << "Wrong ID. Try again: ";
			getline(std::cin, choice);
			id_person = atoi(choice.c_str());
			person_index = return_index_user(id_person, person);
		}
		person[person_index].showUserElement(element,check);


		while (choice != "EXIT" && check)
		{		
			std::cout << "How many items do you want to give back?" << std::endl;
			std::cout << "ALL or SOME of them, EXIT:  ";
			getline(std::cin, choice);
			std::transform(choice.begin(), choice.end(),choice.begin(), ::toupper);
			if (choice == "ALL")
			{
				for (int i = 0; i <= person[person_index].borrowed.size(); i++) // zeby pop_back dzialala musi byc <= 
				{
					element[return_index_ele(person[person_index].borrowed[i], element)]->changeAvailable(); // zmienia dostepnosc elementu 
					person[person_index].borrowed.pop_back();	// czysci caly wektor borrowed
				}
				std::cout << "You give back all items!" << std::endl;
				std::cout << "Thank You " << std::endl;
				save_users(file_users, person);
				save_items(file_elements, element);
				break;
			}
			if (choice == "SOME" || choice == "ANOTHER ONE")
			{
				std::cout << "Which one?  ";
				getline(std::cin, id_item_s);
				element_index = return_index_ele(atoi(id_item_s.c_str()), element);
				for (int i = 0; i < person[person_index].borrowed.size(); i++)
				{
					if (person[person_index].borrowed[i] == std::atoi(id_item_s.c_str()))
					{
						incorrect = false;
						person[person_index].borrowed.erase(person[person_index].borrowed.begin() + i); // usuwa wybrany element
						element[element_index]->changeAvailable(); // zmienia dostepnosc elementu
						std::cout << "You give back item\n ";
						element[element_index]->showItem();
						std::cout << "Thank You " << std::endl;
						break;
					}
				}
				if (incorrect == true)
					std::cout << "You haven't got item with ID like thtat!" << std::endl;
				else
				{
					save_users(file_users, person);
					save_items(file_elements, element);
					break;
				}
			}
		}
	}
}

void delete_(std::vector<Person>& person, std::vector<Element*>& element, const std::string file_elements, const std::string file_users)
{
	std::string choice, index;
	std::cout << "What do you want delete?" << std::endl;
	std::cout << "USER or ITEM:  ";
	getline(std::cin, choice);
	std::transform(choice.begin(), choice.end(),choice.begin(), ::toupper);
	if (choice == "ITEM")
	{
		std::cout << "Chose item to delete:  ";
		getline(std::cin, index);
		int id = atoi(index.c_str());
		int i = return_index_ele(id, element);
		if (i==-1)
			std::cout << "We dont have that item." << std::endl;
		else if(element[i]->getAvailable()=="No available")
			std::cout << "You can't delete borrowed item... !" << std::endl;
		else
		{
			std::cout << "You delete item: \n";
			element[i]->showItem();
			element.erase(element.begin() + i);
			save_items(file_elements, element);
			load_items(file_elements, element);
		}
	}
	if (choice == "USER")
	{
		std::cout << "Chose user to delete:  ";
		getline(std::cin, index);
		int i = return_index_user(atoi(index.c_str()), person);
		if (i==-1)
			std::cout << "We dont have this user."<<std::endl;
		else
		{
			std::cout << "You delete user: ";
			show_user(i, person);
			for (int j = 0; j < person[i].borrowed.size(); j++)
			{
				element[person[i].borrowed[j] - 1]->changeAvailable();
			}
			person.erase(person.begin() + (i));
			save_users(file_users, person);
			save_items(file_elements, element);
		}
	}
}

void sort_by_rate(const std::vector<Element*> element) noexcept
{
	std::vector <float> f; // wektor ocen
	int i = 0;
	for (auto e : element)
		if (e->getType()==FILM) // jezeli typ to film
			f.push_back(e->getRaiting());  // doaj jego ocene do vektora
	sort(f.begin(), f.end()); // sortowanie rosnąco 
	f.erase(std::unique(f.begin(), f.end()), f.end());//usuniecie powtorek
	for (i = f.size()-1; i >= 0; i--) // wyswietlanie od tylu
		for(auto e : element)
			e->printByRate(f[i]); // wyswietlanie wedlug oceny od najwiekszej do najmniejszej
}


