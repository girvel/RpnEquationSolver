cmake_minimum_required(VERSION 3.12)
project(RpnEquationSolver)

set(CMAKE_CXX_STANDARD 17)

add_executable(RpnEquationSolver main.cpp Modeling/Evaluable.cpp Modeling/Evaluable.h Parsing/Parser.cpp Parsing/Parser.h Modeling/Equation.cpp Modeling/Equation.h Modeling/Constant.cpp Modeling/Constant.h Modeling/Operations/Addition.h Modeling/Operation.cpp Modeling/Operation.h Parsing/Operator.cpp Parsing/Operator.h Modeling/Operations/AdditiveInversion.cpp Modeling/Operations/AdditiveInversion.h Modeling/Operations/Multiplication.cpp Modeling/Operations/Multiplication.h Modeling/Operations/MultiplicativeInversion.cpp Modeling/Operations/MultiplicativeInversion.h)