#include "tree.h"

/*
 * Given a binary tree, find out whether or not it is a binary search tree.
 */

#define MIN(a,b) ((a<b) ? a : b)
#define MAX(a,b) ((a>b) ? a : b)

static int
btree_is_bst_rec(struct b_tree_node_t *root, int *pmin, int *pmax)
{
   unsigned int lmin = -1, rmin = -1;
   int lmax = 0, rmax = 0;

   if (root->left) {
      if (!btree_is_bst_rec(root->left, &lmin, &lmax)) {
         return 0;
      }

      if (root->value < lmax) {
         return 0;
      }
   }

   if (root->right) {
      if (!btree_is_bst_rec(root->right, &rmin, &rmax)) {
         return 0;
      }

      if (root->value > rmin) {
         return 0;
      }
   }

   *pmin = MIN(lmin, root->value);
   *pmax = MAX(rmax, root->value);
   return 1;
}

int
btree_is_bst(struct b_tree_node_t *root)
{
   int min, max;
   return btree_is_bst_rec(root, &min, &max);
}

int main()
{
  struct b_tree_node_t *bst_root = DF_NODE(10, DF_NODE(6, DF_LEAF(3), DF_LEAF(7)), DF_NODE(12, DF_LEAF(11), DF_LEAF(15)));
  struct b_tree_node_t *non_bst_root = DF_NODE(10, DF_NODE(6, DF_LEAF(7), DF_LEAF(3)), DF_NODE(12, DF_LEAF(11), DF_LEAF(15)));
  struct b_tree_node_t *non_bst_root_2 = DF_NODE(10, DF_NODE(6, DF_LEAF(3), DF_LEAF(7)), DF_NODE(12, DF_LEAF(9), DF_LEAF(15)));

  printf("is bst %u\n", btree_is_bst(bst_root));
  printf("is bst %u\n", btree_is_bst(non_bst_root));
  printf("is bst %u\n", btree_is_bst(non_bst_root_2));
}
