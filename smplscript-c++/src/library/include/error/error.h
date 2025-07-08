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
#ifndef ERROR_H
#define ERROR_H

#include <string>
#include "../include/position/position.h"

/// Represents a language error with positional context in the source code.
/// This is the base class for all error types in smplscript, such as syntax or runtime errors.
class Error
{
public:
    /// Constructs an Error object.
    /// @param errorName The name/type of the error (e.g., "SyntaxError").
    /// @param posStart The starting position of the error.
    /// @param posEnd The ending position of the error.
    /// @param details A description of the error.
    Error(const std::string& errorName, const Position& posStart, const Position& posEnd, const std::string& details);

    /// Gets the error name/type.
    /// @return The error name string.
    const std::string& getErrorName() const;

    /// Gets the error message/details.
    /// @return The error details string.
    const std::string& getDetails() const;

    /// Gets the start position of the error.
    /// @return A const reference to the starting Position.
    const Position& getStart() const;

    /// Gets the end position of the error.
    /// @return A const reference to the ending Position.
    const Position& getEnd() const;

private:
    std::string mErrorName;   ///< The type/name of the error (e.g. "SyntaxError")
    std::string mDetails;     ///< Description or message of the error
    Position mPosStart;       ///< Start position in the source file
    Position mPosEnd;         ///< End position in the source file
};

/// Prints an Error object to an output stream in a human-readable format.
/// @param os The output stream.
/// @param error The Error object to print.
/// @return Reference to the modified output stream.
std::ostream& operator<<(std::ostream& os, const Error& error);

#endif // ERROR_H

