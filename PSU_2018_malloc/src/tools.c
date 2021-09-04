/*
** EPITECH PROJECT, 2019
** PSU_2018_malloc
** File description:
** new_malloc
*/
#include "malloc.h"

data_field_t *get_data_field(void *ptr)
{
    char *ptr_in_char = ptr;
    ptr_in_char -= sizeof(data_field_t);
    return ((void*)ptr_in_char);
}

data_field_t *get_set_head(data_field_t *new_head)
{
    static data_field_t *head = NULL;
    if (new_head)
        head = new_head;
    return (head);
}

data_field_t *get_last_elem(data_field_t *head)
{
    while (head && head->next)
        head = head->next;
    return (head);
}

size_t allign_size(size_t size)
{
    return ((size - 1) / 4 * 4 + 4);
}

data_field_t *find_in_list(data_field_t *head, size_t size)
{
    while (head) {
        if (head->is_free == TRUE && head->size >= size) {
            head->is_free = FALSE;
            return (head);
        }
        head = head->next;
    }
    return (NULL);
}