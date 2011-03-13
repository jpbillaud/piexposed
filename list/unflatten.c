#include <stdlib.h>

#include "list.h"

/*
 * Unflatten a tree-linked list that went through the flattening
 * function in flatten.c.
 */

void tlist_unflatten(struct t_list_node *head, struct t_list_node **tail)
{
   struct t_list_node *ptail = *tail;
   struct t_list_node *last_valid_tail = *tail;

   for (; ptail; ptail = ptail->prev) {
      struct t_list_node *child = ptail->child;

      if (child) {
         child->prev->next = NULL;
         last_valid_tail = child->prev;
         child->prev = NULL;
      }
   }

   *tail = last_valid_tail;
}
