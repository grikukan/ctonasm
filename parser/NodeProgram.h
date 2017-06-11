//
// Created by gritukan on 6/11/17.
//

#ifndef COMPILER_NODEPROGRAM_H
#define COMPILER_NODEPROGRAM_H


#include "NodeFunctionDeclaration.h"
#include "ParserState.h"
#include "../assembler/ProgramState.h"

class NodeProgram : Node {
private:
    NodeFunctionDeclaration *function;
    NodeProgram *program;
public:
    NodeProgram();
    friend NodeProgram *parseNodeProgram(ParserState &state);
    void assembly(ProgramState &state);
};

NodeProgram *parseNodeProgram(ParserState &state);

#endif //COMPILER_NODEPROGRAM_H
