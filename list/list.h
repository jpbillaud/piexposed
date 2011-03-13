#ifndef _LIST_H_
#define _LIST_H_

/* singly-linked list */

struct s_list_node {
  struct s_list_node *next;
  void *data;
};

/* doubly-linked list */

struct d_list_node {
   struct d_list_node *next;
   struct d_list_node *prev;
   void *data;
};

/* tree-linked list */

struct t_list_node {
   struct t_list_node *next;
   struct t_list_node *prev;
   struct t_list_node *child;
   void *data;
};

#endif /* _LIST_H_ */
