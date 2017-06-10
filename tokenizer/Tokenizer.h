//
// Created by gritukan on 6/10/17.
//

#ifndef COMPILER_TOKENIZER_H
#define COMPILER_TOKENIZER_H


#include <vector>
#include <string>
#include "Token.h"

class Tokenizer {
private:
    const static std::unordered_set<std::string> terminals;
    bool isSpace(char c);
    bool isDigit(char c);
    bool isLetter(char c);
public:
    std::vector<Token> tokenize(const std::string &source);
};



#endif //COMPILER_TOKENIZER_H
