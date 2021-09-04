/*
** EPITECH PROJECT, 2019
** PSU_2018_malloc
** File description:
** new_malloc
*/

#include "malloc.h"
#include "stdio.h"

data_field_t *get_more_heap(size_t size, data_field_t *prev)
{
    data_field_t *new_node = sbrk(0);

    if (sbrk(size + sizeof(data_field_t)) == (void*) -1)
        return (NULL);
    new_node->is_free = FALSE;
    new_node->size = size;
    new_node->prev = prev;
    new_node->ptr_to_data = &new_node->data[8];
    if (prev)
        prev->next = new_node;
    new_node->next = NULL;
    return (new_node);
}

void *malloc(size_t size)
{
    data_field_t *head = get_set_head(NULL);
    data_field_t *temp = NULL;

    size = allign_size(size);
    if (!head) {
        get_set_head(get_more_heap(size, NULL));
        return (get_set_head(NULL)->ptr_to_data);
    }
    temp = find_in_list(head, size);
    if (temp)
        return (temp->ptr_to_data);
    temp = get_more_heap(size, get_last_elem(head));
    if (!temp)
        return (NULL);
    return (temp->ptr_to_data);
}

void free(void *ptr)
{
    data_field_t *temp = NULL;

    if (!ptr)
        return ;
    temp = get_data_field(ptr);
    if (ptr == temp->ptr_to_data) {
        temp->is_free = TRUE;
    }
    if (temp->next == NULL)
        brk(temp);
}

void copy_data(int *ptr1, int *ptr2, size_t size)
{
    for (size_t i = 0; i * 4 != size; i += 1)
        ptr2[i] = ptr1[i];
}

void *realloc(void *ptr, size_t size)
{
    data_field_t *temp = NULL;
    data_field_t *new_node = NULL;

    size = allign_size(size);
    if (!ptr || size == 0)
        return (malloc(size));
    if (size == 0 && ptr)
        return (NULL);
    temp = get_data_field(ptr);
    new_node = find_in_list(get_set_head(NULL), size);
    if (!new_node)
        new_node = get_more_heap(size, get_last_elem(get_set_head(NULL)));
    copy_data((int*)temp->ptr_to_data, (int*)new_node->data, size);
    free(temp->ptr_to_data);
    return (new_node->ptr_to_data);
}
