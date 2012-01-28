#include "tree.h"

/*
 * Given the value of two nodes in a binary tree, find the lowest common ancestor.
 * You may assume that both values already exist in the tree.
 */

struct b_tree_node_t *
btree_lca(struct b_tree_node_t *root,
	  int val1,
	  int val2)
{
  struct b_tree_node_t *p1;
  struct b_tree_node_t *p2;

  /*
   * the current node carries one of the values let's
   * signal the upper layer that we found something.
   */
  if (!root ||
      root->value == val1 ||
      root->value == val2) {
    return root;
  }

  p1 = btree_lca(root->left, val1, val2);
  p2 = btree_lca(root->right, val1, val2);

  /*
   * if we found a value on the left and the right side
   * then it means the current node is the lowest common
   * ancestor;
   */
  if (p1 && p2) {
    return root;
  }

  /*
   * otherwise we just report up there whatever was found
   * during our subtrees traversals.
   */
  return p1 ? p1 : p2;
}

int main()
{
  struct b_tree_node_t *root = DF_NODE(10, DF_NODE(6, DF_LEAF(3), DF_LEAF(7)), DF_NODE(12, DF_LEAF(11), DF_LEAF(15)));

  printf("lca of 3 and 7 is %u\n", btree_lca(root, 3, 7)->value);
  printf("lca of 6 and 7 is %u\n", btree_lca(root, 6, 7)->value);
  printf("lca of 11 and 3 is %u\n", btree_lca(root, 11, 3)->value);

  return 0;
}
