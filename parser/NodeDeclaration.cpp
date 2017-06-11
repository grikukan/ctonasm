//
// Created by gritukan on 6/10/17.
//

#include "NodeDeclaration.h"

NodeDeclaration::NodeDeclaration() {
    type = NodeType::DECLARATION;
    expression = nullptr;
}

NodeDeclaration *parseNodeDeclaration(ParserState &state) {
    if (!state.haveTokens() || state.getNextToken().value != "int") return nullptr;
    NodeDeclaration *result = new NodeDeclaration();
    state.nextToken();
    result->value = state.nextToken().value;
    if (state.getNextToken().value == ";") { // int x;
        return result;
    } else {
        state.nextToken();
        result->expression = parseNodeExpression(state); // int x = <expression>
    }
    return result;
}


void NodeDeclaration::assembly(ProgramState &state) {
    state.addVariable(value);
    if (expression != nullptr) {
        expression->assembly(state);
        state.addLine("mov dword" + state.getAddress(value) + ", eax");
    }
}