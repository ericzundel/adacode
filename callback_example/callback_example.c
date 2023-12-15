#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/* Include definitions for the public API for list */
#include "list.h"

/* A data structure to pass back to the callback function */
struct mycontext {
  char message[80];
  int count;
};

void my_callback(LIST_HND list_hnd, NODE_HND node_hnd, void *ctx) {
  struct mycontext *myctx = (struct mycontext*)ctx;
  
  myctx->count++;
  printf("Message: %s Count: %d\n", myctx->message, myctx->count);
}

void test_list_walk() {
  /* Create a new list */
  LIST_HND mylist_hnd = list_create();

  /* Add some nodes to the list */
  list_prepend(mylist_hnd, (void *)1);
  list_prepend(mylist_hnd, (void *)2);
  list_prepend(mylist_hnd, (void *)3);

  struct mycontext *ctx = malloc(sizeof(struct mycontext));
  ctx->count = 0;
  
  /* walk the list */
  sprintf(ctx->message, "Hello");
  list_walk(mylist_hnd, &my_callback, ctx);
  
  sprintf(ctx->message, "Goodbye");
  list_walk(mylist_hnd, &my_callback, ctx);

  assert(ctx->count == 6);
  
  /* cleanup the data created by this test */
  list_free(mylist_hnd, true);
  free(mylist_hnd);
}

int main(int argc, char *argv[]) {
  test_list_walk();
  printf("All tests passed\n");
}
