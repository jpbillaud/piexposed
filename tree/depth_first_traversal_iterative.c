#include <stdlib.h>

#include "tree.h"

void
btree_depth_first_traversal_iterative(struct b_tree_node_t *root)
{
   struct b_tree_node_t *node;
   fifo_t fifo;

   fifo_init(&fifo);

   fifo_push(&fifo, root);

   do {
      root = fifo_pop(&fifo);
      if (root == NULL) {
         continue;
      }

      if (root->right) {
         fifo_push(&fifo, root->right);
      }
      
      if (root->left) {
         fifo_push(&fifo, root->left);
      }

   } while (root);
}


