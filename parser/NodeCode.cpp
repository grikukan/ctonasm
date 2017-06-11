//
// Created by gritukan on 6/10/17.
//

#include "NodeCode.h"
#include "NodeReturn.h"

NodeCode::NodeCode() {
    type = NodeType::CODE;
    declaration = nullptr;
    expression = nullptr;
    nodeReturn = nullptr;
    code = nullptr;
}

NodeCode *parseNodeCode(ParserState &state) {
    if (!state.haveTokens()) return nullptr;
    if (state.getNextToken().value == "}") return nullptr;
    NodeCode *result = new NodeCode();
    if (state.getNextToken().value == "int") {
        result->declaration = parseNodeDeclaration(state);
    } else if (state.getNextToken().value == "return") {
        result->nodeReturn = parseNodeReturn(state);
    } else {
        result->expression = parseNodeExpression(state);
    }
    state.nextToken(); // ;
    result->code = parseNodeCode(state);
    return result;
}

void NodeCode::assembly(ProgramState &state) {
    if (expression != nullptr) {
        expression->assembly(state);
    } else if (nodeReturn != nullptr) {
        nodeReturn->assembly(state);
    } else {
        declaration->assembly(state);
    }
    if (code != nullptr) {
        code->assembly(state);
    }
}
