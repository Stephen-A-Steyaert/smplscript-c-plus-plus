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

#include <string>
#include <variant>
#include <ostream>

	/// Represents a lexical token in the language, with optional associated value.
	class Token
	{
	public:
		/// Variant type that can store an int, float, string, or no value.
		using Value = std::variant<std::monostate, int, float, std::string>;

	private:
		std::string mTokenType; ///< The type of the token (e.g. "INT", "PLUS", etc.)
		Value mValue; ///< The value associated with the token (if any)

	public:
		/// Default constructor. Token type and value are unset.
		Token();

		/// Constructs a token with a given type and no value.
		/// @param tokenType The type of token.
		explicit Token(std::string tokenType);

		/// Constructs a token with an integer value.
		/// @param tokenType The type of token.
		/// @param intValue The integer value associated with the token.
		Token(std::string tokenType, int intValue);

		/// Constructs a token with a float value.
		/// @param tokenType The type of token.
		/// @param floatValue The float value associated with the token.
		Token(std::string tokenType, float floatValue);

		/// Constructs a token with a string value.
		/// @param tokenType The type of token.
		/// @param stringValue The string value associated with the token.
		Token(std::string tokenType, std::string stringValue);

		/// Gets the value stored in the token.
		/// @return A const reference to the token's value.
		const Value& getValue() const;

		/// Gets the type string of the token.
		/// @return A const reference to the token type.
		const std::string& getTokenType() const;
	};

	/// Prints a token to an output stream in the format "TYPE[:value]".
	/// @param os The output stream.
	/// @param token The token to print.
	/// @return The modified output stream.
	std::ostream& operator<<(std::ostream& os, const Token& token);

#endif // TOKEN_H