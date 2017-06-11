//
// Created by gritukan on 6/11/17.
//

#include "NodeArgumentsDeclaration.h"

NodeArgumentsDeclaration::NodeArgumentsDeclaration() {
    type = NodeType::ARGUMENTS_DECLARATION;
    argumentsDeclaration = nullptr;
}
NodeArgumentsDeclaration *parseNodeArgumentsDeclaration(ParserState &state) {
    if (!state.haveTokens() || state.getNextToken().value != "int") return nullptr;
    state.nextToken();
    NodeArgumentsDeclaration *result = new NodeArgumentsDeclaration();
    result->value = state.nextToken().value;
    if (state.getNextToken().value == ",") {
        state.nextToken();
        result->argumentsDeclaration = parseNodeArgumentsDeclaration(state);
    }
    return result;
}
void NodeArgumentsDeclaration::assembly(ProgramState &state, size_t offset) {
    state.addFunctionArgument(value, offset);
    if (argumentsDeclaration != nullptr) {
        argumentsDeclaration->assembly(state, offset + 4);
    }
}