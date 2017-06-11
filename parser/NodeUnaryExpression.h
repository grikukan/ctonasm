//
// Created by gritukan on 6/11/17.
//

#ifndef COMPILER_NODEUNARYEXPRESSION_H
#define COMPILER_NODEUNARYEXPRESSION_H


#include "NodeFunctionCall.h"

class NodeUnaryExpression : Node {
private:
    NodeFunctionCall *functionCall;
    std::string value;
public:
    NodeUnaryExpression();
    friend NodeUnaryExpression *parseNodeUnaryExpression(ParserState &state);
    void assembly(ProgramState &state);
    std::string getValue() const;
};

NodeUnaryExpression *parseNodeUnaryExpression(ParserState &state);
#endif //COMPILER_NODEUNARYEXPRESSION_H
