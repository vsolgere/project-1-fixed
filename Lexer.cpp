#include "Lexer.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "StringAutomaton.h"
#include "CommentAutomaton.h"
#include "IDAutomaton.h"
#include "KeyAutomaton.h"
#include <cctype>
#include <sstream>

Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    // TODO: need to clean up the memory in `automata` and `tokens`
}

void Lexer::CreateAutomata() {
    automata.push_back(new KeyAutomaton(TokenType::PERIOD, "."));
    automata.push_back(new KeyAutomaton(TokenType::COMMA, ","));
    automata.push_back(new KeyAutomaton(TokenType::Q_MARK, "?"));
    automata.push_back(new KeyAutomaton(TokenType::EX_POINT, "!"));
    automata.push_back(new KeyAutomaton(TokenType::ADD, "+"));
    automata.push_back(new KeyAutomaton(TokenType::MULTIPLY, "*"));
    automata.push_back(new KeyAutomaton(TokenType::LEFT_PAREN, "("));
    automata.push_back(new KeyAutomaton(TokenType::RIGHT_PAREN, ")"));
    automata.push_back(new KeyAutomaton(TokenType::QUERIES, "Queries"));
    automata.push_back(new KeyAutomaton(TokenType::SCHEMES, "Schemes"));
    automata.push_back(new KeyAutomaton(TokenType::RULES, "Rules"));
    automata.push_back(new KeyAutomaton(TokenType::FACTS, "Facts"));
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new StringAutomaton());
    automata.push_back(new CommentAutomaton());
    automata.push_back(new IDAutomaton());
    // TODO: Add the other needed automata here
}

void Lexer::Run(std::string& input) {
    //set lineNumber to 1
    int lineNumber = 1;

   while (input.size() > 0) {                                         // While there are more characters to tokenize
        //set maxRead to 0
        int maxRead = 0;

       Automaton* maxAutomaton = automata[0];                                // set maxAutomaton to the first automaton in automata

        // TODO: you need to handle whitespace inbetween tokens

        while( input.size() != 0 && isspace(input.at(0))) {

            if(input.at(0) == '\n')
            {
                lineNumber++;
            }

            input.erase(0,1);
        }


        // Here is the "Parallel" part of the algorithm
        //   Each automaton runs with the same input
        for(unsigned int x = 0; x < automata.size(); x++) {

            int inputRead = automata[x]->Start(input);

            if (inputRead > maxRead) {
                //set maxRead to inputRead
                maxRead = inputRead;
                //set maxAutomaton to automaton
                maxAutomaton = automata[x];
            }
        }
        if (maxRead > 0) {                                               // Here is the "Max" part of the algorithm

            Token* newToken = maxAutomaton->CreateToken(input.substr(0,maxRead),lineNumber);
            lineNumber += maxAutomaton->NewLinesRead();     //increment lineNumber by maxAutomaton.NewLinesRead()
            tokens.push_back(newToken);       //add newToken to collection of all tokens

        }
        else {
            maxRead = 1;     //set maxRead to 1
            Automaton* tempAuto = new KeyAutomaton(TokenType::UNDEFINED,input.substr(0,maxRead));
            Token* undefToken = tempAuto->CreateToken(input.substr(0,maxRead),lineNumber);
            tokens.push_back(undefToken);    //add undefined thing to collection of all tokens
                //set newToken to a  new undefined Token
                //(with first character of input)
            delete tempAuto;    //clear memory bc main one doesnt fix this apparently
        }

        input.erase(0,maxRead);


        //some of my whitespace wasnt deleting at the end and was turning into an undef so yeah this
       while( input.size() != 0 && isspace(input.at(0))) {

           if(input.at(0) == '\n')
           {
               lineNumber++;
           }

           input.erase(0,1);
       }

    }
    //add end of file token to all tokens
    lineNumber++;
    Token* endToken = new Token(TokenType::ITS_EOF,"",lineNumber);
    tokens.push_back(endToken);
}

std::string Lexer::printTokens(){
    std::stringstream tokenOutput;
    for(int i = 0; i < tokens.size(); i++)
    {
        tokenOutput << tokens.at(i)->toString();
    }

    return tokenOutput.str();
}
