#include "tree.h"
#include "util.h"

/*
 * Given a binary tree find out its height.
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

int main()
{
    struct b_tree_node_t *root_1 = DF_NODE(1, DF_NODE(2, DF_LEAF(3), DF_LEAF(4)), DF_NODE(2, DF_LEAF(4), DF_LEAF(3)));
    struct b_tree_node_t *root_2 = DF_NODE(1, DF_NODE(2, DF_NODE(3, DF_LEAF(5), NULL), DF_LEAF(4)), DF_NODE(2, DF_LEAF(4), DF_NODE(3, NULL, DF_LEAF(5))));
    struct b_tree_node_t *root_3 = DF_LEAF(1);

    printf("height %d should be 2\n", btree_height(root_1));
    printf("height %d should be 3\n", btree_height(root_2));
    printf("height %d should be 0\n", btree_height(root_3));
}
