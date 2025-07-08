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
#ifndef ILLEGALCHARACTERERROR_H
#define ILLEGALCHARACTERERROR_H

#include "error.h"
#include "../position/position.h"
#include <string>

/// Error class representing illegal characters encountered during lexing.
class IllegalCharacterError : public Error
{
public:
    /// Default constructor.
    IllegalCharacterError();

    /// Constructs an IllegalCharacterError with position range and details.
    /// @param posStart The starting position of the illegal character.
    /// @param posEnd The ending position of the illegal character.
    /// @param details Additional details about the error.
    IllegalCharacterError(const Position& posStart, const Position& posEnd, const std::string& details);
};

#endif // ILLEGALCHARACTERERROR_H
