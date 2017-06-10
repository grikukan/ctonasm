//
// Created by gritukan on 6/10/17.
//

#ifndef COMPILER_ASSEMBLER_H
#define COMPILER_ASSEMBLER_H

#include <string>
#include "../parser/Node.h"

class Assembler {
public:
    std::string assembly(Node *node);

};


#endif //COMPILER_ASSEMBLER_H
