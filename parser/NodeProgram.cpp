//
// Created by gritukan on 6/10/17.
//

#include "NodeProgram.h"

NodeProgram::NodeProgram() {
    type = NodeType::PROGRAM;
    assignment = nullptr;
    declaration = nullptr;
    program = nullptr;
}

NodeProgram *parseNodeProgram(ParserState &state) {
    if (!state.haveTokens()) return nullptr;
    NodeProgram *result = new NodeProgram();
    if (state.getNextToken().value == "int") {
        result->declaration = parseNodeDeclaration(state);
    } else {
        result->assignment = parseNodeAssignment(state);
    }
    result->program = parseNodeProgram(state);
    return result;
}

void NodeProgram::assembly(ProgramState &state) {
    if (assignment != nullptr) {
        assignment->assembly(state);
    } else {
        declaration->assembly(state);
    }
    if (program != nullptr) {
        program->assembly(state);
    }
}
