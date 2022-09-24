#include "KeyAutomaton.h"

void KeyAutomaton::S0(const std::string& input) {
    if (input.substr(0,keyword.size()) == keyword) {
        inputRead = keyword.size();
    }
    else {
        Serr();
    }
}