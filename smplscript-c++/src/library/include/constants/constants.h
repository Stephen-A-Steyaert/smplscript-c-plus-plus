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

/// @brief type for integer literals.
inline const std::string TT_INT = "TT_INT";

/// @brief type for floating-point literals.
inline const std::string TT_FLOAT = "TT_FLOAT";

/// @brief type for the '+' operator.
inline const std::string TT_PLUS = "TT_PLUS";

/// @brief Token type for the '-' operator.
inline const std::string TT_MINUS = "TT_MINUS";

/// @brief type for the '*' operator.
inline const std::string TT_MUL = "TT_MUL";

/// @brief type for the '/' operator.
inline const std::string TT_DIV = "TT_DIV";

/// @brief type for '('.
inline const std::string TT_LPAREN = "TT_LPAREN";

/// @brief type for ')'.
inline const std::string TT_RPAREN = "TT_RPAREN";

/// @brief Token type for the end of the file.
inline const std::string TT_EOF = "TT_EOF";

/// @brief digit characters (0–9).
inline const std::string DIGITS = "0123456789";

/// @brief letter characters (A–Z, a–z).
inline const std::string LETTERS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
