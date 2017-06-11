//
// Created by gritukan on 6/10/17.
//

#ifndef COMPILER_PROGRAMSTATE_H
#define COMPILER_PROGRAMSTATE_H


#include <unordered_map>
#include <string>
#include "Variable.h"

class ProgramState {
private:
    std::unordered_map<std::string, Variable> variables;
    size_t stackOffset;
    std::string program;
public:
    ProgramState();
    void addLine(const std::string &s);
    bool haveVariable(const std::string &name);
    void addVariable(const std::string &name);
    void addFunctionArgument(const std::string &name, size_t offset);
    void newFunction();
    std::string getAddress(const std::string &name);
    std::string getSource();
};


#endif //COMPILER_PROGRAMSTATE_H
