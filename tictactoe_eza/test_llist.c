#include "llist.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

llist *alloc_node(void *data) {
	llist *llist_ptr = (llist *)calloc(1, sizeof(struct llist_str));
	llist_ptr->data = data;
}
	
void test_prepend() {
	printf("Testing ll_prepend()...");
	llist *head = alloc_node((void *)1);
	llist *node1 = alloc_node((void *)2);
	ll_prepend(head, node1);

	assert(head->next != NULL);
	assert(head->next->next == NULL);
	assert(head->data == (void *)1);
	assert(head->next->data == (void *)2);

	llist *node2 = alloc_node((void *)3);
	ll_prepend(head, node2);
	assert(head->next->next != NULL);
	assert(head->data == (void *)1);
	assert(head->next->data == (void *)3);
	assert(head->next->next->data == (void *)2);
	assert(head->next->next->next == NULL);

	printf("pass \n");	
	
}

int main(int argc, char*argv[]) {
	test_prepend();
	/* Add more tests here */
}
