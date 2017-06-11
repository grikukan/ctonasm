//
// Created by gritukan on 6/11/17.
//

#include "NodeReturn.h"

NodeReturn::NodeReturn() {
    type = NodeType::NODE_RETURN;
    expression = nullptr;
}

NodeReturn* parseNodeReturn(ParserState &state) {
    state.nextToken();
    NodeReturn *result = new NodeReturn();
    result->expression = parseNodeExpression(state);
    return result;
}

void NodeReturn::assembly(ProgramState &state) {
    if (expression == nullptr) {
        state.addLine("xor eax, eax");
    } else {
        expression->assembly(state);
    }
    state.addLine("leave");
    state.addLine("ret");
}