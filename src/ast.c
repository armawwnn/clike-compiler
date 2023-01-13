#include "include/AST.h"
#include <stdlib.h>

AST_c* init_ast(int type)
{
    AST_c* ast = calloc(1, sizeof(struct AST_STRUCT));
    ast->type = type;

    if (type == AST_COMPOUND)
        ast->children = init_list(sizeof(struct AST_STRUCT*));

    return ast;
}

