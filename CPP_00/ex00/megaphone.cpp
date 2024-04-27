#include <iostream>

int main(int ac, char** av) {
	if (ac > 1) {
		for (int i = 1; i < ac; ++i) {
			if (i > 1)
				std::cout << " ";
			std::string str = av[i];
			for (std::string::iterator it = str.begin(); it != str.end(); ++it)
				std::cout << static_cast<char>(std::toupper(*it));
		}
		std::cout << std::endl;
	} else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}