cmake_minimum_required(VERSION 3.7)
project(compiler)

set(CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp tokenizer/Token.cpp tokenizer/Token.h tokenizer/Tokenizer.cpp tokenizer/Tokenizer.h parser/Node.cpp parser/Node.h parser/Parser.cpp parser/Parser.h assembler/Assembler.cpp assembler/Assembler.h parser/ParserState.cpp parser/ParserState.h parser/NodeProgram.cpp parser/NodeProgram.h parser/NodeDeclaration.cpp parser/NodeDeclaration.h parser/NodeExpression.cpp parser/NodeExpression.h parser/NodeAssignment.cpp parser/NodeAssignment.h)
add_executable(compiler ${SOURCE_FILES})