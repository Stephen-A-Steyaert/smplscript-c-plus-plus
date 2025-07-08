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

#include <string>
#include <string_view>
#include <vector>
#include <cctype>  // for std::isspace in .cpp
#include "../token/token.h"
#include "../position/position.h"

/// @brief Performs lexical analysis on the input text, generating a list of tokens.
class Lexer
{
public:
    /// @brief Default constructor. Initializes an empty Lexer.
    Lexer();

    /// @brief Constructs a Lexer with the given source file name and input text.
    /// @param fileName The name of the source file.
    /// @param text The source code text to lex.
    Lexer(const std::string& fileName, std::string_view text);

    /// @brief Generates a vector of tokens by analyzing the input text.
    /// @return A vector containing all tokens generated from the source.
    std::vector<Token> generateTokens();

private:
    /// @brief Advances the current position and updates the current character.
    void advance();

    /// @brief Creates a numeric token (int or float) from the current position in the text.
    /// @return A Token representing the number found.
    Token makeNumber();

    std::string mFileName;   ///< The source file name.
    std::string mText;       ///< The source code text being lexed.
    char mCurrentChar;       ///< The current character under examination.
    Position mCurrentPos;    ///< The current position in the source code.
};


