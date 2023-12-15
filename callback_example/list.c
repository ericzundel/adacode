#include <stdlib.h>
#include <assert.h>

/* This file only contains the function definitions and handle definitions
   for the datatypes.
*/
#include "list.h"

/*
  Here are the actual definitions of the data structures used for the list.
  Since it is defined inside this module (.c file), no other code can see
  the definition and accidentally (or on purpose) mess with the data inside.
  This makes it safer to make changes to the list data structures without
  accidentally breaking callers of the list API.
*/

struct list {
  NODE_HND head;
};

struct node {
  NODE_HND next;
  void *user_data;
};

/*************************************************************************
 * List handling functions
 *************************************************************************/

/* Create a new list, return a handle */
LIST_HND list_create() {
  LIST_HND result = malloc(sizeof(struct list));
  result->head = NULL;
  return result;
}

/* Add a node to the head of the list */
NODE_HND list_prepend(LIST_HND list_hnd, void *user_data) {
  assert(list_hnd != NULL);
  
  NODE_HND new_node = (NODE_HND)malloc(sizeof(struct node));
  new_node->user_data = user_data;
  new_node->next = list_hnd->head;
  list_hnd->head = new_node;
  return new_node;
}

/* Free the list. Since the nodes may contain user data, add an option
   to free that data as well for convenience.
*/
void list_free(LIST_HND list_hnd, bool free_user_data) {
  assert(list_hnd != NULL);
  NODE_HND node = list_hnd->head;
  NODE_HND next_node = NULL;
  while(node != NULL) {
    next_node = node->next;
    if (node->user_data) {
      free(node->user_data);
    }
    free(node);
    node = next_node;
  }
  free(list_hnd);
}

void list_walk(LIST_HND list_hnd, LIST_CALLBACK callback, void *context) {
  assert(list_hnd != NULL);
  NODE_HND node = list_hnd->head;
  while (node != NULL) {
    (*callback)(list_hnd, node, context);
    node = node->next;
  }
}

/*************************************************************************
 * Node handling functions
 *************************************************************************/

/* Retrieve the user data associated with the node */
void * node_user_data(NODE_HND node_hnd) {
  return node_hnd->user_data;
}

