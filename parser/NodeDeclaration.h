//
// Created by gritukan on 6/10/17.
//

#ifndef COMPILER_NODEDECLARATION_H
#define COMPILER_NODEDECLARATION_H

#include <string>
#include "Node.h"
#include "NodeExpression.h"

class NodeDeclaration : Node {
private:
    std::string value;
    NodeExpression *expression;
public:
    NodeDeclaration();
    friend NodeDeclaration *parseNodeDeclaration(ParserState &state);
};

NodeDeclaration *parseNodeDeclaration(ParserState &state);

#endif //COMPILER_NODEDECLARATION_H
