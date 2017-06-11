//
// Created by gritukan on 6/10/17.
//

#include "ProgramState.h"

ProgramState::ProgramState() {
    addLine("section .data");
    addLine("PRINT_INT_STR db `%d\\n`, 0");
    addLine("section .text");
    addLine("extern printf");
    addLine("PRINT_INT:");
    addLine("push ebp");
    addLine("mov ebp, esp");
    addLine("sub esp, 16");
    addLine("and esp, -16");
    addLine("mov dword[esp], PRINT_INT_STR");
    addLine("mov eax, dword[ebp + 8]");
    addLine("mov dword[esp + 4], eax");
    addLine("call printf");
    addLine("leave");
    addLine("ret");
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
    stackOffset -= 4;
    variables[name] = Variable(stackOffset);
}

void ProgramState::addFunctionArgument(const std::string &name, size_t offset) {
    variables[name] = Variable(offset);
}
void ProgramState::newFunction() {
    stackOffset = 0;
    variables.clear();
}

std::string ProgramState::getAddress(const std::string &name) {
    int32_t address = variables[name].address;
    if (address >= 0) {
        return "[ebp + " + std::to_string(address) + "]";
    } else {
        return "[ebp - " + std::to_string(-address) + "]";
    }
}

std::string ProgramState::getSource() {
    addLine("xor eax, eax");
    addLine("leave");
    addLine("ret");
    return program;
}
