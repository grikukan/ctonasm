//
// Created by gritukan on 6/10/17.
//

#include "NodeExpression.h"

NodeExpression::NodeExpression() {
    type = NodeType::EXPRESSION;
    unary = nullptr;
    leftExpression = nullptr;
    rightExpression = nullptr;
}

NodeExpression *parseNodeExpression(ParserState &state) {
    if (!state.haveTokens()) return nullptr;
    if (state.getNextToken().value == ";") return nullptr;
    NodeExpression *result = new NodeExpression();
    result->unary = parseNodeUnaryExpression(state);
    if (state.getNextToken().value == "+" || state.getNextToken().value == "-" || state.getNextToken().value == "=") {
        result->op = state.nextToken().value;
        result->rightExpression = parseNodeExpression(state);
    }
    return result;
}

void NodeExpression::assembly(ProgramState &state) {
    if (op == "=") {
        rightExpression->assembly(state);
        state.addLine("mov dword" + state.getAddress(unary->getValue()) + ", eax");
        return;
    }
    if (rightExpression != nullptr) {
        rightExpression->assembly(state);
        state.addLine("push eax");
    }
    unary->assembly(state);
    if (rightExpression != nullptr) {
        state.addLine("pop ebx");
        if (op == "+") {
            state.addLine("add eax, ebx");
        } else {
            state.addLine("sub eax, ebx");
        }
    }
}
