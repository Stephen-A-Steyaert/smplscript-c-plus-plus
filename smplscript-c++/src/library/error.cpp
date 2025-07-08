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


#include <iostream>
#include "include/error/error.h"
#include "include/position/position.h"

Error::Error(const std::string& errorName, const Position& posStart, const Position& posEnd, const std::string& details)
    : mErrorName(errorName), mDetails(details), mPosStart(posStart), mPosEnd(posEnd) {}

const std::string& Error::getErrorName() const { return mErrorName; }

const std::string& Error::getDetails() const { return mDetails; }

const Position& Error::getStart() const { return mPosStart; }

const Position& Error::getEnd() const { return mPosEnd; }

std::ostream& operator<<(std::ostream& os, const Error& error)
{
    os << error.getErrorName() << ": " << error.getDetails() << "\n";
    os << error.getStart();  // uses Position's operator<<
    return os;
}
