#include <stdlib.h>

#include "list.h"

/*
 * Given a singly-linked list, remove all the elements for a given value. 
 */

struct s_list_node *
slist_remove_all_with_val(struct s_list_node *head, void *data)
{
   struct s_list_node *prev, *ptr, *next;

   for (prev = NULL, ptr = head; ptr; prev = ptr, ptr = next) {
      next = ptr->next;

      if (ptr->data != data) {
         continue;
      }

      /*
       * If we remove the first element then we need to update head
       */
      if (prev == NULL) {
         head = ptr->next;
      } else {
         prev->next = ptr->next;
      }

      free(ptr);
   }

   return head;
}
