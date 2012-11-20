#include "tree.h"

/*
 * Given a binary tree find its minimum height.
 */

#define MIN(a,b) ((a<b) ? a : b)

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
   struct b_tree_node_t *root_none = NULL;

   struct b_tree_node_t *root_mh0 = DF_LEAF(5);

   struct b_tree_node_t *root_mh1 = DF_NODE(10,
                                            DF_NODE(6,
                                                    DF_LEAF(3),
                                                    DF_LEAF(7)),
                                            DF_LEAF(12));
  
   struct b_tree_node_t *root_mh2 = DF_NODE(10,
                                            DF_NODE(6,
                                                    DF_LEAF(3),
                                                    DF_LEAF(7)),
                                            DF_NODE(12,
                                                    DF_LEAF(11),
                                                    DF_LEAF(15)));

   struct b_tree_node_t *root_mh3 = DF_NODE(10,
                                            DF_NODE(6,
                                                    DF_NODE(2,
                                                            DF_NODE(3,
                                                                    DF_LEAF(11),
                                                                    DF_LEAF(4)),
                                                            DF_LEAF(15)),
                                                    DF_NODE(13,
                                                            DF_LEAF(9),
                                                            NULL)),
                                            DF_NODE(14,
                                                    DF_NODE(3,
                                                            DF_NODE(6,
                                                                    DF_LEAF(16),
                                                                    NULL),
                                                            DF_NODE(5,
                                                                    DF_LEAF(15),
                                                                    DF_LEAF(11))),
                                                    NULL));

  printf("min height %d\n", btree_min_height(root_none));
  printf("min height %d\n", btree_min_height(root_mh0));
  printf("min height %d\n", btree_min_height(root_mh1));
  printf("min height %d\n", btree_min_height(root_mh2));
  printf("min height %d\n", btree_min_height(root_mh3));
}
