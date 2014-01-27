#include "tree.h"
#include "util.h"

/*
 * Given a binary tree find the longest path within it. So, find a path between
 * any two leaf nodes, where the path is the longest.
 */

int
btree_longest_path_rec(struct b_tree_node_t *node,
                       int *src,
                       int *dst,
                       int *mx_leaf,
                       int *mx_depth)
{
    int mx_ldepth;
    int mx_lleaf;
    int mx_rdepth;
    int mx_rleaf;
    int mx_lpath;
    int mx_rpath;
    int lsrc;
    int ldst;
    int rsrc;
    int rdst;
    int rooted_path;

    if (!node->left && !node->right) {
        *mx_leaf = node->value;
        *mx_depth = 0;
        return 0;
    }

    if (node->left) {
         mx_lpath = btree_longest_path_rec(node->left,
                                           &lsrc,
                                           &ldst,
                                           &mx_lleaf,
                                           &mx_ldepth);
    } else {
        mx_ldepth = -1;
        mx_lleaf = node->value;
        mx_lpath = 0;
    }

    if (node->right) {
        mx_rpath = btree_longest_path_rec(node->right,
                                          &rsrc,
                                          &rdst,
                                          &mx_rleaf,
                                          &mx_rdepth);
    } else {
        mx_rdepth = -1;
        mx_rleaf = node->value;
        mx_rpath = 0;
    }

    rooted_path = ++mx_rdepth + ++mx_ldepth;
    
    *mx_leaf = (mx_ldepth > mx_rdepth) ? mx_lleaf : mx_rleaf;
    *mx_depth = (mx_ldepth > mx_rdepth) ? mx_ldepth : mx_rdepth;

    if (mx_rpath < rooted_path && mx_lpath < rooted_path) {
        *src = mx_lleaf;
        *dst = mx_rleaf;
        return rooted_path;
    }

    if (mx_rpath > mx_lpath) {
        *src = rsrc;
        *dst = rdst;
        return mx_rpath;
    } else {
        *src = lsrc;
        *dst = ldst;
        return mx_lpath;
    }
}

int
btree_longest_path(struct b_tree_node_t *node, int *src, int *dst)
{
    int mx_leaf, mx_depth;

    return btree_longest_path_rec(node, src, dst, &mx_leaf, &mx_depth); 
}

int main()
{
    struct b_tree_node_t *root_1 = DF_NODE(10, DF_NODE(16, DF_LEAF(13), DF_NODE(1, DF_LEAF(5), DF_NODE(6, DF_LEAF(7), NULL))), DF_NODE(11, DF_LEAF(9), DF_LEAF(8)));
    struct b_tree_node_t *root_2 = DF_NODE(10, DF_NODE(6, DF_NODE(3, DF_NODE(13, DF_NODE(1, DF_LEAF(12), DF_LEAF(14)), NULL), DF_NODE(5, DF_NODE(16, DF_LEAF(15), NULL), DF_LEAF(29))), DF_NODE(7, DF_LEAF(9), DF_NODE(17, DF_NODE(8, DF_LEAF(12), DF_LEAF(21)), NULL))), DF_LEAF(23));
    struct b_tree_node_t *root_3 = DF_LEAF(2);
    struct b_tree_node_t *root_4 = DF_NODE(5, DF_NODE(6, DF_NODE(7, DF_LEAF(8), NULL), NULL), NULL);
    struct b_tree_node_t *root_5 = DF_NODE(5, NULL, DF_NODE(6, NULL, DF_NODE(7, NULL, DF_LEAF(8))));
    int src, dst, path;

    path = btree_longest_path(root_1, &src, &dst);
    printf("root path %d (6) with src %d (7) and dst %d (8)\n", path, src, dst);
    path = btree_longest_path(root_2, &src, &dst);
    printf("root path %d (8) with src %d (15) and dst %d (21)\n", path, src, dst);
    path = btree_longest_path(root_3, &src, &dst);
    printf("root path %d (0)\n", path);
    path = btree_longest_path(root_4, &src, &dst);
    printf("root path %d (3) with src %d (8) and dst %d (5)\n", path, src, dst);
    path = btree_longest_path(root_5, &src, &dst);
    printf("root path %d (3) with src %d (5) and dst %d (8)\n", path, src, dst);
}
