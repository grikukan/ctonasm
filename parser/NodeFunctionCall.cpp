//
// Created by gritukan on 6/11/17.
//

#include "NodeFunctionCall.h"

NodeFunctionCall::NodeFunctionCall() {
    argumentsList = nullptr;
}

NodeFunctionCall *parseNodeFunctionCall(ParserState &state) {
    if (!state.haveTokens()) return nullptr;
    NodeFunctionCall *result = new NodeFunctionCall();
    result->value = state.nextToken().value;
    state.nextToken(); // (
    result->argumentsList = parseNodeArgumentsList(state);
    state.nextToken(); // )
    state.nextToken(); // ;
    return result;
}

void NodeFunctionCall::assembly(ProgramState &state) {
    size_t argumentsNumber = 0;
    if (argumentsList != nullptr) {
        argumentsNumber = argumentsList->getSize();
    }
    if (argumentsNumber != 0) {
        state.addLine("sub esp, " + std::to_string(4 * argumentsNumber));
    }
    if (argumentsList != nullptr) {
        argumentsList->assembly(state);
    }
    state.addLine("call " + value);
    if (argumentsNumber != 0) {
        state.addLine("add esp, " + std::to_string(4 * argumentsNumber));
    }
}