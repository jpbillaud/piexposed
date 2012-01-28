#include "tree.h"

/*
 * Given the value of two nodes in a binary search tree, find the lowest common ancestor.
 * You may assume that both values already exist in the tree.
 */

struct b_tree_node_t *
btree_lca_bst(struct b_tree_node_t *root,
              int val1,
              int val2)
{
   while (1) {

      if (val1 > root->value &&
          val2 > root->value) {
         root = root->right;
         continue;
      }

      if (val1 < root->value &&
          val2 < root->value) {
         root = root->left;
         continue;
      }

      break;
   }

   return root;
}
