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

#include "include/error/illegalCharacterError.h"
#include "include/lexer/lexer.h"
#include "include/constants/constants.h"
#include "token/token.h"
#include <string>
#include <vector>
#include <cctype> // for std::isspace

Lexer::Lexer()
	: mFileName(""), mText(""), mCurrentChar('\0'), mCurrentPos(-1, 0, -1, "", "") {}

Lexer::Lexer(const std::string &fileName, const std::string &text)
	: mFileName(fileName), mText(text), mCurrentChar('\0'), mCurrentPos(-1, 0, -1, fileName, text)
{
	advance();
}

void Lexer::advance()
{
	mCurrentPos = mCurrentPos.advance(mCurrentChar);

	if (mCurrentPos.getIndex() < static_cast<int>(mText.size()))
	{
		mCurrentChar = mText[mCurrentPos.getIndex()];
	}
	else
	{
		mCurrentChar = '\0';
	}
}

Token Lexer::makeNumber()
{
	std::string numberString;
	int dotCount = 0;

	while (mCurrentChar != '\0' && (DIGITS.find(mCurrentChar) != std::string::npos || mCurrentChar == '.'))
	{
		if (mCurrentChar == '.')
		{
			if (dotCount == 1)
				break;
			dotCount++;
		}
		numberString += mCurrentChar;
		advance();
	}

	if (dotCount == 1)
	{
		return Token(TT_FLOAT, std::stof(numberString));
	}
	else
	{
		return Token(TT_INT, std::stoi(numberString));
	}
}

std::vector<Token> Lexer::generateTokens()
{
	std::vector<Token> tokens;

	while (mCurrentChar != '\0')
	{
		if (std::isspace(static_cast<unsigned char>(mCurrentChar)))
		{
			advance();
		}
		else if (DIGITS.find(mCurrentChar) != std::string::npos)
		{
			tokens.emplace_back(makeNumber());
		}
		else
		{
			switch (mCurrentChar)
			{
			case '+':
				tokens.emplace_back(TT_PLUS);
				advance();
				break;
			case '-':
				tokens.emplace_back(TT_MINUS);
				advance();
				break;
			case '*':
				tokens.emplace_back(TT_MUL);
				advance();
				break;
			case '/':
				tokens.emplace_back(TT_DIV);
				advance();
				break;
			case '(':
				tokens.emplace_back(TT_LPAREN);
				advance();
				break;
			case ')':
				tokens.emplace_back(TT_RPAREN);
				advance();
				break;
			default:
			{
				Position posStart = mCurrentPos.copy();
				char currentChar = mCurrentChar;
				advance();
				tokens.clear();
				throw IllegalCharacterError(posStart, mCurrentPos, "'" + std::string(1, currentChar) + "'");
			}
			}
		}
	}

	return tokens;
}
