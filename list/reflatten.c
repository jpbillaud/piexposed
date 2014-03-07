#include <stdio.h>
#include <stdlib.h>

struct s_node {
    int value;
    struct s_node *next;
    struct s_node *child;
};

struct s_node **
l_flatten_rec(struct s_node *node)
{
    struct s_node **child_tail;
    struct s_node **tail;

    for (; node; node = node->next) {
        tail = &node->next;

        if (!node->child) {
            continue;
        }

        child_tail = l_flatten_rec(node->child);
        *child_tail = node->next;
        node->next = node->child;
        node->child = NULL;
    
    }

    return tail;
}

void
l_print(struct s_node *node, int level)
{
    for (; node; node = node->next) {
        printf("-%u- node %u\n", level, node->value);

        if (node->child) {
            l_print(node->child, level + 1);
        } 
    }
}

int
l_flatten(struct s_node *node)
{
    l_flatten_rec(node);
    return 0;   
}

#define DF_L_NODE(_value, _next, _child)            \
    ({                                              \
        struct s_node *node = malloc(sizeof *node); \
        node->value = _value;                       \
        node->next = _next;                         \
        node->child = _child;                       \
        node;                                       \
    })

int main()
{
    struct s_node *head = DF_L_NODE(1, DF_L_NODE(2, DF_L_NODE(3, DF_L_NODE(7, DF_L_NODE(8, NULL, NULL), NULL), DF_L_NODE(4, DF_L_NODE(5, DF_L_NODE(6, NULL, NULL), NULL), NULL)), NULL), NULL);

    l_print(head, 0);
    l_flatten(head);
    l_print(head, 0);
}
