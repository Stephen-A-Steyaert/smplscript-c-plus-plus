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
#include <string>

// Constructor
// Initializes the Position object with the given index, line, and column.
std::Position::Position(int index, int line, int col, std::string fileName, std::string fileContents) {
    mIndex = index;
    mLine = line;
    mCol = col;
    mFileName = fileName;
    mFileContents = fileContents;
}

// advance function
// Advances the index and column by 1. May also increment the line and reset the column 
// if the character is a newline.
std::Position* std::Position::advance(char c) {
    mIndex++;
    mCol++;
    if (c == '\n') {
        mLine++;
        mCol = 0;
    }
    return this;
} 

// copy function
// Returns a new Position object with the same index, line, and column as the current object.
std::Position* std::Position::copy() {
    return new Position(mIndex, mLine, mCol, mFileName, mFileContents);
}

// getIndex function
// Returns the current index of the Position object.
int std::Position::getIndex() {
    return mIndex;
}

// getFileName function
// Returns the file name of the Position Object.
std::string std::Position::getFileName() {
    return mFileName;
}

// getLineNumber function
// Returns the current line number of the Position object.
int std::Position::getLineNumber() {
    return mLine;
}