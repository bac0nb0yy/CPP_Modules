#pragma once

#include <string>

class Contact {
public:
	Contact();
	~Contact();

	std::string getFirstName() const;
	void setFirstName(std::string firstName);

	std::string getLastName() const;
	void setLastName(std::string lastName);

	std::string getNickName() const;
	void setNickName(std::string nickname);

	std::string getPhoneNumber() const;
	void setPhoneNumber(std::string phoneNumber);

	std::string getDarkestSecret() const;
	void setDarkestSecret(std::string darkestSecret);

private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickName;
	std::string _phoneNumber;
	std::string _darkestSecret;
};