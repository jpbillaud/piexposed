#include "tree.h"

/*
 * Given a binary tree find its minimum height and the according nodes path.
 */

static unsigned int
btree_min_height_path_rec(struct b_tree_node_t *root,
                          unsigned int cheight,
                          unsigned int mheight,
                          unsigned int *path)
{
   unsigned nmheight;

   if (root == NULL || ++cheight >= mheight) {
      return mheight;
   }

   nmheight = btree_min_height_path_rec(root->right,
                                        cheight,
                                        btree_min_height_path_rec(root->left,
                                                                  cheight,
                                                                  mheight,
                                                                  path),
                                        path);

   /* If the node is a leaf then its height must be the new min height */
   if (root->left == root->right) {
      nmheight = cheight;
   }

   /* If a new min height was found then this node must be in the path */
   if (nmheight != mheight) {
      path[cheight] = root->value;
   }

   return nmheight;
}

/*
 * Not great but this function assumes "path" has enough slots to fill in the
 * worst-case scenario... One could allocate an array of "nodes" size which
 * would require an extra traversal of the tree or have a smart array
 * implementation that grows dynamically. Regardless that's not the core issue
 * of this particular exercise even though I might fix it later.
 */
int
btree_min_height_path(struct b_tree_node_t *root, unsigned int *path)
{
   return btree_min_height_path_rec(root,
                                    (unsigned int)-1,
                                    (unsigned int)-1,
                                    path);
}

int main()
{
   int idx;

   MK_TREES();

   for (idx = 0; idx < NB_TREES; idx++) {
      unsigned int path[256] = {0,};
      int pidx;
      int mheight;

      mheight = btree_min_height_path(trees[idx].root, path);

      printf("calling on %s with found minimum path: ",
             trees[idx].name);
      for (pidx = 0; pidx <= mheight; pidx++) {
         printf("%d ", path[pidx]);
      }
      printf("\n");
   }
}
