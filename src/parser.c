#include "include/parser.h"
#include "include/types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


parser_c* init_parser(lexer_c* lexer)
{
    parser_c* parser = calloc(1,sizeof(struct PARSER_STRUCT));
    parser->lexer = lexer;
    parser->token = lexer_next_token(lexer);

    return parser;
}


token_c* parser_eat(parser_c* parser,int type)
{
    if(parser->token->type != type){
        printf("[parser]: unexpexted token : `%s` , was expecting: `%s` \n ",token_to_string(parser->token),token_type_to_string(type));
        exit(1);
    }
    parser->token = lexer_next_token(parser->lexer);
    return parser->token;
}
AST_c* parser_parse(parser_c* parser)
{
    return parser_parse_compound(parser);
}
AST_c* parser_parse_id(parser_c* parser)
{
    char* value = calloc(strlen(parser->token->value)+1,sizeof(char));
    strcpy(value,parser->token->value);
    parser_eat(parser,TOKEN_ID);

       //parse var
   AST_c* ast = init_ast(AST_VARIABLE);
   ast->name = value;

   if (parser->token->type == TOKEN_ID)
   {
       parser_eat(parser,TOKEN_ID);

       while(parser->token->type == TOKEN_ID)
       {
       ast->data_type = typename_to_int(parser->token->value);
       parser_eat(parser,TOKEN_ID);
       }

   }


   if (parser->token->type == TOKEN_EQUALS) 
   {
       // parse ==
       parser_eat(parser,TOKEN_EQUALS);
       AST_c* ast = init_ast(AST_ASSIGNMENT);
       ast->name = value;



       ast->value = parser_parse_exp(parser);
       return ast;
   }

   return ast;
}



AST_c* parser_parse_list(parser_c* parser)
{
    parser_eat(parser,TOKEN_LPAREN);
    AST_c* ast = init_ast(AST_COMPOUND);


    list_push(ast->children,parser_parse_exp(parser));

    while(parser->token->type == TOKEN_COMMA)
    {
        parser_eat(parser,TOKEN_COMMA);
        list_push(ast->children,parser_parse_exp(parser));
    }

    parser_eat(parser,TOKEN_RPAREN);

 if (parser->token->type == TOKEN_ID)
   {
       parser_eat(parser,TOKEN_ID);

       while(parser->token->type == TOKEN_ID)
       {
       ast->data_type = typename_to_int(parser->token->value);
       parser_eat(parser,TOKEN_ID);
       }

   }


    return ast;

}
AST_c* parser_parse_exp(parser_c* parser)
{
    switch (parser->token->type)
    {
        case TOKEN_ID : return parser_parse_id(parser);
        case TOKEN_LPAREN : return parser_parse_list(parser);
        default:{ printf("[parser]: unexpected token `%s`\n",token_to_string(parser->token)); exit(1);};
    }
}

AST_c* parser_parse_compound(parser_c* parser)
{
    AST_c* compound = init_ast(AST_COMPOUND);
    while(parser->token->type != TOKEN_EOF)
    {
        list_push(compound->children,parser_parse_exp(parser));
    }
    return compound;

}
