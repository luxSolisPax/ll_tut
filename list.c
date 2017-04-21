#include <stdlib.h>
#include "list.h"

list_node_t *seek_tail(list_node_t *node);

list_t *ll_new() {
  list_t *ret = (list_t *) malloc(sizeof(list_t));
  ret->head = 0;
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

size_t ll_size(list_t *list) {
    return list->size;
}

/* get a value in the list by index */
int ll_get(list_t *list, int index){    
    list_node_t *get_node = list->head;
    
    if(index >= ll_size(list)){
        //error handling?
        printf(" [!! ll_get: Index %Iu is out of bounds !!] ", index);
        return -1;
    } else {
        while (index > 0) {
            get_node = get_node->next;
            index--;
        }
        return get_node->value;
    }
}

/* set a value in the list by index */
void ll_set(list_t *list, int index, int value) {
    list_node_t *set_node = list->head;

    if (index >= ll_size(list)) {
        //error handling?
        printf(" [!! ll_get: Index %Iu is out of bounds !!] ", index);
    } else {
        while (index > 0) {
            set_node = set_node->next;
            index--;
        }
        set_node->value = value;
    }
}

void ll_remove(list_t *list, int index){
    list_node_t *remove_node = list->head;
    list_node_t *previous_node = NULL;
    
    if(index >= ll_size(list)){
        printf(" [!! ll_get: Index %Iu is out of bounds !!] ", index);
    } else {
        list->size--;
        if(index == 0){
            list->head = remove_node->next;
        } else {
            while (index > 0) {
                previous_node = remove_node;
                remove_node = remove_node->next;
                index--;
            }
            previous_node->next = remove_node->next;            
        }

    }
}

void ll_insert(list_t *list, int index, int value) {
    list_node_t *new_node = (list_node_t*) malloc(sizeof (list_node_t));
    new_node->value = value;
    new_node->next = NULL;
    
    list_node_t *insert_node = list->head;
    if(index >= ll_size(list)){
        printf(" [!! ll_get: Index %Iu is out of bounds !!] ", index);
    } else {
        while (index > 0) {
            insert_node = insert_node->next;
            index--;
        }
        new_node->next = insert_node->next;
        insert_node->next = new_node;
        list->size++;
    }

}