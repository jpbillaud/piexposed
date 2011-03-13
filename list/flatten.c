#include <stdlib.h>

#include "list.h"

/*
 * Flatten a tree-linked list so that all nodes appear in a single
 * level, doubly-linked list. You are given the head and the tail
 * of the first level of the list.
 */

void
tlist_flatten(struct t_list_node *head, struct t_list_node **tail)
{
   struct t_list_node *ptail = *tail;

   for (; head; head = head->next) {
      struct t_list_node *child = head->child;

      if (child) {
         ptail->next = child;
         child->prev = ptail;

         while (child->next) {
            child = child->next;
         }

         ptail = child;
      }
   }

   *tail = ptail;
}
