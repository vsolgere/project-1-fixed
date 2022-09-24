#include "Token.h"

Token::Token(TokenType type, std::string description, int line) {
    this->type = type;
    this->description = description;
    this->lineNum = line;
}

std::string Token::tokenExplain(TokenType type){
    switch(type) {
        case TokenType::COLON:
            return "COLON";
            break;
        case TokenType::COLON_DASH:
            return "COLON_DASH";
            break;
        case TokenType::PERIOD:
            return "PERIOD";
            break;
        case TokenType::COMMA:
            return "COMMA";
            break;
        case TokenType::Q_MARK:
            return "Q_MARK";
            break;
        case TokenType::EX_POINT:
            return "EX_POINT";
            break;
        case TokenType::LEFT_PAREN:
            return "LEFT_PAREN";
            break;
        case TokenType::RIGHT_PAREN:
            return "RIGHT_PAREN";
            break;
        case TokenType::QUERIES:
            return "QUERIES";
            break;
        case TokenType::SCHEMES:
            return "SCHEMES";
            break;
        case TokenType::RULES:
            return "RULES";
            break;
        case TokenType::FACTS:
            return "FACTS";
            break;
        case TokenType::MULTIPLY:
            return "MULTIPLY";
            break;
        case TokenType::ADD:
            return "ADD";
            break;
        case TokenType::UNDEFINED:
            return "UNDEFINED";
            break;
        case TokenType::ID:
            return "ID";
            break;
        case TokenType::STRING:
            return "STRING";
            break;
        case TokenType::COMMENT:
            return "COMMENT";
            break;
        case TokenType::ITS_EOF:
            return "EOF";
            break;
    }
        return "Something went wrong";
}

std::string Token::toString() {
        return "(" + tokenExplain(type) + ",\"" + this->description + "\"," + std::to_string(lineNum) + ")";
}

