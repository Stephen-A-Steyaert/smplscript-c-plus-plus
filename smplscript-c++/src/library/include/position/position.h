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

namespace std{
/*
* Position object to keep track of the current position in the source code.
*/
    class Position {
    public:
        Position(int index, int line, int col, std::string fileName, std::string fileContents);
        Position* advance(char c);
        Position* copy();
        int getIndex();
        std::string getFileName();
        int getLineNumber();

    private:
        int mIndex;
        int mLine;
        int mCol;
        std::string mFileName;
        std::string mFileContents;

    };
    
}

#endif