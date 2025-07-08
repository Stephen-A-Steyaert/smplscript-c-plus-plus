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
#ifndef POSITION_H
#define POSITION_H

#include <string>
#include <ostream>

/// Represents a position in the source code, including index, line, column, and file metadata.
class Position {
public:
    /// Default constructor. Initializes all values to zero or empty.
    Position();

    /// Constructs a Position object with the given data.
    /// @param index The character index in the file.
    /// @param line The current line number.
    /// @param col The current column number.
    /// @param fileName The name of the source file.
    /// @param fileContents The contents of the source file.
    Position(int index, int line, int col, const std::string& fileName, const std::string& fileContents);

    /// Returns a copy of this Position advanced by one character.
    /// If the character is a newline, increments the line and resets the column.
    /// @param c The character that was read.
    /// @return A new Position object advanced by one character.
    Position advance(char c) const;

    /// Returns a copy of this Position object.
    /// @return A copy of the current Position.
    Position copy() const;

    /// Gets the character index.
    /// @return The character index in the source file.
    int getIndex() const;

    /// Gets the source file name.
    /// @return The file name string.
    const std::string& getFileName() const;

    /// Gets the current line number.
    /// @return The current line number.
    int getLineNumber() const;

    /// Gets the current column number.
    /// @return The current column number.
    int getCol() const;

    /// Gets the full source file contents.
    /// @return The file contents.
    const std::string& getFileContents() const;

private:
    int mIndex;              ///< The current character index in the file.
    int mLine;               ///< The current line number.
    int mCol;                ///< The current column number.
    std::string mFileName;  ///< The name of the source file.
    std::string mFileContents; ///< The full contents of the source file.
};

/// Prints a Position object to an output stream in a human-readable format.
/// @param os The output stream.
/// @param pos The Position object to print.
/// @return Reference to the modified output stream.
std::ostream& operator<<(std::ostream& os, const Position& pos);

#endif // POSITION_H

