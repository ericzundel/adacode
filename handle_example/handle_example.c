#include <stdlib.h>
#include <stdio.h>

#include "list.h"

struct mydata {
  int value;
};


void test_user_context(NODE_HND node) {
  struct mydata *data_ptr =
    (struct mydata *)node_user_data(node);
  printf("User context of this node is: %d", data_ptr->value);
    
}

int main(int argc, char *argv[]) {
  LIST_HND mylist_hnd = list_create();
  struct mydata *mydata_ptr = malloc(sizeof(struct mydata));
  mydata_ptr->value = 1;
  
  NODE_HND new_node = list_prepend(mylist_hnd, (void *)mydata_ptr);

  test_user_context(new_node);
}
