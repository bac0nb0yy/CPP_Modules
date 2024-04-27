#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>

PhoneBook::PhoneBook() : nbContacts(0) {}

PhoneBook::~PhoneBook() {}

int PhoneBook::getNbContacts() { return this->nbContacts; }

void PhoneBook::rotateUpContacts() {
	for (int i = 0; i < 7; i++)
		this->contacts[i] = this->contacts[i + 1];
	this->nbContacts--;
};

void PhoneBook::addContact(std::string* infos) {
	if (this->nbContacts == CAPACITY)
		this->rotateUpContacts();
	Contact& target =
		this->contacts[this->nbContacts < CAPACITY ? this->nbContacts
												   : CAPACITY - 1];
	target.setFirstName(infos[0]);
	target.setLastName(infos[1]);
	target.setNickName(infos[2]);
	target.setPhoneNumber(infos[3]);
	target.setDarkestSecret(infos[4]);
	if (this->nbContacts < CAPACITY)
		this->nbContacts++;
}

std::string centered(std::string const& original, int targetSize) {
	int padding = targetSize - original.size();
	return std::string(padding % 2, ' ') + std::string(padding / 2, ' ') +
		   original + std::string(padding / 2, ' ');
}

std::string goodFormat(std::string str, unsigned long width) {
	if (str.length() > width)
		return str.substr(0, width - 1) + '.';
	return centered(str, 10);
}

void PhoneBook::displayContacts() {
	std::cout << std::setfill(' ') << std::setw(10) << "Index"
			  << "|" << std::setfill(' ') << std::setw(10) << "First Name"
			  << "|" << std::setfill(' ') << std::setw(10) << "Last Name"
			  << "|" << std::setfill(' ') << std::setw(10) << "Nick Name"
			  << std::endl;

	for (int i = 0; i < this->nbContacts; i++) {
		std::cout << std::setfill(' ') << std::setw(10) << i + 1 << '|';
		std::cout << goodFormat(this->contacts[i].getFirstName(), 10) << '|';
		std::cout << goodFormat(this->contacts[i].getLastName(), 10) << '|';
		std::cout << goodFormat(this->contacts[i].getNickName(), 10)
				  << std::endl;
	}
}

void PhoneBook::displayContact(int index) {
	std::cout << "First Name: " << this->contacts[index].getFirstName()
			  << std::endl;
	std::cout << "Last Name: " << this->contacts[index].getLastName()
			  << std::endl;
	std::cout << "Nick Name: " << this->contacts[index].getNickName()
			  << std::endl;
	std::cout << "Phone Number: " << this->contacts[index].getPhoneNumber()
			  << std::endl;
	std::cout << "Darkest Secret: " << this->contacts[index].getDarkestSecret()
			  << std::endl;
}
