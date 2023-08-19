# UPO-Programming-2

C list concepts and improvements for students and developers.

## Linked list

A linked list is an **Abstract Data Type** (or ADT) which performs literally a list of elements.

It's called **linked** for its own particular structure:

```c
// defined in list_private.h, part of private implementation

struct upo_list_node_s
{
    void *value; // Any type of value (generic pointer)
    struct upo_list_node_s *next; // Pointer to next value
};

typedef struct upo_list_node_s upo_list_node_t; // Aliasing for struct

// List structure
struct upo_list_s 
{
    upo_list_node_t *head; // Pointer to head node
    size_t size; // List size
    upo_list_comparator_t cmp; // Pointer containing comparison function
};
```
