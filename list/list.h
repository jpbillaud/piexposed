#ifndef _LIST_H_
#define _LIST_H_

#include <stdlib.h>

/* singly-linked list */

struct s_list_node {
  struct s_list_node *next;
  unsigned int data;
};

/* doubly-linked list */

struct d_list_node {
   struct d_list_node *next;
   struct d_list_node *prev;
   unsigned int data;
};

/* tree-linked list */

struct t_list_node {
   struct t_list_node *next;
   struct t_list_node *prev;
   struct t_list_node *child;
   unsigned int data;
};

#define DF_SL_NODE(_data, _next)                         \
    ({struct s_list_node *node = malloc(sizeof (*node)); \
      node->data = _data;                                \
      node->next = _next;                                \
      node;})

#endif /* _LIST_H_ */
