#ifndef CLIKE_AST_H
#define CLIKE_AST_H
#include "list.h"

typedef struct AST_STRUCT
{
    enum
    {
        AST_COMPOUND,
        AST_FUNCTION_DDEFENISION,
        AST_DEFENITION_TYPE,
        AST_VARIABLE,
        AST_STATMENT,
        AST_NOOP,
    } type;

  list_c* children;
} AST_c;

AST_c* init_ast(int type);
#endif
