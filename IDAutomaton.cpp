#include "IDAutomaton.h"
#include <cctype>

void IDAutomaton::S0(const std::string& input) {
    if (isalpha(input[index])) {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void IDAutomaton::S1(const std::string& input) {
    if (index >= input.size()) { return; } //IF END OF FILE
    else if (isalnum(input.at(index))) {
        inputRead++;
        index++;
        S1(input);
    }
    else { return; }
}