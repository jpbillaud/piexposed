#include <stdlib.h>

#include "list.h"

/*
 * Reverse a given a singly-linked list.
 */

struct s_list_node *
slist_reverse(struct s_list_node *head)
{
   struct s_list_node *prev, *ptr, *next;

   for (prev = NULL, ptr = head; ptr; prev = ptr, ptr = next) {
      next = ptr->next;
      ptr->next = prev;
   }

   return prev;
}
