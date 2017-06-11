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
    if (state.nextToken().value == ";") { // int x;
        return result;
    } else {
        result->expression = parseNodeExpression(state); // int x = <expression>;
        state.nextToken(); // ; at the end
    }
    return result;
}


void NodeDeclaration::assembly(ProgramState &state) {
    state.addVariable(value);
    if (expression != nullptr) {
        expression->assembly(state);
        state.addLine("mov dword[ebp - " + std::to_string(state.getAddress(value)) + "], eax");
    }
}