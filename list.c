#include <stdlib.h>
#include "list.h"

list_node_t *seek_tail(list_node_t *node);

list_t *ll_new() {
  list_t *ret = (list_t *) malloc(sizeof(list_t));
  ret->head = (void *)0;
  ret->size = 0;
  return ret; }

// O(n)
void ll_delete(list_t *list) {
  list_node_t *head = list->head;
  while (head != NULL) {
    list_node_t *next = head->next;
    free(head);
    head = next;
  }
  free(list);
}

/* O(n) */
void ll_add(list_t *list, int value) {
  list_node_t *new_node = (list_node_t*) malloc(sizeof(list_node_t));
  new_node->value = value;
  new_node->next = NULL;
  list->size++;
  if (list->head == NULL) {
    list->head = new_node;
  } else {
    seek_tail(list->head)->next = new_node;
  }
}

list_node_t *seek_tail(list_node_t *node) {
  if (node->next == NULL) {
    return node;
  } else {
    return seek_tail(node->next);
  }
}
