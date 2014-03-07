#include <stdlib.h>
#include <stdio.h>

struct s_list_node {
    int val;
    struct s_list_node *next;
};

struct t_list_node {
    struct s_list_node s_node;
    struct t_list_node *t_node;
};

#define offsetof(_type, _member) \
    (unsigned int)&(((_type *) NULL)->_member)

#define struct_from_member(_type, _addr, _member) \
    (_type *)((char *)_addr - offsetof(_type, _member))

struct s_list_node **
list_tail(struct s_list_node **head)
{
    return *head ? head : list_tail(&(*head)->next);
}

struct t_list_node *
list_flatten_rec(struct t_list_node *node,
                 struct s_list_node ***s_tail)
{
    struct s_list_node *c;
    struct s_list_node **tail;

    for (c = &node->s_node;
         c;
         c = c->next) {
        struct t_list_node *t = struct_from_member(struct t_list_node, c, s_node);

        tail = &c->next;

        if (t->t_node) {
            list_flatten_rec(t->t_node, &tail);
            *tail = c->next;
            c->next = &t->t_node->s_node;
//            t->t_node = NULL;
        }
    }

    if (s_tail) {
        *s_tail = tail;
    }

    return node;
}

struct t_list_node *
list_flatten(struct t_list_node *node)
{
    return list_flatten_rec(node, NULL);
}

void
list_s_traverse(struct s_list_node *node)
{
    if (node) {
        printf("%u", node->val);
        list_s_traverse(node->next);
    }
}

void
list_t_traverse(struct t_list_node *node)
{
    struct s_list_node *c;

    if (!node) {
        return;
    }

    for (c = &node->s_node;
         c;
         c = c->next) {
        struct t_list_node *t = struct_from_member(struct t_list_node, c, s_node);

        printf("%u - ", c->val);

        if (t->t_node) {
            list_t_traverse(t->t_node);
        }
    }
}

#define DF_NODE(_val, _n_s_node, _n_t_node)                 \
    ({                                                      \
        struct t_list_node *node = malloc(sizeof(*node));   \
        node->s_node.val = _val;                            \
        node->s_node.next = _n_s_node;                      \
        node->t_node = _n_t_node;                           \
        node;                                               \
     })

/*
 *struct t_list_node {
 *    struct t_list_node *next;
 *    struct t_list_node *child;
 *    int val;
 *};
 *
 *struct t_list_node *
 *list_t_flatten(struct t_list_node *node)
 *{
 *    struct t_list_node *c;
 *    struct t_list_node **tail;
 *
 *    for (c = node; c; c = c->next) {
 *
 *        if (c->child) {
 *            list_t_flatten(c->child);
 *            *tail = c->next;
 *            c->next = c->child;
 *            c->child = NULL;
 *        }
 *    }
 *}
 */

int main()
{
    struct t_list_node *node = DF_NODE(1, &DF_NODE(4, &DF_NODE(5, NULL, NULL)->s_node, DF_NODE(12, &DF_NODE(15, NULL, NULL)->s_node, NULL))->s_node, NULL);

    list_t_traverse(node);
    printf("\nnew round\n");
    list_t_traverse(list_flatten(node));
    return 0;
}
