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
#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

/*
Constants for Lexer, Parser. Will eventually contain keywords
for defining functions, while and for loops, etc.
*/



const std::string TT_INT = "TT_INT";
const std::string TT_FLOAT = "TT_FLOAT";
const std::string TT_PLUS = "TT_PLUS";
const std::string TT_MINUS = "TT_MINUS";
const std::string TT_MUL = "TT_MUL";
const std::string TT_DIV = "TT_DIV";
const std::string TT_LPAREN = "TT_LPAREN";
const std::string TT_RPAREN = "TT_RPAREN";

// Alphanumeric constants
const std::string DIGITS = "0123456789";
const std::string LETTERS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";


#endif
