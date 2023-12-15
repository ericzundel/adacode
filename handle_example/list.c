#include <stdlib.h>

#include "list.h"


struct list {
  NODE_HND head;
};

struct node {
  NODE_HND *next;
  void *user_data;
};

LIST_HND list_create() {
  LIST_HND result = malloc(sizeof(struct list));
  result->head = NULL;
  return result;
}

NODE_HND list_prepend(LIST_HND list_hnd, void *user_data) {
  NODE_HND new_node = (NODE_HND)malloc(sizeof(struct node));
  new_node->user_data = user_data;
  new_node->next = list_hnd->head;
  list_hnd->head = new_node;
  return new_node;
}

void * node_user_data(NODE_HND node_hnd) {
  return node_hnd->user_data;
}
