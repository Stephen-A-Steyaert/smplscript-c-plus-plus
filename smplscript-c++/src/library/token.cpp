#include "include/token/token.h"
#include <string>
#include <climits>
 
/*
* Defining all of the Token object's functions
*/
// Default constructor
// Initializes all fields to null
std::Token::Token() {
 	mTokenType = nullptr;
 	mStringValue = nullptr;
    mIntValue = LLONG_MIN;
 }
// Constructor
// Initializes the token type field to the input token type
std::Token::Token(std::string tokenType) {
 	mTokenType = tokenType;
 	mStringValue = nullptr;
    mIntValue = LLONG_MIN;
}
// Constructor
// Initializes the token type field to the input token type,
// and the string value field to the input string value
std::Token::Token(std::string tokenType, std::string stringValue) {
 	mTokenType = tokenType;
 	mStringValue = stringValue;
    mIntValue = LLONG_MIN;
}
 // Constructor
 // Initializes the token type field to the input token type,
 // and the int value field to the input int value
std::Token::Token(std::string tokenType, long long intValue) {
 	mTokenType = tokenType;
 	mStringValue = nullptr;
 	mIntValue = intValue;
}
 // getValue function
 // Returns a valueReturn struct containing the string and int values
std::Token::valueReturn std::Token::getValue() {
 	valueReturn returnValue;
 	returnValue.stringValue = mStringValue;
 	returnValue.intValue = mIntValue;
 	return returnValue;
}
 // getTokenType function
 // Returns the token type
std::string std::Token::getTokenType() {
 	return mTokenType;
}
 // operator<< function
 // Overloads the << operator to print the token type and value (if it exists)
std::string std::Token::toString() {
 	std::string out = mTokenType;
 	if (mStringValue.compare(nullptr) != 0) {
 		out += ":" + mStringValue;
 	}
 	else if (mIntValue != LLONG_MIN) {
 		out += ":" + std::to_string(mIntValue);
 	}
    return out;
 }