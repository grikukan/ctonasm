cmake_minimum_required(VERSION 3.7)
project(compiler)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp tokenizer/Token.cpp tokenizer/Token.h tokenizer/Tokenizer.cpp tokenizer/Tokenizer.h parser/Node.cpp parser/Node.h parser/Parser.cpp parser/Parser.h assembler/Assembler.cpp assembler/Assembler.h)
add_executable(compiler ${SOURCE_FILES})