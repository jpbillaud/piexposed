#include <stdlib.h>

#include "tree.h"

void
b_tree_breadth_first_traversal(struct b_tree_node_t *root)
{
   fifo_t fifo;

   fifo_init(&fifo);

   fifo_push(&fifo, root);

   do {
      root = fifo_pop(&fifo);

      if (root == NULL) {
         continue;
      }

      if (root->left) {
         fifo_push(&fifo, root->left);
      }

      if (root->right) {
         fifo_push(&fifo, root->right);
      }

   } while (root);
}


