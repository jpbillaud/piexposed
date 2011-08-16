#include <stdlib.h>

#include "list.h"

/*
 * Flatten a tree-linked list so that all nodes appear in a single
 * level, doubly-linked list. You are given the head and the tail
 * of the first level of the list.
 *
 *    --head                  --tail
 *   |                       |
 *  ---     ---     ---     --- 
 * | 5 |   | 6 |   | 3 |   | 4 |
 * |   |-->|   |-->|   |-->| x |
 * |   |<--|   |<--|   |<--| x |
 * |   |   | x |   | x |   | x |
 *  ---     ---     ---     ---
 *   |
 *   |
 *  ---     --- 
 * | 2 |   | 1 |
 * |   |-->| x |
 * |   |<--| x |
 * |   |   |   |
 *  ---     --- 
 *   |       |
 *   |       |
 *  ---     ---     ---     --- 
 * | 7 |   | 8 |   | 9 |   | 2 |
 * | x |   |   |-->|   |-->| x |
 * | x |   |   |<--|   |<--| x |
 * | x |   | x |   | x |   |   |
 *  ---     ---     ---     ---
 *                           |
 *                           |
 *                          ---     --- 
 *                         | 4 |   | 0 |
 *                         |   |-->| x |
 *                         |   |<--| x |
 *                         | x |   | x |
 *                          ---     --- 
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
