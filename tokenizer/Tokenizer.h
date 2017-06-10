//
// Created by gritukan on 6/10/17.
//

#ifndef COMPILER_TOKENIZER_H
#define COMPILER_TOKENIZER_H


#include <vector>
#include <string>
#include "Token.h"

class Tokenizer {
public:
    std::vector<Token> tokenize(const std::string &source);
};


#endif //COMPILER_TOKENIZER_H
