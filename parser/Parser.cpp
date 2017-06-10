//
// Created by gritukan on 6/10/17.
//

#include "Parser.h"
#include "ParserState.h"
#include "NodeProgram.h"

NodeProgram *Parser::parse(const std::vector<Token> &tokens) {
    ParserState state(tokens);
    NodeProgram *program = parseNodeProgram(state);
    return program;
}