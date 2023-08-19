#include <assert.h>
#include "list_private.h"
#include <stdio.h>
#include <stdlib.h>

void *create_node(void *value)
{
    upo_list_node_t *node = malloc(sizeof(upo_list_node_t));
    if (node == NULL)
    {
        perror("Error allocating memory");
        abort();
    }
    node->value = value;
    node->next = NULL;
    return node;
}

void *upo_list_create(upo_list_comparator_t key_cmp)
{
    assert(key_cmp != NULL);
    upo_list_t list = malloc(sizeof(struct upo_list_s));
    if (list == NULL)
    {
        perror("Error allocating list");
        abort();
    }
    list->head = NULL;
    list->size = 0;
    list->cmp = key_cmp;
    return list;
}

void upo_list_clear(upo_list_t list, int destroy_data)
{
    if (upo_list_is_empty(list))
        return;
    upo_list_node_t *head = list->head;
    while (head != NULL)
    {
        upo_list_node_t *node = head;
        head = head->next;
        if (destroy_data)
            free(node->value);
        free(node);
    }
    list->head = NULL;
    list->size = 0;
}

void upo_list_destroy(upo_list_t list, int destroy_data)
{
    if (!upo_list_is_empty(list))
        upo_list_clear(list, destroy_data);
    free(list);
    list = NULL;
}

int upo_list_is_empty(upo_list_t list)
{
    if (list == NULL)
        return 1;
    if (list->head == NULL)
        return 1;

    return 0;
}

void upo_list_append(upo_list_t list, void *value)
{
    if (list == NULL)
        return;
    if (upo_list_is_empty(list))
    {
        upo_list_node_t *node = create_node(value);
        list->head = node;
        list->size += 1;
    }
    else
    {
        upo_list_node_t *node = list->head;

        while (node->next != NULL)
            node = node->next;

        node->next = create_node(value);
        list->size += 1;
    }
}

void upo_list_insert_before(upo_list_t list, void *value, const void *val_after)
{
    if (list == NULL)
        return;

    upo_list_comparator_t cmp = list->cmp;
    upo_list_node_t *node = list->head;
    upo_list_node_t *previous = NULL;

    while (node->next != NULL)
    {
        if (cmp(node->value, val_after) == 0)
            break;
        previous = node;
        node = node->next;
    }
    if (cmp(node->value, val_after) == 0)
    {
        if (previous != NULL)
        {
            upo_list_node_t *old_list = previous->next;
            upo_list_node_t *new_node = create_node(value);
            previous->next = new_node;
            new_node->next = old_list;
        }
        else
        {
            list->head = create_node(value);
            list->head->next = node;
        }
        list->size++;
    }
}

void upo_list_insert_after(upo_list_t list, void *value, const void *val_before)
{
    if (list == NULL)
        return;

    upo_list_comparator_t cmp = list->cmp;
    upo_list_node_t *node = list->head;

    if (node == NULL)
    {
        upo_list_append(list, value);
        return;
    }

    while (node != NULL || cmp(node->value, val_before) != 0)
    {
        node = node->next;
    }
    if (node != NULL)
    {
        upo_list_node_t *new_node = create_node(value);
        node->next = new_node;
    }
}

size_t upo_list_size(upo_list_t list)
{
    if (list == NULL)
        return 0;
    if (list->head == NULL)
        return 0;
    return list->size;
}

void *upo_list_get_value(upo_list_t list, size_t index)
{
    if(list == NULL)
        return NULL;

    size_t count = upo_list_size(list);
    assert(index < count);

    upo_list_node_t *node = list->head;
    for(size_t i = 0; i < count; i++)
    {
        if(i == index)
            return node->value;
        node = node->next;
    }
    return NULL;
}