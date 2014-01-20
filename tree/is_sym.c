#include "tree.h"

/*
 * Given a binary tree, find out whether or not it is symmetrical.
 */

static
int btree_is_sym_rec(struct b_tree_node_t *n1, struct b_tree_node_t *n2)
{
    if (!n1 || !n2) {
        return !n1 && !n2;
    }

    return n1->value == n2->value &&
           btree_is_sym_rec(n1->left, n2->right) &&
           btree_is_sym_rec(n1->right, n2->left);           
}

int
btree_is_sym(struct b_tree_node_t *root)
{
    return btree_is_sym_rec(root->left, root->right);
}

int main()
{
    struct b_tree_node_t *sym_root = DF_NODE(1, DF_NODE(2, DF_LEAF(3), DF_LEAF(4)), DF_NODE(2, DF_LEAF(4), DF_LEAF(3)));
    struct b_tree_node_t *sym_root_2 = DF_NODE(1, DF_NODE(2, DF_NODE(3, DF_LEAF(5), NULL), DF_LEAF(4)), DF_NODE(2, DF_LEAF(4), DF_NODE(3, NULL, DF_LEAF(5))));
    struct b_tree_node_t *non_sym_root = DF_NODE(1, DF_NODE(2, DF_LEAF(3), NULL), DF_NODE(2, DF_LEAF(4), DF_LEAF(3)));

    printf("is sym %u should be 1\n", btree_is_sym(sym_root));
    printf("is sym %u should be 1\n", btree_is_sym(sym_root_2));
    printf("is sym %u should be 0\n", btree_is_sym(non_sym_root));
}
