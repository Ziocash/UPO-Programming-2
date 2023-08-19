#ifndef UPO_LIST_H
#define UPO_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * @brief Pointer to list structure.
 */
typedef struct upo_list_s *upo_list_t;

/**
 * @brief Pointer to comparison function.
 */
typedef int (*upo_list_comparator_t)(const void *, const void *);

/**
 * @brief Create a list using the given comparison function
 * 
 * @param cmp Comparison function
 * @return void*
 */
void *upo_list_create(upo_list_comparator_t cmp);

void upo_list_clear(upo_list_t list, int destroy_data);

void upo_list_destroy(upo_list_t list, int destroy_data);

int upo_list_is_empty(upo_list_t list);

void upo_list_append(upo_list_t list, void *value);

void upo_list_insert_before(upo_list_t list, void *value, const void *val_after);

void upo_list_insert_after(upo_list_t list, void *value, const void *val_before);

size_t upo_list_size(upo_list_t list);

void *upo_list_get_value(upo_list_t list, size_t index);

#endif