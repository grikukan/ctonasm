//
// Created by gritukan on 6/11/17.
//

#ifndef COMPILER_NODEFUNCTIONCALL_H
#define COMPILER_NODEFUNCTIONCALL_H

#include <string>
#include "NodeArgumentsList.h"

class NodeFunctionCall {
private:
    std::string value;
    NodeArgumentsList *argumentsList;
public:
    NodeFunctionCall();
    friend NodeFunctionCall *parseNodeFunctionCall(ParserState &state);
    void assembly(ProgramState &state);
};

NodeFunctionCall *parseNodeFunctionCall(ParserState &state);

#endif //COMPILER_NODEFUNCTIONCALL_H
