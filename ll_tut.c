#include <stdio.h>
#include "list.h"

void print_list(list_t *list) {
  list_node_t *curr = list->head;
  printf("[");
  while(curr != NULL) {
    printf("%d", curr->value);
    if(curr->next != NULL) {
      printf(", ");
    }
    curr = curr->next;
  }
  printf("] (%zu elems)\n", list->size);
}

int main(int argc, char *argv[]) {
  list_t *list = ll_new();
  ll_add(list, 1);
  ll_add(list, 2);
  ll_add(list, 3);
  ll_add(list, 4);
  ll_add(list, 5);
  print_list(list);
  ll_delete(list);
  return 0;
}
