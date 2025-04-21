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

#include "include/token/token.h"
#include <string>
#include <optional>
// #include 

/*
* Defining all of the Token object's functions
*/
// Default constructor
// Initializes all fields to null
std::Token::Token() {
	mTokenType = nullptr;
}
// Constructor
// Initializes the token type field to the input token type
std::Token::Token(std::string tokenType) {
	mTokenType = tokenType;
}
// Constructor
// Initializes the token type field to the input token type,
// and the string value field to the input string value
std::Token::Token(std::string tokenType, std::string stringValue) {
	mTokenType = tokenType;
	mStringValue = stringValue;
}
// Constructor
// Initializes the token type field to the input token type,
// and the int value field to the input int value
std::Token::Token(std::string tokenType, int intValue) {
	mTokenType = tokenType;
	mIntValue = intValue;
}
// getValue function
// Returns a valueReturn struct containing the string and int values
std::Token::valueReturn std::Token::getValue() {
	valueReturn returnValue;
	returnValue.stringValue = mStringValue.value();
	returnValue.intValue = mIntValue.value();
	return returnValue;
}
// getTokenType function
// Returns the token type
std::string std::Token::getTokenType() {
	return mTokenType;
}
// toString function to Print out Token
std::string std::Token::toString() {
	std::string out = mTokenType;
	if (mStringValue.has_value()) {
		out += ":" + mStringValue.value();
	}
	else if (mIntValue.has_value()) {
		out += ":" + std::to_string(mIntValue.value());
	}
	return out;
}