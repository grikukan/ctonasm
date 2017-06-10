//
// Created by gritukan on 6/10/17.
//

#ifndef COMPILER_TOKEN_H
#define COMPILER_TOKEN_H


#include <string>
#include <unordered_set>

enum class TokenType {ID, CONSTANT, TERMINAL};

class Token {

public:
    const std::string value;
    const TokenType type;
    Token(const std::string &value, const TokenType &type) : value(value), type(type) {};
};


#endif //COMPILER_TOKEN_H
