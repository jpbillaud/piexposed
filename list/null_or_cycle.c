#include <stdlib.h>

#include "list.h"

/*
 * Write a function that takes a pointer to the head of
 * a list and determines whether the list is cyclic or
 * acyclic.
 */

int
s_list_is_cyclic(struct s_list_node *head)
{
   struct s_list_node *fptr;
   struct s_list_node *sptr;
   
   /*
    * The idea is to run one slow and one fast pointer
    * through the list and see if the fast pointer
    * ever catch up the slow one. If that's the case
    * then there is a cycle.
    */

   for (sptr = fptr = head;
        fptr && fptr->next;
        sptr = sptr->next, fptr = fptr->next->next) {

      if (fptr == sptr ||
          fptr->next == sptr) {
         return 1;
      }
   }

   return 0;
}
