#include <stdlib.h>
#include <stdio.h>

#include "list.h"

/*
 * Given a singly-linked list, remove all the elements for a given value. 
 */

struct s_list_node *
slist_remove_all_with_val_1(struct s_list_node *head, unsigned int data)
{
    if (!head) {
        return head;
    }

    if (head->data == data) {
        return slist_remove_all_with_val_1(head->next, data);
    } else {
        head->next = slist_remove_all_with_val_1(head->next, data);
        return head;
    }
}

struct s_list_node *
slist_remove_all_with_val_2(struct s_list_node *head, unsigned int data)
{
    struct s_list_node **pnode = &head;

    while (*pnode) {
        if ((*pnode)->data == data) {
            *pnode = (*pnode)->next;
        } else {
            pnode = &(*pnode)->next;
        }
    }

    return head;
}

void
slist_remove_all_with_val_3(struct s_list_node **head, unsigned int data)
{
    if (!*head) {
        return;
    }

    if ((*head)->data == data) {
        *head = (*head)->next;
        slist_remove_all_with_val_3(head, data);
    } else {
        slist_remove_all_with_val_3(&(*head)->next, data);
    }
}

void
slist_traverse(struct s_list_node *node)
{
    if (!node) {
        return;
    }

    printf("val %u\n", node->data);
    slist_traverse(node->next);
}

int main()
{
    struct s_list_node *head = DF_SL_NODE(5, DF_SL_NODE(6, DF_SL_NODE(7, DF_SL_NODE(9, DF_SL_NODE(5, DF_SL_NODE(4, DF_SL_NODE(5, NULL)))))));

    slist_traverse(head);
    printf("done 1\n");
    head = slist_remove_all_with_val_2(head, 5);
    printf("done 2\n");
    slist_traverse(head);
}
