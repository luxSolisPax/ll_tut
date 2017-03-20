#include <stdlib.h>

typedef struct list_node_TAG {
  int value;
  struct list_node_TAG *next;
} list_node_t;

typedef struct {
  list_node_t *head;
  size_t size;
} list_t;

/* creates and returns a new empty list */
list_t* ll_new();
/* deletes a linked list previously created by ll_new */
void ll_delete(list_t*);
int ll_get(list_t*, int index);
void ll_set(list_t*, int index, int value);
/* Adds a new element to the end of the list. */
void ll_add(list_t*, int value);
size_t ll_size(list_t*);
