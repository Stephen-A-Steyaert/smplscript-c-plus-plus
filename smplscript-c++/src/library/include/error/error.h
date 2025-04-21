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

/*
* Error object is the base class for future errors
*/

class Error
{
public:
	Error(std::string errorName, std::Position* posStart, std::Position* posEnd, std::string details);
	std::string toString();
private:
	std::string mErrorName;
	std::string mDetails;
	std::Position* mPosStart;
	std::Position* mPosEnd;
};

#endif
