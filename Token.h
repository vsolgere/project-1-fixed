#ifndef TOKEN_H
#define TOKEN_H
#include <string>

enum class TokenType {
    COLON,
    COLON_DASH,
    PERIOD,
    COMMA,
    Q_MARK,
    EX_POINT,
    LEFT_PAREN,
    RIGHT_PAREN,
    QUERIES,
    SCHEMES,
    RULES,
    FACTS,
    MULTIPLY,
    ADD,
    STRING,
    COMMENT,
    ITS_EOF,
    ID,
    UNDEFINED
};

class Token
{
private:
    // TODO: add member variables for information needed by Token
    TokenType type;
    std::string description;
    int lineNum;

public:
    Token(TokenType type, std::string description, int line);
    std::string toString();
    std::string tokenExplain(TokenType type);
};

#endif // TOKEN_H
