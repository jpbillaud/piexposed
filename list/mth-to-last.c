#include <stdlib.h>

#include "list.h"

/*
 * Given a singly-linked list, devise a time- and space -efficient algorithm
 * to find the mth-to-last element of the list.
 */

struct s_list_node *
slist_mth_to_last(struct s_list_node *head, short m)
{
  struct s_list_node *node = NULL;
  struct s_list_node *mth = NULL;

  if (!head) {
    return NULL;
  }

  for (node = head; node; node = node->next) {

    if (mth) {
      mth = mth->next;
      continue;
    }

    mth = !--m ? head : NULL;
  }
  
  return mth;
}
