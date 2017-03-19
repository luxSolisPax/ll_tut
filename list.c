#include <inttypes.h>
#include "list.h"

list_t* ll_new();
void ll_delete(list_t*);
int ll_get(list_t*, int index);
void ll_set(list_t*, int index, int value);
/* Adds a new element to the end of the list. */
void ll_add(list_t*, int value);
size_t ll_size(list_t*);
