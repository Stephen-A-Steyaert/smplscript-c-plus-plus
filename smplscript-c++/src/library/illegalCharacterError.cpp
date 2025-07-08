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

#include "common/common.h"

/// Default constructor delegates to base Error with empty parameters.
IllegalCharacterError::IllegalCharacterError()
    : Error("Illegal Character", Position(), Position(), "") {}

/// Constructor initializes base Error with the error name and position info.
IllegalCharacterError::IllegalCharacterError(const Position& posStart, const Position& posEnd, const std::string& details)
    : Error("Illegal Character", posStart, posEnd, details) {}
