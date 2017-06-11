//
// Created by gritukan on 6/10/17.
//

#ifndef COMPILER_NODE_H
#define COMPILER_NODE_H

enum class NodeType {PROGRAM, DECLARATION, EXPRESSION, ASSIGNMENT, ARGUMENTS_LIST, FUNCTION_CALL, FUNCTION_DECLARATION,
                    CODE, UNARY_EXRESSION, NODE_RETURN, ARGUMENTS_DECLARATION};

class NodeAssignment;
class NodeArgumentsList;
class NodeCode;
class NodeDeclaration;
class NodeExpression;
class NodeFunctionCall;
class NodeFunctionDeclaration;
class NodeProgram;
class NodeUnaryExpression;
class NodeReturn;
class NodeArumentsDeclaration;

class Node {
protected:
    NodeType type;
};


#endif //COMPILER_NODE_H
