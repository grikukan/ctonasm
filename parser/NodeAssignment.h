//
// Created by gritukan on 6/10/17.
//

#ifndef COMPILER_NODEASSIGNMENT_H
#define COMPILER_NODEASSIGNMENT_H

#include <string>
#include "NodeExpression.h"

class NodeAssignment : Node {
private:
    std::string value;
    NodeExpression *expression;
public:
    NodeAssignment();
    friend NodeAssignment *parseNodeAssignment(ParserState &state);
};

NodeAssignment *parseNodeAssignment(ParserState &state);

#endif //COMPILER_NODEASSIGNMENT_H
