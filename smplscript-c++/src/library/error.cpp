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


#include <string>
#include "include/error/error.h"
#include "include/position/position.h"

// Constructor
// Initializes the error name and details
Error::Error(std::string errorName, std::Position* posStart,std::Position* posEnd, std::string details) {
	mErrorName = errorName;
	mDetails = details;
	mPosStart = posStart;
	mPosEnd = posEnd;
}
// toString function
// Returns the error name and details as a string
std::string Error::toString() {
	std::string errorStr = mErrorName + ": " + mDetails + "\n";
	errorStr += "File: " + mPosStart->getFileName() + " Line: " + std::to_string(mPosStart->getLineNumber()) + "\n";

	return errorStr;
}