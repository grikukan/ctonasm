//
// Created by gritukan on 6/11/17.
//

#include "NodeArgumentsList.h"

NodeArgumentsList::NodeArgumentsList() {
    type = NodeType::ARGUMENTS_LIST;
    expression = nullptr;
    arguments = nullptr;
}

NodeArgumentsList *parseNodeArgumentsList(ParserState &state) {
    if (!state.haveTokens()) return nullptr;
    if (state.getNextToken().value == ")") {
        return nullptr;
    }
    NodeArgumentsList *result = new NodeArgumentsList();
    result->expression = parseNodeExpression(state);
    if (state.getNextToken().value == ",") {
        state.nextToken();
        result->arguments = parseNodeArgumentsList(state);
    }
    return result;
}

size_t NodeArgumentsList::getSize() const {
    if (arguments == nullptr) return 1;
    return arguments->getSize() + 1;
}

void NodeArgumentsList::assembly(ProgramState &state, size_t offset) {
    expression->assembly(state);
    state.addLine("mov dword[esp + " + std::to_string(4 * offset) + "], eax");
    if (arguments != nullptr) {
        arguments->assembly(state, offset + 1);
    }
}

