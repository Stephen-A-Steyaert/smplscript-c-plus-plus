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

#include "include/position/position.h"

/// Default constructor. Initializes all members to default values.
Position::Position()
    : mIndex(0), mLine(0), mCol(0), mFileName(""), mFileContents("") {}

/// Parameterized constructor
Position::Position(int index, int line, int col, const std::string &fileName, const std::string &fileContents)
    : mIndex(index), mLine(line), mCol(col), mFileName(fileName), mFileContents(fileContents) {}

/// Advances the position by one character
Position Position::advance(char c) const
{
    Position result = *this;
    result.mIndex++;
    result.mCol++;
    if (c == '\n')
    {
        result.mLine++;
        result.mCol = 0;
    }
    return result;
}

/// Returns a copy of the current position
Position Position::copy() const
{
    return Position(mIndex, mLine, mCol, mFileName, mFileContents);
}

/// Returns the index
int Position::getIndex() const
{
    return mIndex;
}

/// Returns the file name
const std::string &Position::getFileName() const
{
    return mFileName;
}

/// Returns the line number
int Position::getLineNumber() const
{
    return mLine;
}

/// Returns the column number
int Position::getCol() const
{
    return mCol;
}

/// Returns the file contents
const std::string &Position::getFileContents() const
{
    return mFileContents;
}

/// Stream output operator for Position.
/// Outputs the file name, line number, and column in a readable format.
/// Example output: "main.smpl Line: 12 Col: 5"
/// @param os Output stream to write to.
/// @param pos Position object to print.
/// @return Reference to the output stream.
std::ostream &operator<<(std::ostream &os, const Position &pos)
{
    os << pos.getFileName() << " Line: " << pos.getLineNumber() + 1 << " Col: " << pos.getCol() + 1;
    return os;
}
