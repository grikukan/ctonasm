//
// Created by gritukan on 6/11/17.
//

#ifndef COMPILER_NODEARGUMENTSDECLARATION_H
#define COMPILER_NODEARGUMENTSDECLARATION_H


#include "ParserState.h"
#include "../assembler/ProgramState.h"
#include "Node.h"

class NodeArgumentsDeclaration : Node {
private:
    std::string value;
public:
    NodeArgumentsDeclaration *argumentsDeclaration;
    NodeArgumentsDeclaration();
    friend NodeArgumentsDeclaration *parseNodeArgumentsDeclaration(ParserState &state);
    void assembly(ProgramState &state, size_t offset = 8);
};

NodeArgumentsDeclaration *parseNodeArgumentsDeclaration(ParserState &state);

#endif //COMPILER_NODEARGUMENTSDECLARATION_H
