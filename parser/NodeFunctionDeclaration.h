//
// Created by gritukan on 6/11/17.
//

#ifndef COMPILER_NODEFUNCTIONDECLARATION_H
#define COMPILER_NODEFUNCTIONDECLARATION_H

#include <string>
#include "NodeCode.h"
#include "NodeArgumentsDeclaration.h"

class NodeFunctionDeclaration : Node {
private:
    std::string value;
    NodeArgumentsDeclaration *argumentsDeclaration;
    NodeCode *code;
public:
    NodeFunctionDeclaration();
    friend NodeFunctionDeclaration *parseNodeFunctionDeclaration(ParserState &state);
    void assembly(ProgramState &state);
};

NodeFunctionDeclaration *parseNodeFunctionDeclaration(ParserState &state);

#endif //COMPILER_NODEFUNCTIONDECLARATION_H
