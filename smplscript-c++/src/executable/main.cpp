#include <iostream>
#include "../include/entrypoint/entrypoint.h"

/*
Bare main function, will be used as the entry point.
*/

int main() {

	std::cout << "smplscript > ";
	std::string text;
	std::getline(std::cin, text);

	std::vector<std::Token> result = run(text);

	std::cout << "[";
	for (int i = 0; i < result.size(); i++) {
		std::cout << result[i].toString();
		if (i != result.size() - 1)
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;

	return 0;
}