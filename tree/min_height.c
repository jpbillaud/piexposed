#include "tree.h"

/*
 * Given a binary tree find its minimum height.
 */

static unsigned int
btree_min_height_rec(struct b_tree_node_t *root,
                     unsigned int cheight,
                     unsigned int mheight)
{
   if (root == NULL || ++cheight >= mheight) {
      return mheight;
   }

   mheight = btree_min_height_rec(root->right,
                                  cheight,
                                  btree_min_height_rec(root->left,
                                                       cheight,
                                                       mheight));

   /* If the node is a leaf then its height must be the new min height */
   return (root->left == root->right) ? cheight : mheight;
}

int
btree_min_height(struct b_tree_node_t *root)
{
   return btree_min_height_rec(root, (unsigned int)-1, (unsigned int)-1);
}

int main()
{
   ITERATE_TREES(btree_min_height, "%d");
}
