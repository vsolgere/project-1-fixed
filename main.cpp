#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cctype>

#include "Lexer.h"

int main(int argc, char** argv) {

    Lexer* lexer = new Lexer();

    std::cout << "Input file: " << argv[1] << std::endl;
    std::ifstream input;
    input.open(argv[1]);
    std::ostringstream out;
    out << input.rdbuf();
    std::string inputString = out.str();


    std::cout << inputString;


    //std::string testString = "\nQueries:\n"
                             "   marriedTo ('Bea' , 'Zed')?\n"
                             "\n"
                             "Rules:\n"
                             "   marriedTo( X,Y ) :- marriedTo(Y,X) .\n";

    //testString = inputString;

    //lexer->Run(testString);

    lexer->Run(inputString);
    std::cout << lexer->printTokens();

    // TODO

    //delete lexer;

    return 0;
}
