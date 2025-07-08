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
#include <cctype>
#include <algorithm>  // for std::transform
#include "../library/include/entrypoint/entrypoint.h"
#include "../library/include/constants/license.h"
#include "error/illegalCharacterError.h"

/*
 * Bare main function, will be used as the entry point.
 */
int main(int argc, char* argv[])
{
    std::string text, textcpy;

    if (argc == 1)
    {
        std::cout << "\tsmplscript  Copyright (C) 2025  Stephen Steyaert\n"
                  << "\tThis program comes with ABSOLUTELY NO WARRANTY; for details type `show w'.\n"
                  << "\tThis is free software, and you are welcome to redistribute it\n"
                  << "\tunder certain conditions; type `show c' for details.\n";

        while (true)
        {
            std::cout << "smplscript > ";
            std::getline(std::cin, text);
            textcpy = text;
            std::transform(textcpy.begin(), textcpy.end(), textcpy.begin(),
                           [](unsigned char c) { return std::toupper(c); });

            if (textcpy == "SHOW W")
            {
                std::cout << terms.at(0) << "\n\n"
                          << terms.at(15) << "\n\n"
                          << terms.at(16) << "\n\n"
                          << terms.at(17) << "\n";
            }
            else if (textcpy == "SHOW C")
            {
                std::cout << terms.at(0) << "\n\n"
                          << terms.at(4) << "\n\n"
                          << terms.at(5) << "\n";
            }
            else if (textcpy == "EXIT")
            {
                break;
            }
            else
            {
                try
                {
                    std::vector<Token> result = run("<stdin>", text);

                    std::cout << "[";
                    for (size_t i = 0; i < result.size(); ++i)
                    {
                        std::cout << result[i];
                        if (i != result.size() - 1)
                            std::cout << ", ";
                    }
                    std::cout << "]\n";
                }
                catch (const IllegalCharacterError& e)
                {
                    std::cerr << e << std::endl;
                }
            }
        }
    }
    else if (argc == 2)
    {
        std::ifstream input(argv[1]);
        if (!input.is_open())
        {
            std::cerr << "Unable to open " << argv[1] << std::endl;
            return EXIT_FAILURE;
        }

        std::string line;
        while (std::getline(input, line))
        {
            text.append(line).append("\n");
        }

        try
        {
            std::vector<Token> result = run(argv[1], text);

            std::cout << "[";
            for (size_t i = 0; i < result.size(); ++i)
            {
                std::cout << result[i];
                if (i != result.size() - 1)
                    std::cout << ", ";
            }
            std::cout << "]\n";
        }
        catch (const IllegalCharacterError& e)
        {
            std::cerr << e << std::endl;
            return EXIT_FAILURE;
        }
    }
    else
    {
        std::cerr << "Incorrect Usage.\n";
        std::cerr << "Usage: smpl <file.ss>\n";
        std::cerr << "Usage: smpl\n";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
