//
// Created by gritukan on 6/10/17.
//

#include "NodeDeclaration.h"

NodeDeclaration::NodeDeclaration() {
    type = NodeType::DECLARATION;
}

NodeDeclaration *parseNodeDeclaration(ParserState &state) {
    if (!state.haveTokens() || state.getNextToken().value != "int") return nullptr;
    NodeDeclaration *result = new NodeDeclaration();
    state.nextToken();
    result->value = state.nextToken().value;
    if (state.nextToken().value == ";") {
        return result;
    } else {
        result->expression = parseNodeExpression(state);
    }
    return result;
}

