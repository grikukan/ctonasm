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
    std::unordered_set<std::string> functionsNames;
    size_t state;
public:
    ParserState(const std::vector<Token> &tokens);
    bool haveTokens();
    bool isFunction(const std::string &name);
    void addFunction(const std::string &name);
    size_t getState();
    void setState(size_t state);
    Token nextToken();
    Token getNextToken();

};


#endif //COMPILER_PARSERSTATE_H
