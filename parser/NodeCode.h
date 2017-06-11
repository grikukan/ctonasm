
//
// Created by gritukan on 6/10/17.
//

#ifndef COMPILER_NODECODE_H
#define COMPILER_NODECODE_H


#include "Node.h"
#include "NodeExpression.h"
#include "NodeDeclaration.h"
#include "ParserState.h"
#include "../assembler/ProgramState.h"
#include "NodeAssignment.h"
#include "NodeFunctionCall.h"

class NodeCode : Node {
private:
    NodeAssignment *assignment;
    NodeDeclaration *declaration;
    NodeFunctionCall *functionCall;
    NodeCode *code;
public:
    NodeCode();
    friend NodeCode *parseNodeCode(ParserState &state);
    void assembly(ProgramState &state);
};

NodeCode *parseNodeCode(ParserState &state);
#endif //COMPILER_NODECODE_H
