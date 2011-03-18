#include <stdlib.h>

#include "tree.h"

void
b_tree_breadth_first_traversal(struct b_tree_node_t *root)
{
   lifo_t lifo;

   lifo_init(&lifo);

   lifo_push(&lifo, root);

   do {
      root = lifo_pop(&lifo);
      if (root == NULL) {
         continue;
      }

      if (root->right) {
         lifo_push(&lifo, root->right);
      }
      
      if (root->left) {
         lifo_push(&lifo, root->left);
      }

   } while (root);
}


