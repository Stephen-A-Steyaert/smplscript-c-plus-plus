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

#pragma once
#ifndef TOKEN_H
#define TOKEN_H

#include <optional>
#include <string>


namespace std{

/*
* Token object, will be used in the Lexer to represent pieces of the code, and will
* be used in the Parser to represent the abrstract syntax tree.
*/
	class Token
	{
	// Public methods and fields
	public:
		struct valueReturn {
			std::string stringValue;
			int intValue;
		};
		Token();
		Token(std::string tokenType);
		Token(std::string tokenType, std::string stringValue);
		Token(std::string tokentype, int intValue);
		valueReturn getValue();
		std::string getTokenType();
		std::string toString();

	// Private Fields
	private:
		std::optional<std::string> mStringValue;
		std::optional<long long int> mIntValue;
		std::string mTokenType;
	};

}

#endif