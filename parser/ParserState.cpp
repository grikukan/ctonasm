//
// Created by gritukan on 6/10/17.
//

#include "ParserState.h"

ParserState::ParserState(const std::vector<Token> &tokens) : tokens(tokens) {
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




