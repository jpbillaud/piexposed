#include <stdlib.h>

#include "tree.h"

void
btree_depth_first_traversal_recursive(struct b_tree_node_t *root,
                                      void (*v)(struct b_tree_node_t *))
{
   if (root == NULL) {
      return;
   }

   btree_depth_first_traversal_recursive(root->left, v);
   (*v)(root);
   btree_depth_first_traversal_recursive(root->right, v);
}


