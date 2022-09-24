cmake_minimum_required(VERSION 3.23)
project(Project_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project_1 main.cpp
        Automaton.h
        ColonAutomaton.cpp
        ColonAutomaton.h
        ColonDashAutomaton.cpp
        ColonDashAutomaton.h
        Lexer.cpp
        Lexer.h
        Token.cpp
        Token.h
        StringAutomaton.cpp
        StringAutomaton.h
        CommentAutomaton.h
        CommentAutomaton.cpp
        IDAutomaton.cpp
        IDAutomaton.h
        KeyAutomaton.cpp
        KeyAutomaton.h
        )
