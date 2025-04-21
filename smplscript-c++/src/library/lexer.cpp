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

#include "include/error/illegalCharError.h"
#include "include/lexer/lexer.h"
#include "include/constants/constants.h"
#include <string>
#include <vector>

/*
* Defining all of the Lexer objec's functions
*/

// Default Constructor
// Initializes all fields to null
std::Lexer::Lexer() {
	mText = nullptr;
	mCurrentChar = '\0';
	mCurrentPos = nullptr;
}
// Constructor
// Initializes the text field to the input text, sents the current positiion to -1, advances 
// to the next character in the text
std::Lexer::Lexer(std::string fileName, std::string text) {
	mFileName = fileName;
	mText = text;
	mCurrentPos = new Position(-1, 0, -1, fileName, text);
	mCurrentChar = '\0';
	advance();
}
// Advance function
// Increments the current position, checks if the current position is less than the length of the text,
// if it is, sets the current character to the character at the current position in the text
void std::Lexer::advance() {
	mCurrentPos->advance(mCurrentChar);
	if (mCurrentPos->getIndex() < mText.length()) {
		mCurrentChar = mText[mCurrentPos->getIndex()];
	}
	else {
		mCurrentChar = '\0';
	}
}
// makeNumber function
// Creates a number from the current character in the text, advances to the next character, repeats until
// the current character is not a digit or a period, then returns the Token with the corresponding type and value
std::Token std::Lexer::makeNumber() {
	std::string numberString = "";
	int dotCount = 0;
	while (mCurrentChar != '\0' && (constants::DIGITS.find(mCurrentChar) != std::string::npos || mCurrentChar == '.')) {
		if (mCurrentChar == '.') {
			if (dotCount == 1)
				break;
			dotCount++;
			numberString += '.';
		}
		else
			numberString += mCurrentChar;
		advance();
	}
	if (dotCount == 1) {
		return Token(constants::TT_FLOAT, std::stof(numberString));
	}
	return Token(constants::TT_INT, std::stoi(numberString));
}

// generateTokens function
// Generates tokens from the text, returns a vector of tokens or an error if an illegal character is found
std::vector<std::Token> std::Lexer::generateTokens() {
	std::vector<std::Token> tokens;
	while (mCurrentChar != '\0') {
		if (mCurrentChar == ' ' || mCurrentChar == '\t') {
			advance();
		}
		else if (constants::DIGITS.find(mCurrentChar) != std::string::npos) {
			tokens.push_back(makeNumber());
		}
		else {
			switch (mCurrentChar) {
			case '+':
				tokens.push_back(Token(constants::TT_PLUS));
				advance();
				break;
			case '-':
				tokens.push_back(Token(constants::TT_MINUS));
				advance();
				break;
			case '*':
				tokens.push_back(Token(constants::TT_MUL));
				advance();
				break;
			case '/':
				tokens.push_back(Token(constants::TT_DIV));
				advance();
				break;
			case '(':
				tokens.push_back(Token(constants::TT_LPAREN));
				advance();
				break;
			case ')':
				tokens.push_back(Token(constants::TT_RPAREN));
				advance();
				break;
			default:
				std::Position* posStart = mCurrentPos->copy();
				char currentChar = mCurrentChar;
				advance();
				tokens.clear();
				throw IllegalCharError(posStart, mCurrentPos, "'" + std::string(1, currentChar) + "'");
			}
		}

	}
	return tokens;
}