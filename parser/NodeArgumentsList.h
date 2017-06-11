//
// Created by gritukan on 6/11/17.
//

#ifndef COMPILER_NODEARGUMENTSLIST_H
#define COMPILER_NODEARGUMENTSLIST_H


#include "NodeExpression.h"

class NodeArgumentsList : Node {
private:
    NodeExpression *expression;
    NodeArgumentsList *arguments;
public:
    NodeArgumentsList();
    friend NodeArgumentsList *parseNodeArgumentsList(ParserState &state);
    size_t getSize() const;
    void assembly(ProgramState &state, size_t offset = 0);
};

NodeArgumentsList *parseNodeArgumentsList(ParserState &state);

#endif //COMPILER_NODEARGUMENTSLIST_H
