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
#include <vector>
#include "../token/token.h"

/// @brief Runs the lexer and parser on the provided source code text.
/// @param fileName The name of the source file (used for error reporting).
/// @param text The source code text to process.
/// @return A vector of tokens produced from the input text.
std::vector<Token> run(const std::string &fileName, const std::string &text);
