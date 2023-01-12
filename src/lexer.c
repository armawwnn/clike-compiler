#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "include/lexer.h"
#include "include/macros.h"

lexer_c* init_lexer(char * src){
    lexer_c * lexer = calloc(1,sizeof (struct LEXER_STRUCT));
    lexer->src = src;
    lexer->src_size = strlen(src);
    lexer->i = 0;
    lexer->c = src[lexer->i];

    return lexer;
}
void lexer_advance(lexer_c* lexer){
    if(lexer->i < lexer->src_size && lexer->c != '\0'){
        lexer->i +=1;
        lexer->c = lexer->src[lexer->i];
    }
}
char lexer_peck(lexer_c* lexer,int offset){
return lexer->src[MIN(lexer->i + offset, lexer->src_size)];
}
token_c* lexer_advance_with (lexer_c* lexer,token_c* token){
    lexer_advance(lexer);
    return token;
}
token_c * lexer_advance_current(lexer_c* lexer,int type) {
    char * value = calloc(2,sizeof(char));
    value[0] = lexer->c;
    value[1] = '\0';

    token_c * token = init_token(value,type);
    lexer_advance(lexer);
    return token;

}
void lexer_skip_whitespace(lexer_c* lexer){
    while (lexer->c == 13 || lexer->c == 10 || lexer->c == ' ' || lexer->c == '\t')
        lexer_advance(lexer);
}

token_c * lexer_parse_id(lexer_c* lexer){
    char* value = calloc(1,sizeof(char));
    while (isalnum(lexer->c)){
        value = realloc(value, (strlen(value)+2)*sizeof(char));
        strcat(value,(char[]){lexer->c,0});
        lexer_advance(lexer);
    }
    return init_token(value,TOKEN_ID);
}
token_c * lexer_parse_number(lexer_c* lexer){
    char* value = calloc(1,sizeof(char));
    while (isdigit(lexer->c)){
        value = realloc(value, (strlen(value)+2)*sizeof(char));
        strcat(value,(char[]){lexer->c,0});
        lexer_advance(lexer);
    }
    return init_token(value,TOKEN_INT);
}

token_c * lexer_next_token(lexer_c* lexer){
    while (lexer->c !='\0'){

        lexer_skip_whitespace(lexer);
            if(isalpha(lexer->c))
            return lexer_advance_with(lexer,lexer_parse_id(lexer));

            if(isdigit(lexer->c))
                return lexer_advance_with(lexer, lexer_parse_number(lexer));


        switch (lexer->c) {

            case '|': {
                if (lexer_peck(lexer, 1) == '|'){
                    if (lexer_peck(lexer, 1) == '|')
                    lexer_advance(lexer);
                    return lexer_advance_with(lexer, init_token("||", TOKEN_DOUBLE_PIPE));
                }
                return lexer_advance_with(lexer, init_token("|", TOKEN_PIPE));
            }


            case '&': {
                if (lexer_peck(lexer, 1) == '&'){
                    if (lexer_peck(lexer, 1) == '&')
                        lexer_advance(lexer);
                    return lexer_advance_with(lexer, init_token("&&", TOKEN_DOUBLE_AMPERSAND));
                }
                return lexer_advance_with(lexer, init_token("&", TOKEN_AMPERSAND));
            }


            case '=': {
                if (lexer_peck(lexer, 1) == '='){
                    if (lexer_peck(lexer, 1) == '=')
                        lexer_advance(lexer);
                    return lexer_advance_with(lexer, init_token("==", TOKEN_DOUBLE_EQUAL));
                }
                return lexer_advance_with(lexer, init_token("=", TOKEN_EQUALS));
            }


            case '!': {
                    if (lexer_peck(lexer, 1) == '='){
                        lexer_advance(lexer);
                    return lexer_advance_with(lexer, init_token("!=", TOKEN_NOT_EQUAL));
                }
                return lexer_advance_with(lexer, init_token("!", TOKEN_NOT));
            }


            case '<': {
                    if (lexer_peck(lexer, 1) == '='){
                        lexer_advance(lexer);
                    return lexer_advance_with(lexer, init_token(">=", TOKEN_GT_EQUAL));
                }
                return lexer_advance_with(lexer, init_token(">", TOKEN_GT));
            }






            case '(': return lexer_advance_current(lexer, TOKEN_LPAREN);

            case ')': return lexer_advance_current(lexer, TOKEN_RPAREN);

            case '{': return lexer_advance_current(lexer, TOKEN_LBRACE);

            case '}': return lexer_advance_current(lexer, TOKEN_RBRACE);

            case ':': return lexer_advance_current(lexer, TOKEN_COLON);


            case ';': return lexer_advance_current(lexer, TOKEN_SEMI);

            case ',': return lexer_advance_current(lexer, TOKEN_COMMA);

//            case '<': return lexer_advance_current(lexer, TOKEN_LT);
//
//            case '>':
//                return lexer_advance_current(lexer, TOKEN_GT);

            case '#': return lexer_advance_current(lexer, TOKEN_HASH);

            case '+': return lexer_advance_current(lexer, TOKEN_PLUS);

            case '*':
                return lexer_advance_current(lexer, TOKEN_ASTRESIK);
//


            case '-': return lexer_advance_current(lexer, TOKEN_MINUS);

            case '%': return lexer_advance_current(lexer, TOKEN_PERCENT);

            case '/':
                return lexer_advance_current(lexer, TOKEN_DIVISION);

//            case '!':
//                return lexer_advance_current(lexer, TOKEN_NOT);


//            case '>=':
                //

//            case '>=':
                //

        case '\0':
                break;
            default:
                printf("unexpected chaarecter %c \n", lexer->c);
                exit(1);
                break;
        }
    }
    return init_token(0,TOKEN_EOF);
}
