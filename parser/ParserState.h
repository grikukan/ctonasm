//
// Created by gritukan on 6/10/17.
//

#ifndef COMPILER_PARSERSTATE_H
#define COMPILER_PARSERSTATE_H


#include <vector>
#include "../tokenizer/Token.h"

class ParserState {
private:
    std::vector<Token> tokens;
    size_t state;
public:
    ParserState(const std::vector<Token> &tokens);
    bool haveTokens();
    size_t getState();
    void setState(size_t state);
    Token nextToken();
    Token getNextToken();

};


#endif //COMPILER_PARSERSTATE_H
