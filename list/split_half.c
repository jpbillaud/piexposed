#include <stdlib.h>

#include "list.h"

/*
 * Split a given singly-linked list in half.
 */

struct s_list_node *
slist_split(struct s_list_node *head)
{
   struct s_list_node *slowp = head;
   struct s_list_node *fastp = head;
   struct s_list_node *prevp = NULL;

   /*
    * The idea is to have a slow and a fast pointer. The fast pointer
    * moving twice as fast as the slow one.
    */
   while (fastp) {
      prevp = slowp;
      slowp = slowp->next;
      fastp = (fastp->next) ? fastp->next->next : NULL;
   }

   if (prevp) {
      prevp->next = NULL;
   }
   return slowp;
}
