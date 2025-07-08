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

#include "include/common/common.h"
#include <iostream>
#include <utility>


	// Default constructor
	Token::Token() : mTokenType(""), mValue(std::monostate{}) {}

	// Token type only
	Token::Token(std::string tokenType)
		: mTokenType(std::move(tokenType)), mValue(std::monostate{}) {}

	// Token with int value
	Token::Token(std::string tokenType, int intValue)
		: mTokenType(std::move(tokenType)), mValue(intValue) {}

	// Token with float value
	Token::Token(std::string tokenType, float floatValue)
		: mTokenType(std::move(tokenType)), mValue(floatValue) {}

	// Token with string value
	Token::Token(std::string tokenType, std::string stringValue)
		: mTokenType(std::move(tokenType)), mValue(std::move(stringValue)) {}

	// Accessors
	const Token::Value& Token::getValue() const {
		return mValue;
	}

	const std::string& Token::getTokenType() const {
		return mTokenType;
	}

	// Stream output operator
	std::ostream& operator<<(std::ostream& os, const Token& token)
	{
		os << token.getTokenType();

		const Token::Value& val = token.getValue();

		std::visit([&os](auto&& arg) {
			using T = std::decay_t<decltype(arg)>;
			if constexpr (std::is_same_v<T, std::monostate>) {
				// continue to else
			} else {
				os << ":" << arg;
			}
		}, val);

		return os;
	}
