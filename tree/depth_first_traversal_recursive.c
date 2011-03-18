#include <stdlib.h>

#include "tree.h"

void
btree_depth_first_traversal_recursive(struct b_tree_node_t *root)
{
   if (root == NULL) {
      return;
   }

   depth_first_traversal_recursive(root->left);
   /* process root */
   depth_first_traversal_recursive(root->right);
}


