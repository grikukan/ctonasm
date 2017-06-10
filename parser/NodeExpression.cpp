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
    result->op = state.nextToken().value;
    if (result->op == ";") {
        return result;
    }
    result->expression = parseNodeExpression(state);
    return result->expression;
}
