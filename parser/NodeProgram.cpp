//
// Created by gritukan on 6/11/17.
//

#include "NodeProgram.h"

NodeProgram::NodeProgram() {
    type = NodeType::PROGRAM;
    function = nullptr;
    program = nullptr;
}

NodeProgram *parseNodeProgram(ParserState &state) {
    NodeProgram *result = new NodeProgram();
    result->function = parseNodeFunctionDeclaration(state);
    if (state.haveTokens()) {
        result->program = parseNodeProgram(state);
    }
    return result;
}

void NodeProgram::assembly(ProgramState &state) {
    function->assembly(state);
    if (program != nullptr) {
        program->assembly(state);
    }
}