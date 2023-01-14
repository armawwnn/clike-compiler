#ifndef CLIKE_TOKEN_H
#define CLIKE_TOKEN_H
typedef struct TOKEN_STRUCT
{
char * value;
enum{
    TOKEN_ID,
    TOKEN_EQUALS,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_LBRACE,
    TOKEN_RBRACE,
    TOKEN_COLON,
    TOKEN_COMMA,
    TOKEN_LT,
    TOKEN_GT,
    TOKEN_INT,
    TOKEN_SEMI,
    TOKEN_HASH,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_PERCENT,
    TOKEN_PIPE,
    TOKEN_ASTRESIK,
    TOKEN_DOUBLE_AMPERSAND,
    TOKEN_AMPERSAND,
    TOKEN_DOUBLE_PIPE,
    TOKEN_DIVISION,
    TOKEN_NOT,
    TOKEN_DOUBLE_EQUAL,
    TOKEN_NOT_EQUAL,
    TOKEN_GT_EQUAL,
    TOKEN_LT_EQUAL,
    TOKEN_EOF,
} type;
}token_c;
token_c* init_token(char * value,int type);

char* token_to_string(token_c* token);
#endif
