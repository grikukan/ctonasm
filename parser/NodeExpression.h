//
// Created by gritukan on 6/10/17.
//

#ifndef COMPILER_NODEEXPRESSION_H
#define COMPILER_NODEEXPRESSION_H

#include <string>
#include "ParserState.h"
#include "Node.h"
#include "../assembler/ProgramState.h"
#include "NodeUnaryExpression.h"

class NodeExpression : Node {
private:
    NodeUnaryExpression *unary;
    NodeExpression *leftExpression;
    std::string op;
    NodeExpression *rightExpression;
public:
    NodeExpression();
    friend NodeExpression *parseNodeExpression(ParserState &state);
    void assembly(ProgramState &state);

};

NodeExpression *parseNodeExpression(ParserState &state);

#endif //COMPILER_NODEEXPRESSION_H
