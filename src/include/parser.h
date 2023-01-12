#ifndef CLIKE_PARSER_H
#define CLIKE_PARSER_H
#include "lexer.h"
#include "AST.h"

typedef struct PARSER_STRUCT
{
    lexer_c* lexer;
    token_c* token;

} parser_c;

parser_c* init_parser(lexer_c* lexer);
token_c* parser_advance(parser_c* parser);
AST_c* parser_parse(parser_c* parser);


#endif
