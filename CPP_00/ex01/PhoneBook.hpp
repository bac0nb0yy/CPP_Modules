#pragma once

#define CAPACITY 8

#include "Contact.hpp"
#include <string>

#define RESET "\e[0m"
#define PINK "\e[0;38;5;199m"
#define LILAC "\e[0;38;5;13m"
#define PURPLE "\e[0;38;5;93m"
#define BOLD_RED "\e[1;31m"
#define BLUE "\e[0;34m"
#define V_CYAN "\e[0;38;5;44m"

class PhoneBook {
public:
	PhoneBook();
	~PhoneBook();
	void rotateUpContacts();
	void displayContact(int index);
	void displayContacts();
	void addContact(std::string* infos);
	int getNbContacts();

private:
	int nbContacts;
	Contact contacts[CAPACITY];
};