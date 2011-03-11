#ifndef _LIST_H_
#define _LIST_H_

struct s_list_node {
  struct s_list_node *next;
  void *data;
};

#endif _LIST_H_
