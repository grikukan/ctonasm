//
// Created by gritukan on 6/10/17.
//

#include "NodeExpression.h"

NodeExpression::NodeExpression() {
    type = NodeType::EXPRESSION;
    expression = nullptr;
}

NodeExpression *parseNodeExpression(ParserState &state) {
    if (!state.haveTokens()) return nullptr;
    NodeExpression *result = new NodeExpression();
    result->value = state.nextToken().value;
    if (state.getNextToken().value == ";" || state.getNextToken().value == ")") {
        return result;
    }
    result->op = state.nextToken().value;
    result->expression = parseNodeExpression(state);
    return result;
}

void NodeExpression::assembly(ProgramState &state) {
    if (expression == nullptr) {
        state.addLine("xor ebx, ebx");
    } else {
        expression->assembly(state);
        state.addLine("mov ebx, eax");
    }
    if (value[0] >= '0' && value[0] <= '9') {
        state.addLine("mov eax, " + value);
    } else {
        state.addLine("mov eax, dword[ebp - " + std::to_string(state.getAddress(value)) + "]");
    }
    if (op == "+") {
        state.addLine("add eax, ebx");
    } else if (op == "-") {
        state.addLine("sub eax, ebx");
    }
}
