#include "clike.h"
#include "lexer.h"
#include <stdlib.h>
#include <stdio.h>
#include "io.h"

void clike_compile(char*src){
    lexer_c * lexer = init_lexer(src);
    token_c * tok = 0;
    while ((tok = lexer_next_token(lexer))->type != TOKEN_EOF){
        printf("%s\n", token_to_string(tok));
    }if(tok->type == TOKEN_EOF){
        exit(0);
    }
}
void clike_compile_file(const char* filename){
    char* src = clike_read_file(filename);
    clike_compile(src);
    free(src);
}