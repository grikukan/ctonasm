//
// Created by gritukan on 6/11/17.
//

#include "NodeUnaryExpression.h"

NodeUnaryExpression::NodeUnaryExpression() {
    type = NodeType::UNARY_EXRESSION;
    functionCall = nullptr;
}
NodeUnaryExpression *parseNodeUnaryExpression(ParserState &state) {
    if (!state.haveTokens()) return nullptr;
    NodeUnaryExpression *result = new NodeUnaryExpression();
    if (state.isFunction(state.getNextToken().value)) {
        result->functionCall = parseNodeFunctionCall(state);
    } else {
        result->value = state.nextToken().value;
    }
    return result;
}

void NodeUnaryExpression::assembly(ProgramState &state) {
    if (functionCall != nullptr) {
        functionCall->assembly(state);
    } else if (value[0] >= '0' && value[0] <= '9') {
        state.addLine("mov eax, " + value);
    } else {
        state.addLine("mov eax, dword" + state.getAddress(value));
    }
}

std::string NodeUnaryExpression::getValue() const {
    return value;
}