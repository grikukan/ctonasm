//
// Created by gritukan on 6/10/17.
//

#include "NodeProgram.h"
#include "NodeDeclaration.h"
#include "NodeExpression.h"

NodeProgram::NodeProgram() {
    type = NodeType::PROGRAM;
    expression = nullptr;
    declaration = nullptr;
    program = nullptr;
}

NodeProgram *parseNodeProgram(ParserState &state) {
    if (!state.haveTokens()) return nullptr;
    NodeProgram *result = new NodeProgram();
    if (state.getNextToken().value == "int") {
        result->declaration = parseNodeDeclaration(state);
    } else {
        result->expression = parseNodeExpression(state);
    }
    result->program = parseNodeProgram(state);
    return result;
}
