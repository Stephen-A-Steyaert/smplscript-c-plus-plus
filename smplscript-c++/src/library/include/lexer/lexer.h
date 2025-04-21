#pragma once
#ifndef LEXER_H
#define LEXER_H

#include "../token/token.h"
#include <string>
#include <vector>
 
 /*
 * Lexer object will be use to tokenize input code.
 */
namespace std
{

    class Lexer
    {
    public:
        Lexer();
        Lexer(std::string text);
        std::vector<std::Token> generateTokens();
    private:
        void advance();
        std::Token makeNumber();
        std::string mText;
        char mCurrentChar;
        int mCurrentPos;
    };
} // namespace std
#endif