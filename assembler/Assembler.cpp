//
// Created by gritukan on 6/10/17.
//

#include "Assembler.h"

std::string Assembler::assembly(NodeProgram *node) {
    ProgramState state;
    node->assembly(state);
    return state.getSource();
}