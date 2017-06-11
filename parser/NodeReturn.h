//
// Created by gritukan on 6/11/17.
//

#ifndef COMPILER_NODERETURN_H
#define COMPILER_NODERETURN_H


#include "NodeExpression.h"

class NodeReturn : Node {
private:
    NodeExpression *expression;
public:
    NodeReturn();
    friend NodeReturn *parseNodeReturn(ParserState &state);
    void assembly(ProgramState &state);
};

NodeReturn *parseNodeReturn(ParserState &state);

#endif //COMPILER_NODERETURN_H
