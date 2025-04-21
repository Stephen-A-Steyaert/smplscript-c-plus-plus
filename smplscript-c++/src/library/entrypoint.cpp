#include "include/entrypoint/entrypoint.h"
#include "error/illegalCharacterError.h"
#include "include/lexer/lexer.h"
#include "token/token.h"
#include <iostream>
#include <string>

// run function
// creates a Lexer object, generates tokens from input text, returns the result
std::vector<std::Token> run(std::string text) {
    std::Lexer lexer = std::Lexer(text);

    std::vector<std::Token> lexerResult;

    try{
        lexerResult =  lexer.generateTokens();
    }catch(std::IllegalCharacterError error){
        std::cerr << error.toString() << std::endl;
    }
    return lexerResult;
}
