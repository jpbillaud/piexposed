#ifndef _TREE_H_
#define _TREE_H_

#include <stdlib.h>
#include <stdio.h>

struct b_tree_node_t {
   struct b_tree_node_t *right;
   struct b_tree_node_t *left;
   int                   value;
};

#define DF_NODE(_value, _left, _right)					\
  ({struct b_tree_node_t *node = malloc(sizeof(struct b_tree_node_t));	\
    node->value = _value;						\
    node->left = _left;							\
    node->right = _right; node;})

#define DF_LEAF(_value) DF_NODE(_value, NULL, NULL)

#define MK_TREES()                                                              \
struct b_tree_node_t *root_none = NULL;                                         \
struct b_tree_node_t *root_mh0 = DF_LEAF(5);                                    \
struct b_tree_node_t *root_mh1 = DF_NODE(10,                                    \
                                         DF_NODE(6,                             \
                                                 DF_LEAF(3),                    \
                                                 DF_LEAF(7)),                   \
                                         DF_LEAF(12));                          \
struct b_tree_node_t *root_mh2 = DF_NODE(10,                                    \
                                         DF_NODE(6,                             \
                                                 DF_LEAF(3),                    \
                                                 DF_LEAF(7)),                   \
                                         DF_NODE(12,                            \
                                                 DF_LEAF(11),                   \
                                                 DF_LEAF(15)));                 \
struct b_tree_node_t *root_mh3 = DF_NODE(10,                                    \
                                         DF_NODE(6,                             \
                                                 DF_NODE(2,                     \
                                                         DF_NODE(3,             \
                                                                 DF_LEAF(11),   \
                                                                 DF_LEAF(4)),   \
                                                         DF_LEAF(15)),          \
                                                 DF_NODE(13,                    \
                                                         DF_LEAF(9),            \
                                                         NULL)),                \
                                         DF_NODE(14,                            \
                                                 DF_NODE(3,                     \
                                                         DF_NODE(6,             \
                                                                 DF_LEAF(16),   \
                                                                 NULL),         \
                                                         DF_NODE(5,             \
                                                                 DF_LEAF(15),   \
                                                                 DF_LEAF(11))), \
                                                 NULL));                        \
struct {                                                                        \
   char *name;                                                                  \
   struct b_tree_node_t *root;                                                  \
} trees[] = {                                                                   \
   {                                                                            \
      .name = "empty",                                                          \
      .root = root_none                                                         \
   },                                                                           \
   {                                                                            \
      .name = "0-level",                                                        \
      .root = root_mh0                                                          \
   },                                                                           \
   {                                                                            \
      .name = "1-level",                                                        \
      .root = root_mh1                                                          \
   },                                                                           \
   {                                                                            \
      .name = "2-level",                                                        \
      .root = root_mh2                                                          \
   },                                                                           \
   {                                                                            \
      .name = "3-level",                                                        \
      .root = root_mh3                                                          \
   }                                                                            \
};

#define NB_TREES (sizeof(trees)/((char *)&trees[1] - (char *)trees))

#define ITERATE_TREES(_f, _fmt, _args ...)                        \
   do {                                                           \
      int idx;                                                    \
      MK_TREES();                                                 \
      for (idx = 0; idx < NB_TREES; idx++) {                      \
         printf("running %s against %s returned ", #_f, trees[idx].name); \
         printf(_fmt, _f(trees[idx].root, ##_args));              \
         printf("\n");                                            \
               }                                                  \
   } while(0);

typedef void *fifo_t;

extern void  fifo_init(fifo_t *fifo);
extern void  fifo_push(fifo_t *fifo, void *data);
extern void *fifo_pop(fifo_t *fifo);
extern int   fifo_empty(fifo_t *fifo);

typedef void *lifo_t;

extern void  lifo_init(lifo_t *lifo);
extern void  lifo_push(lifo_t *lifo, void *data);
extern void *lifo_pop(lifo_t *lifo);
extern int   lifo_empty(lifo_t *lifo);

#endif /* _TREE_H_*/
