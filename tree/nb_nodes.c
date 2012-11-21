#include "tree.h"

/*
 * Given a binary tree find the number of nodes.
 */

unsigned int
btree_nb_nodes(struct b_tree_node_t *root)
{
   if (root == NULL) {
      return 0;
   }

   return 1 + btree_nb_nodes(root->left) + btree_nb_nodes(root->right);
}

int main()
{
   ITERATE_TREES(btree_nb_nodes, "%u");
}
