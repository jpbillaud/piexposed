#include "tree.h"
#include "util.h"

/*
 * Given a binary tree, find out whether or not it is balanced tree e.g. the
 * the height difference between its left and right sub-tree is at most 1.
 */

static int
btree_height_rec(struct b_tree_node_t *root)
{
    return (root) ? 1 + MAX(btree_height_rec(root->left), btree_height_rec(root->right))
                  : 0;
}

int
btree_height(struct b_tree_node_t *root)
{
    return btree_height_rec(root) - 1;
}

int
btree_is_bal(struct b_tree_node_t *root)
{
    return abs(btree_height(root->left) - btree_height(root->right)) <= 1;
}

int main()
{
    struct b_tree_node_t *bal_root = DF_NODE(1, DF_NODE(2, DF_LEAF(3), DF_LEAF(4)), DF_NODE(2, DF_LEAF(4), DF_LEAF(3)));
    struct b_tree_node_t *bal_root_2 = DF_NODE(1, DF_NODE(2, DF_NODE(3, DF_LEAF(5), NULL), DF_LEAF(4)), DF_NODE(2, DF_LEAF(4), DF_NODE(3, NULL, DF_LEAF(5))));
    struct b_tree_node_t *non_bal_root = DF_NODE(1, DF_NODE(2, DF_LEAF(4), DF_NODE(3, DF_LEAF(7), DF_NODE(5, DF_LEAF(6), NULL))), DF_LEAF(2));

    printf("is bal %u should be 1\n", btree_is_bal(bal_root));
    printf("is bal %u should be 1\n", btree_is_bal(bal_root_2));
    printf("is bal %u should be 0\n", btree_is_bal(non_bal_root));
}
