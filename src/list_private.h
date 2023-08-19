#ifndef UPO_LIST_PRIVATE_H
#define UPO_LIST_PRIVATE_H

#include <upo/list.h>

/**
 * @brief
 *
 */
struct upo_list_node_s
{
    void *value; // Any type of value (generic pointer)
    struct upo_list_node_s *next;
};

/**
 * @brief
 *
 */
typedef struct upo_list_node_s upo_list_node_t;

/**
 * @brief
 *
 */
struct upo_list_s
{
    upo_list_node_t *head;
    size_t size;
    upo_list_comparator_t cmp;
};

/**
 * @brief Create a node object
 *
 * @param value
 * @return void*
 */
static void *create_node(void *value);

#endif