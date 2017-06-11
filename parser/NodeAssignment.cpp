//
// Created by gritukan on 6/10/17.
//

#include "NodeAssignment.h"

NodeAssignment::NodeAssignment() {
    type = NodeType::ASSIGNMENT;
    expression = nullptr;
}

NodeAssignment *parseNodeAssignment(ParserState &state) {
    if (!state.haveTokens()) return nullptr;
    NodeAssignment *result = new NodeAssignment(); // <id> = expression;
    result->value = state.nextToken().value;
    state.nextToken(); // =
    result->expression = parseNodeExpression(state);
    state.nextToken(); // ;
    return result;
}
void NodeAssignment::assembly(ProgramState &state) {
    expression->assembly(state);
    state.addLine("mov dword[ebp - " + std::to_string(state.getAddress(value)) + "], eax");
}