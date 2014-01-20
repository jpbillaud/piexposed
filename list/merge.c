#include <stdio.h>

#include "list.h"

/*
 * Write a function that takes an array of sorted list and return a single
 * sorted list.
 */

struct s_list_node *
slist_merge_node(struct s_list_node *c1, struct s_list_node *c2)
{
    struct s_list_node *m_node;
    struct s_list_node **m_node_tail = &m_node;

    while (c1 && c2) {
        struct s_list_node *sl_node;

        if (c1->data < c2->data) {
            sl_node = c1;
            c1 = c1->next;
        } else {
            sl_node = c2;
            c2 = c2->next;
        }

        *m_node_tail = sl_node;
        m_node_tail = &sl_node->next;
    }

    if (c1) {
        *m_node_tail = c1;
    }

    if (c2) {
        *m_node_tail = c2;
    }

    return m_node;
}

struct s_list_node *
slist_merge_node_sort_rec(struct s_list_node *p_node, int sidx, int eidx)
{
    unsigned int midx;

    if (sidx == eidx) {
        return &p_node[sidx];
    }

    midx = (sidx+eidx)/2;

    return slist_merge_node(slist_merge_node_sort_rec(p_node, sidx, midx),
                            slist_merge_node_sort_rec(p_node, midx+1, eidx));
}

struct s_list_node *
slist_merge_node_sort(struct s_list_node *p_node, int n_nodes)
{
    return slist_merge_node_sort_rec(p_node, 0, n_nodes-1);
}

int main(void)
{
    struct s_list_node *m_node;
    struct s_list_node p_node[4];

    p_node[0] = *DF_SL_NODE(2, DF_SL_NODE(4, DF_SL_NODE(8, NULL)));
    p_node[1] = *DF_SL_NODE(5, DF_SL_NODE(9, DF_SL_NODE(11, NULL)));
    p_node[2] = *DF_SL_NODE(1, DF_SL_NODE(3, DF_SL_NODE(6, NULL)));
    p_node[3] = *DF_SL_NODE(12, DF_SL_NODE(15, NULL));

    m_node = slist_merge_node_sort(p_node, 4);

    for (; m_node; m_node = m_node->next) {
        printf("node %u\n", (unsigned int) m_node->data);
    }

    return 0;
}
