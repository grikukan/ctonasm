//
// Created by gritukan on 6/11/17.
//

#include "NodeFunctionDeclaration.h"
#include "NodeArgumentsDeclaration.h"

NodeFunctionDeclaration::NodeFunctionDeclaration() {
    type = NodeType::FUNCTION_DECLARATION;
    argumentsDeclaration = nullptr;
    code = nullptr;
}

NodeFunctionDeclaration *parseNodeFunctionDeclaration(ParserState &state) {
    if (!state.haveTokens()) return nullptr;
    state.nextToken();
    NodeFunctionDeclaration *result = new NodeFunctionDeclaration();
    result->value = state.nextToken().value;
    state.addFunction(result->value);
    state.nextToken(); // (
    result->argumentsDeclaration = parseNodeArgumentsDeclaration(state);
    state.nextToken(); // )
    state.nextToken(); // {
    result->code = parseNodeCode(state);
    state.nextToken();
    return result;
}

void NodeFunctionDeclaration::assembly(ProgramState &state) {
    state.newFunction();
    state.addLine("global " + value);
    state.addLine(value + ":");
    state.addLine("push ebp");
    state.addLine("mov ebp, esp");
    if (argumentsDeclaration != nullptr) {
        argumentsDeclaration->assembly(state);
    }
    code->assembly(state);
    state.addLine("leave");
    state.addLine("ret");
}