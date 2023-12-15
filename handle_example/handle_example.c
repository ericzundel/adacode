#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/* Include definitions for the public API for list */
#include "list.h"

/* A data structure to store in each node of the list */
struct mydata {
  int value;
};


/* test retrieving user context data from a node */
void test_node_user_context() {
  /* Create a new list */
  LIST_HND mylist_hnd = list_create();

  /* Create some data to associate with the node */
  struct mydata *mydata_ptr = malloc(sizeof(struct mydata));
  mydata_ptr->value = 1;

  /* Add a new node to the list */
  NODE_HND new_node = list_prepend(mylist_hnd, (void *)mydata_ptr);

  
  /* Test retrieving the dataThe user context is defined as void * so you can store any value in
     it. Cast it back to the datastructure we passed in.
  */
  struct mydata *retrieved_data_ptr =
    (struct mydata *)node_user_data(new_node);
  printf("User context of this node is: %d", retrieved_data_ptr->value);
  
  /* assert() will crash the program if the expression is false */
  assert(1 == retrieved_data_ptr->value);

  /* cleanup the data created by this test */
  list_free(mylist_hnd, true);
}

int main(int argc, char *argv[]) {
  test_node_user_context();
}
