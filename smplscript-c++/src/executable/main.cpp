/*

    smplscript, A Simple Scripting Language for Beginners
    Copyright (C) 2025  Stephen Steyaert

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

*/

#include <fstream>
#include <iostream>
#include <string>
#include "../library/include/entrypoint/entrypoint.h"
#include "../library/include/constants/license.h"

/*
Bare main function, will be used as the entry point.
*/

int main(int argc, char *argv[]) {

	std::string text;

	if (argc == 1){

		std::cout << "\tsmplscript  Copyright (C) 2025  Stephen Steyaert" << std::endl 
		<< "\tThis program comes with ABSOLUTELY NO WARRANTY; for details type `show w'." << std::endl
		<< "\tThis is free software, and you are welcome to redistribute it" << std::endl 
		<< "\tunder certain conditions; type `show c' for details." << std::endl;

		std::cout << "smplscript > ";
		
		std::getline(std::cin, text);

		if (text.compare("show w") == 0){
			std::cout << terms.at(0) << std::endl;
			std::cout << std::endl << terms.at(15) << std::endl;
			std::cout << std::endl << terms.at(16) << std::endl;
			std::cout << std::endl << terms.at(17) << std::endl;
		}
		else if (text.compare("show c") == 0){
			std::cout << terms.at(0) << std::endl;
			std::cout << std::endl << terms.at(4) << std::endl;
			std::cout << std::endl << terms.at(5) << std::endl;
		}
		else {

			std::vector<std::Token> result = run( "<stdin>", text);

			std::cout << "[";
			for (int i = 0; i < result.size(); i++) {
				std::cout << result[i].toString();
				if (i != result.size() - 1)
					std::cout << ", ";
			}
			std::cout << "]" << std::endl;
		}
	}
	else if (argc == 2){
		{
			std::ifstream input(argv[1]);
			if (!input.is_open()){
				std::cerr << "Unable to open " << argv[1] << std::endl;
				return EXIT_FAILURE;
			}
			std::string line;
			while (getline(input, line)){
				text.append(line).append("\n");
			}
		}

		
		std::vector<std::Token> result = run(argv[1], text);

			std::cout << "[";
			for (int i = 0; i < result.size(); i++) {
				std::cout << result[i].toString();
				if (i != result.size() - 1)
					std::cout << ", ";
			}
			std::cout << "]" << std::endl;

	}
	else{
		std::cerr << "Incorrect Usage." << std::endl;
		std::cerr << "Usage: smpl <file.ss>" << std::endl;
		std::cerr << "Usage: smpl" << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}