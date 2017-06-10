//
// Created by gritukan on 6/10/17.
//

#ifndef COMPILER_NODEEXPRESSION_H
#define COMPILER_NODEEXPRESSION_H

#include <string>
#include "ParserState.h"
#include "Node.h"

class NodeExpression : Node {
private:
    std::string value;
    std::string op;
    NodeExpression *expression;
public:
    NodeExpression();
    friend NodeExpression *parseNodeExpression(ParserState &state);
};

NodeExpression *parseNodeExpression(ParserState &state);

#endif //COMPILER_NODEEXPRESSION_H
