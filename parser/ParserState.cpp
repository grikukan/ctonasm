//
// Created by gritukan on 6/10/17.
//

#include "ParserState.h"

ParserState::ParserState(const std::vector<Token> &tokens) : tokens(tokens) {
    functionsNames = {"main", "PRINT_INT"};
    state = 0;
}

size_t ParserState::getState() {
    return state;
}

void ParserState::setState(size_t state) {
    this->state = state;
}

bool ParserState::haveTokens() {
    return state < tokens.size();
}

Token ParserState::nextToken() {
    state++;
    return tokens[state - 1];
}

Token ParserState::getNextToken() {
    return tokens[state];
}

bool ParserState::isFunction(const std::string &name) {
    return functionsNames.count(name);
}




