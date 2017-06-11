//
// Created by gritukan on 6/10/17.
//

#include "Parser.h"

NodeProgram *Parser::parse(const std::vector<Token> &tokens) {
    ParserState state(tokens);
    NodeProgram *program = parseNodeProgram(state);
    return program;
}