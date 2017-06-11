//
// Created by gritukan on 6/10/17.
//

#ifndef COMPILER_VARIABLE_H
#define COMPILER_VARIABLE_H


#include <cstddef>

class Variable {
public:
    size_t address;
    Variable() : address(0) {};
    Variable(int32_t address) : address(address) {};
};


#endif //COMPILER_VARIABLE_H
