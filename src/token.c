#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "token.h"

token_c* init_token(char* value,int type){
    token_c* token = calloc(1,sizeof (struct TOKEN_STRUCT));
    token->value = value;
    token->type = type;

    return token;
}

static const char* token_type_to_string(int type){
    switch (type) {
        case TOKEN_ID:return "TOKEN_ID";
        case TOKEN_EQUALS:return "TOKEN_EQUALS";
        case TOKEN_LPAREN:return "TOKEN_LPAREN";
        case TOKEN_RPAREN:return "TOKEN_RPAREN";
        case TOKEN_LBRACE:return "TOKEN_LBRACE";
        case TOKEN_RBRACE:return "TOKEN_RBRACE";
        case TOKEN_COLON:return "TOKEN_COLON";
        case TOKEN_COMMA:return "TOKEN_COMMA";
        case TOKEN_LT:return "TOKEN_LT";
        case TOKEN_GT:return "TOKEN_GT";
        case TOKEN_INT:return "TOKEN_INT";
        case TOKEN_SEMI:return "TOKEN_SEMI";
        case TOKEN_MINUS:return "TOKEN_MINUS";
        case TOKEN_PERCENT:return "TOKEN_PERCENT";
        case TOKEN_PIPE:return "TOKEN_PIPE";
        case TOKEN_HASH:return "TOKEN_HASH";
        case TOKEN_ASTRESIK:return "TOKEN_ASTRESIK";
        case TOKEN_DIVISION:return "TOKEN_DIVISION";
        case TOKEN_NOT:return "TOKEN_NOT";
        case TOKEN_DOUBLE_EQUAL:return "TOKEN_DOUBLE_EQUAL";
        case TOKEN_NOT_EQUAL:return "TOKEN_NOT_EQUAL";
        case TOKEN_GT_EQUAL:return "TOKEN_GT_EQUAL";
        case TOKEN_LT_EQUAL:return "TOKEN_LT_EQUAL";
        case TOKEN_PLUS:return "TOKEN_PLUS";
        case TOKEN_DOUBLE_AMPERSAND:return "TOKEN_DOUBLE_AMPERSAND";
        case TOKEN_DOUBLE_PIPE:return "TOKEN_DOUBLE_PIPE";
        case TOKEN_EOF:return "TOKEN_EOF";

    }
    return "dont have ...";
}
char* token_to_string(token_c* token){
    const char* type_str = token_type_to_string(token->type);
    const char*  template = "<type=%s , int_type=%d , value = %s>";
    char* str = calloc(strlen(type_str) + strlen(template) + 8,sizeof(char));
    sprintf(str,template,type_str,token->type,token->value);
    return str;
}
