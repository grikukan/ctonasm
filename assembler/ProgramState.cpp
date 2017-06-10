//
// Created by gritukan on 6/10/17.
//

#include "ProgramState.h"

ProgramState::ProgramState() {
    addLine("section .text");
    addLine("global main");
    addLine("main:");
    addLine("push ebp");
    addLine("mov ebp, esp");
    stackOffset = 0;
}
void ProgramState::addLine(const std::string &s) {
    program += "\n";
    program += s;
}

bool ProgramState::haveVariable(const std::string &name) {
    return variables.count(name);
}

void ProgramState::addVariable(const std::string &name) {
    addLine("sub esp, 4");
    stackOffset += 4;
    variables[name] = Variable(stackOffset);
}

size_t ProgramState::getAddress(const std::string &name) {
    return variables.at(name).address;
}

std::string ProgramState::getSource() {
    addLine("xor eax, eax");
    addLine("leave");
    addLine("ret");
    return program;
}
