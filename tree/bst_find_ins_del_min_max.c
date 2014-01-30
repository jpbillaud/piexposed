#include "tree.h"

/*
 * Given a binary search tree, implements the insert and delete node functions.
 */

struct b_tree_node_t **
btree_find_node(struct b_tree_node_t **p_root,
                unsigned int value)
{
    struct b_tree_node_t *root = *p_root;
    struct b_tree_node_t **child;

    if (!root) {
        return NULL;
    }

    if (root->value == value) {
        return p_root;
    }

    child = (root->value > value) ? &root->left : &root->right;

    return btree_find_node(child, value);
}

struct b_tree_node_t **
btree_find_min(struct b_tree_node_t **root)
{
    struct b_tree_node_t **min_node;

    return (!*root) ? NULL :
                     (min_node = btree_find_min(&(*root)->left)) ? min_node :
                                                                   root;
}

struct b_tree_node_t **
btree_find_max(struct b_tree_node_t **root)
{
    struct b_tree_node_t **max_node;

    return (!*root) ? NULL :
                     (max_node = btree_find_max(&(*root)->right)) ? max_node :
                                                                    root;
}

int
btree_insert_node(struct b_tree_node_t **root,
                  unsigned int value)
{
    struct b_tree_node_t **child;

    if (!*root) {
        *root = DF_LEAF(value);
        return 0;
    }

    if ((*root)->value == value) {
        return 1;
    }

    child = ((*root)->value > value) ? &(*root)->left : &(*root)->right;

    return btree_insert_node(child, value);
}

int
btree_delete_node(struct b_tree_node_t **root,
                  unsigned int value)
{
    struct b_tree_node_t **p_node;
    struct b_tree_node_t **n_node;
    struct b_tree_node_t *n_child;;

    if ((p_node = btree_find_node(root, value)) == NULL) {
        return 1;
    }

    if ((*p_node)->left == (*p_node)->right) {
        *p_node = NULL;
        return 0;
    }

    n_node = (n_node = btree_find_min(&(*p_node)->right)) ? n_node :
                                                            btree_find_max(&((*p_node)->left));

    if ((*n_node)->value > (*p_node)->value) {
        n_child = (*n_node)->right;
        (*n_node)->left = (*p_node)->left;
        (*n_node)->right = ((*p_node)->right == *n_node) ? (*n_node)->right :
                                                           (*p_node)->right;
    } else {
        n_child = (*n_node)->left;
        (*n_node)->right = (*p_node)->right;
        (*n_node)->left = ((*p_node)->left == *n_node) ? (*n_node)->left :
                                                         (*p_node)->left;
    }

    *p_node = *n_node;
    *n_node = n_child;
    return 0;
}

static void
btree_dummy_visitor(struct b_tree_node_t *node)
{
    printf("%u ", node->value);
}

int main()
{
    struct b_tree_node_t *bst_root = DF_NODE(10, DF_NODE(6, DF_NODE(3, DF_LEAF(1), DF_LEAF(4)), DF_LEAF(7)), DF_NODE(19, DF_NODE(12, DF_LEAF(11), DF_NODE(17, DF_LEAF(15), DF_LEAF(18))), DF_LEAF(21)));

    printf("-- initial status:\n");
    btree_depth_first_traversal_recursive(bst_root, btree_dummy_visitor);
    printf("\nmin value %u and max value %u\n", (*btree_find_min(&bst_root))->value, (*btree_find_max(&bst_root))->value);

    printf("-- adding 17:\n");
    btree_insert_node(&bst_root, 17);
    btree_depth_first_traversal_recursive(bst_root, btree_dummy_visitor);
    printf("\nmin value %u and max value %u\n", (*btree_find_min(&bst_root))->value, (*btree_find_max(&bst_root))->value);

    printf("-- adding 30:\n");
    btree_insert_node(&bst_root, 30);
    btree_depth_first_traversal_recursive(bst_root, btree_dummy_visitor);
    printf("\nmin value %u and max value %u\n", (*btree_find_min(&bst_root))->value, (*btree_find_max(&bst_root))->value);

    printf("-- adding 1:\n");
    btree_insert_node(&bst_root, 1);
    btree_depth_first_traversal_recursive(bst_root, btree_dummy_visitor);
    printf("\nmin value %u and max value %u\n", (*btree_find_min(&bst_root))->value, (*btree_find_max(&bst_root))->value);

    printf("-- adding 4:\n");
    btree_insert_node(&bst_root, 4);
    btree_depth_first_traversal_recursive(bst_root, btree_dummy_visitor);
    printf("\nmin value %u and max value %u\n", (*btree_find_min(&bst_root))->value, (*btree_find_max(&bst_root))->value);

    printf("-- remove 11:\n");
    btree_delete_node(&bst_root, 11);
    btree_depth_first_traversal_recursive(bst_root, btree_dummy_visitor);
    printf("\nmin value %u and max value %u\n", (*btree_find_min(&bst_root))->value, (*btree_find_max(&bst_root))->value);

    printf("-- remove 10:\n");
    btree_delete_node(&bst_root, 10);
    btree_depth_first_traversal_recursive(bst_root, btree_dummy_visitor);
    printf("\nmin value %u and max value %u\n", (*btree_find_min(&bst_root))->value, (*btree_find_max(&bst_root))->value);

    printf("-- remove 3:\n");
    btree_delete_node(&bst_root, 3);
    btree_depth_first_traversal_recursive(bst_root, btree_dummy_visitor);
    printf("\nmin value %u and max value %u\n", (*btree_find_min(&bst_root))->value, (*btree_find_max(&bst_root))->value);

    printf("-- remove 4:\n");
    btree_delete_node(&bst_root, 4);
    btree_depth_first_traversal_recursive(bst_root, btree_dummy_visitor);
    printf("\nmin value %u and max value %u\n", (*btree_find_min(&bst_root))->value, (*btree_find_max(&bst_root))->value);

    printf("-- remove 15:\n");
    btree_delete_node(&bst_root, 15);
    btree_depth_first_traversal_recursive(bst_root, btree_dummy_visitor);
    printf("\nmin value %u and max value %u\n", (*btree_find_min(&bst_root))->value, (*btree_find_max(&bst_root))->value);
}
