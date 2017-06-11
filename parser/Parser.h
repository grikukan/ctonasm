//
// Created by gritukan on 6/10/17.
//

#ifndef COMPILER_PARSER_H
#define COMPILER_PARSER_H


#include <vector>
#include "Node.h"
#include "../tokenizer/Token.h"
#include "NodeCode.h"
#include "NodeProgram.h"

class Parser {
public:
    NodeProgram *parse(const std::vector<Token> &tokens);
};


#endif //COMPILER_PARSER_H
