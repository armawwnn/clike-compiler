#ifndef CLIKE_LEXER_H
#define CLIKE_LEXER_H
#include "token.h"
#include <stdio.h>

typedef struct LEXER_STRUCT{
    char * src;
    size_t src_size;
    char c;
    unsigned int i;
} lexer_c;
lexer_c* init_lexer(char * src);

token_c* lexer_advance_with(lexer_c* lexer,token_c* token);
token_c* lexer_advance_current(lexer_c* lexer,int type);
void lexer_advance(lexer_c* lexer);
char lexer_peack(lexer_c* lexerint,int offset);
token_c* lexer_next_token(lexer_c* lexer);
void lexer_skip_whitespace(lexer_c* lexer);
token_c* lexer_parse_id(lexer_c* lexer);
token_c* lexer_parse_number(lexer_c* lexer);
token_c* lexer_next_token(lexer_c* lexer);

#endif