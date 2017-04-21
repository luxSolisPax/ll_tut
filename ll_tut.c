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
  
  //ll_get test
  printf("index (0): ");
  printf("%Iu", ll_get(list, 0));
  printf("\n");
  
  printf("index (1): ");
  printf("%Iu", ll_get(list, 1));
  printf("\n");
  
  printf("index (2): ");
  printf("%Iu", ll_get(list, 2));
  printf("\n");
  
  printf("index (3): ");
  printf("%Iu", ll_get(list, 3));
  printf("\n");
  
  printf("index (4): ");
  printf("%Iu", ll_get(list, 4));
  printf("\n");
  
  //Out of bounds
  printf("index (5): ");
  printf("%Iu", ll_get(list, 5));
  printf("\n");  
  
  //ll_set test
  printf("preSet: ");
  printf("%Iu \n", ll_get(list, 0));
  ll_set(list, 0, 50);
  printf("postSet: ");
  printf("%Iu \n", ll_get(list, 0));
  
  
  //ll_remove test
  print_list(list);
  ll_remove(list, 1);
  print_list(list);
  
  //ll_insert test
  ll_insert(list, 4, 900);
  print_list(list);
  
  ll_delete(list);
  return 0;
}
