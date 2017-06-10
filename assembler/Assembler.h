//
// Created by gritukan on 6/10/17.
//

#ifndef COMPILER_ASSEMBLER_H
#define COMPILER_ASSEMBLER_H

#include <string>
#include "../parser/Node.h"
#include "../parser/NodeProgram.h"

class Assembler {
public:
    std::string assembly(NodeProgram *node);

};


#endif //COMPILER_ASSEMBLER_H
