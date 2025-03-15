#include "illegalcharerror.h"
#include "lexer.h"
#include "constants.h"
#include <string>
#include <vector>

/*
* Defining all of the Lexer objec's functions
*/

// Default Constructor
// Initializes all fields to null
Lexer::Lexer() {
	mText = nullptr;
	mCurrentChar = NULL;
	mCurrentPos = NULL;
}
// Constructor
// Initializes the text field to the input text, sents the current positiion to -1, advances 
// to the next character in the text
Lexer::Lexer(std::string text) {
	mText = text;
	mCurrentPos = -1;
	mCurrentChar = NULL;
	advance();
}
// Advance function
// Increments the current position, checks if the current position is less than the length of the text,
// if it is, sets the current character to the character at the current position in the text
void Lexer::advance() {
	mCurrentPos++;
	if (mCurrentPos < mText.length()) {
		mCurrentChar = mText[mCurrentPos];
	}
	else {
		mCurrentChar = NULL;
	}
}
// makeNumber function
// Creates a number from the current character in the text, advances to the next character, repeats until
// the current character is not a digit or a period, then returns the Token with the corresponding type and value
Token Lexer::makeNumber() {
	std::string numberString = "";
	int dotCount = 0;
	while (mCurrentChar != NULL && (constants::DIGITS.find(mCurrentChar) != std::string::npos || mCurrentChar == '.')) {
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
Lexer::valueReturn Lexer::generateTokens() {
	std::vector<Token> tokens;
	while (mCurrentChar != NULL) {
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
				char currentChar = mCurrentChar;
				advance();
				tokens.clear();
				return { IllegalCharError("'" + std::string(1, currentChar) + "'"), true, tokens};
			}
		}

	}
	return { IllegalCharError(""), false, tokens};
}