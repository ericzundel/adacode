#include "llist.h"

void ll_prepend(llist *list, llist*node_to_add) {
	llist *old = list->next;
	list->next = node_to_add;
	node_to_add->next = old;
}
