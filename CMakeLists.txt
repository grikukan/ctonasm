cmake_minimum_required(VERSION 3.2.2)
project(compiler)

set(CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp tokenizer/Token.cpp tokenizer/Token.h tokenizer/Tokenizer.cpp tokenizer/Tokenizer.h parser/Node.cpp parser/Node.h parser/Parser.cpp parser/Parser.h assembler/Assembler.cpp assembler/Assembler.h parser/ParserState.cpp parser/ParserState.h parser/NodeCode.cpp parser/NodeCode.h parser/NodeDeclaration.cpp parser/NodeDeclaration.h parser/NodeExpression.cpp parser/NodeExpression.h parser/NodeAssignment.cpp parser/NodeAssignment.h assembler/Variable.cpp assembler/Variable.h assembler/ProgramState.cpp assembler/ProgramState.h parser/NodeArgumentsList.cpp parser/NodeArgumentsList.h parser/NodeFunctionCall.cpp parser/NodeFunctionCall.h parser/NodeFunctionDeclaration.cpp parser/NodeFunctionDeclaration.h parser/NodeProgram.cpp parser/NodeProgram.h parser/NodeUnaryExpression.cpp parser/NodeUnaryExpression.h parser/NodeReturn.cpp parser/NodeReturn.h parser/NodeArgumentsDeclaration.cpp parser/NodeArgumentsDeclaration.h)
add_executable(compiler ${SOURCE_FILES})