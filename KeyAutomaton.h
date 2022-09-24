#ifndef KEYAUTOMATON_H
#define KEYAUTOMATON_H

#include "Automaton.h"

class KeyAutomaton : public Automaton
{
private:
    std::string keyword;

public:
    KeyAutomaton(TokenType type, std::string keyword) : Automaton(type) { this->keyword = keyword;}  // Call the base constructor

    void S0(const std::string& input);
};

#endif // KEYAUTOMATON_H