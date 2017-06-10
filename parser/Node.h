//
// Created by gritukan on 6/10/17.
//

#ifndef COMPILER_NODE_H
#define COMPILER_NODE_H

enum class NodeType {PROGRAM, DECLARATION, EXPRESSION, ASSIGNMENT};

class Node {
protected:
    NodeType type;
};


#endif //COMPILER_NODE_H
