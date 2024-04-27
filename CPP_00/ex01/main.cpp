#include "PhoneBook.hpp"
#include <cstdlib>
#include <iostream>

bool ask(std::string question, std::string& answer) {
	std::cout << LILAC << question << RESET;
	getline(std::cin, answer);
	if (answer.empty())
		return (false);
	return (true);
}

bool fill_infos(std::string infos[5]) {
	if (!ask("First name: ", infos[0]))
		return (false);
	if (!ask("Last name: ", infos[1]))
		return (false);
	if (!ask("Nickname: ", infos[2]))
		return (false);
	if (!ask("Phone number: ", infos[3]))
		return (false);
	if (!ask("Darkest secret: ", infos[4]))
		return (false);
	return (true);
}

static void print_cat() {
	std::cout << "                               --.                "
			  << std::endl;
	std::cout << "                              *@@@+        =##    "
			  << std::endl;
	std::cout << "                             +@@@@@#...  =@@@@*   "
			  << std::endl;
	std::cout << "               .:-===-       @@@@@@@@@@@%@@@@@%   "
			  << std::endl;
	std::cout << "           :+#@@@@@%%*       +@@@@@@@@@@@@@@@@#   "
			  << std::endl;
	std::cout << "         +%@@#=:.       ....=@@@@@@@@@@@@@@@@@-   "
			  << std::endl;
	std::cout << "       =@@%=              .+@@@@@@@@@@@@@@@@@#    "
			  << std::endl;
	std::cout << "      #@@+                ..#@@@@@@@@@@@@@@@@@    "
			  << std::endl;
	std::cout << "     %@@-                    -%@@@@@@@@@@@@@%=    "
			  << std::endl;
	std::cout << "    =@@=                 #%@%+ .*@@@@@@%++-.      "
			  << std::endl;
	std::cout << "    %@@                  =+#@@@@@@@@@@@#          "
			  << std::endl;
	std::cout << "    @@#            .=*##*+*%@@@@@@@@@@@#          "
			  << std::endl;
	std::cout << "    @@%       *#- +@@@@@@@@@@@@@@@@@@@@*          "
			  << std::endl;
	std::cout << "    #@@.      =@@.@@@@@@@@@@@@@@@@@@@@@:          "
			  << std::endl;
	std::cout << "    :@@#       *@*@@@@@@@@@@@@@@@@@@@@+           "
			  << std::endl;
	std::cout << "     =@@%.      *@%@@@@@@@@@@@@@@@@@@+            "
			  << std::endl;
	std::cout << "      -@@@*:     #@@@@@@@@@@@@@@@@@%-             "
			  << std::endl;
	std::cout << "        =%@@@*=-..=@@@@@@@@@@@@@@#-               "
			  << std::endl;
	std::cout << "          :+%@@@@@@@@@@@@@@@@%*=.                 "
			  << std::endl;
	std::cout << "              .-=====--+%@%*                      "
			  << std::endl;
}

static std::string print_welcome_message(std::string command) {
	print_cat();
	std::cout << PINK << "Welcome to the 42 Phonebook" << RESET << std::endl;
	std::cout << V_CYAN << "Type:" << std::endl
			  << "ADD to add a new contact" << std::endl
			  << "SEARCH to search a contact" << std::endl
			  << "EXIT to exit" << std::endl
			  << RESET;
	std::cout << LILAC << "Type your command: " << RESET;
	getline(std::cin, command);
	return (command);
}

int main() {
	PhoneBook Book;
	std::string command;
	int i;
	int num_contacts;

	command = print_welcome_message(command);
	i = 0;
	num_contacts = 0;
	while (!command.empty() && !std::cin.eof() && command != "EXIT") {
		if (command == "ADD") {
			std::string infos[5];
			if (!fill_infos(infos)) {
				std::cout << BOLD_RED << "Invalid input" << std::endl << RESET;
				continue;
			}
			Book.addContact(infos);

		} else if (command == "SEARCH") {
			if (Book.getNbContacts() == 0)
				std::cout << "PhoneBook is empty." << std::endl;
			else {
				Book.displayContacts();
				std::string target;
				if (!ask("Enter contact index.", target))
					break;
				long targetIndex = std::atol(target.c_str());
				if (target.length() > 10 || targetIndex < 1 ||
					targetIndex > Book.getNbContacts())
					std::cout << "Invalid index, index should be between 1 and "
							  << Book.getNbContacts() << " inclusive."
							  << std::endl;
				else
					Book.displayContact(targetIndex - 1);
			}
		} else
			std::cout << BOLD_RED << "Invalid command" << std::endl << RESET;
		if (!ask("Type your command: ", command))
			break;
	}
	std::cout << PURPLE << "Bye! =)" << std::endl << RESET;
	return (0);
}
