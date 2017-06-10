
//
// Created by gritukan on 6/10/17.
//

#ifndef COMPILER_NODEPROGRAM_H
#define COMPILER_NODEPROGRAM_H


#include "Node.h"
#include "NodeExpression.h"
#include "NodeDeclaration.h"
#include "ParserState.h"
#include "../assembler/ProgramState.h"

class NodeProgram : Node {
private:
    NodeExpression *expression;
    NodeDeclaration *declaration;
    NodeProgram *program;
public:
    NodeProgram();
    friend NodeProgram *parseNodeProgram(ParserState &state);
    void assembly(ProgramState &state);
};

NodeProgram *parseNodeProgram(ParserState &state);
#endif //COMPILER_NODEPROGRAM_H
