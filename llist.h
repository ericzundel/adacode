/* Use this #define to keep from causing problems if a header file is included twice */
#ifndef LLIST_H
#define LLIST_H

typedef struct llist_str {
	void * data;
	struct llist_str *next;
} llist;

void ll_prepend(llist *head, llist *node);

#endif
