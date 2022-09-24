#include "CommentAutomaton.h"

void CommentAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void CommentAutomaton::S1(const std::string& input) {   //comment or block comment?
    if(index >= input.size())
        return;
    else
    {
        if (input[index] == '|') {
            inputRead++;
            index++;
            S3(input);
        }
        else
        {
            inputRead++;
            index++;
            S2(input);  // for comment
        }
    }
}

void CommentAutomaton::S2(const std::string& input) {    //handles a comment, but not a block comment
    if(index >= input.size())
        return;
    else{
        if (input[index] != '\n') {
            inputRead++;
            index++;
            S2(input);
        }
        else
            return;
    }
}

void CommentAutomaton::S3(const std::string& input) {   //comment or block comment?
    if(index >= input.size())
        return;
    else
    {
        if (input[index] == '|') {
            inputRead++;
            index++;
            S4(input);  //signals the block comment is ending
        }
        else
        {
            if (input[index] == '\n')            //there can be multiple lines in a block comment
                newLines++;

            inputRead++;
            index++;
            S3(input);  // continue building the block comment
        }
    }
}

void CommentAutomaton::S4(const std::string& input) {   //comment or block comment?
    if(index >= input.size())
        return;
    else
    {
        if (input[index] == '#') {
            inputRead++;
            index++;
            return;
        }
        else
        {
            return; //this is an error/ an undefined one. need to write the code for this
            // if it is not another # does it go back to the block comment one though? food for thought tbh
        }
    }
}