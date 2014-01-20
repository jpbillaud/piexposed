#include "tree.h"

/*
 * Given a binary tree, find out whether or not it is a binary search tree.
 */

static int
btree_is_bst_rec(struct b_tree_node_t *root,
                 unsigned int min,
                 unsigned int max)
{
    if (!root) {
        return 1;
    }

    if (root->value < min || root->value > max) {
        return 0;
    }

    if (!btree_is_bst_rec(root->left, min, root->value)) {
        return 0;
    }

    return btree_is_bst_rec(root->right, root->value, max);
}

int
btree_is_bst(struct b_tree_node_t *root)
{
   return btree_is_bst_rec(root, 0, -1);
}

int main()
{
    struct b_tree_node_t *bst_root = DF_NODE(10, DF_NODE(6, DF_LEAF(3), DF_LEAF(7)), DF_NODE(12, DF_LEAF(11), DF_LEAF(15)));
    struct b_tree_node_t *non_bst_root = DF_NODE(10, DF_NODE(6, DF_LEAF(7), DF_LEAF(3)), DF_NODE(12, DF_LEAF(11), DF_LEAF(15)));
    struct b_tree_node_t *non_bst_root_2 = DF_NODE(10, DF_NODE(6, DF_LEAF(3), DF_LEAF(7)), DF_NODE(12, DF_LEAF(9), DF_LEAF(15)));

    printf("is bst %u should be 1\n", btree_is_bst(bst_root));
    printf("is bst %u should be 0\n", btree_is_bst(non_bst_root));
    printf("is bst %u should be 0\n", btree_is_bst(non_bst_root_2));
}
