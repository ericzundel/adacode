#ifndef LIST_H
#define LIST_H

/* List Handle used to pass data back and forth to the List API with info
   about the list.

   Define a typedef for a pointer to our list handle, but don't actually
   define the structure. This is done to hide the data definition so that
   API callers don't try to work with data that only the list library needs
   to understand.

   The actual struct list & struct node is defined in list.c
*/
typedef struct list *LIST_HND;
typedef struct node *NODE_HND;

LIST_HND list_create();
NODE_HND list_prepend(LIST_HND list, void *user_data);
void * node_user_data(NODE_HND node);
  
#endif
