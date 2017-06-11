//
// Created by gritukan on 6/10/17.
//

#include "NodeCode.h"

NodeCode::NodeCode() {
    type = NodeType::CODE;
    assignment = nullptr;
    declaration = nullptr;
    functionCall = nullptr;
    code = nullptr;
}

NodeCode *parseNodeCode(ParserState &state) {
    if (!state.haveTokens()) return nullptr;
    if (state.getNextToken().value == "}") return nullptr;
    NodeCode *result = new NodeCode();
    if (state.getNextToken().value == "int") {
        result->declaration = parseNodeDeclaration(state);
    } else if (state.isFunction(state.getNextToken().value)) {
        result->functionCall = parseNodeFunctionCall(state);
    } else {
        result->assignment = parseNodeAssignment(state);
    }
    result->code = parseNodeCode(state);
    return result;
}

void NodeCode::assembly(ProgramState &state) {
    if (assignment != nullptr) {
        assignment->assembly(state);
    } else if (functionCall != nullptr) {
        functionCall->assembly(state);
    } else {
        declaration->assembly(state);
    }
    if (code != nullptr) {
        code->assembly(state);
    }
}
