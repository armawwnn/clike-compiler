#ifndef CLIKE_AST_H
#define CLIKE_AST_H

typedef struct AST_STRUCT
{
    enum
    {

    } type;

} AST_T;

AST_T* init_ast(int type);
#endif
