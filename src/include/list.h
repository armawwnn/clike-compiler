#ifndef CLIKE_LIST_H
#define CLIKE_LIST_H
#include <stdlib.h>
#include <stdio.h>
typedef struct LIST_STRUCT
{
    void** items;
    size_t size;
    size_t item_size;

} list_c;

list_c* init_list(size_t item_size);

void list_push(list_c* list,void* item);

#endif
