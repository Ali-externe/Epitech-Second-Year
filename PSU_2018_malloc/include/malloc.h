/*
** EPITECH PROJECT, 2019
** PSU_2018_malloc
** File description:
** new_malloc
*/
#pragma once
#include <unistd.h>

enum Bool {
    TRUE,
    FALSE
};

typedef struct s_data_field {
    size_t size;
    enum Bool is_free;
    struct s_data_field *prev;
    struct s_data_field *next;
    void *ptr_to_data;
    char data[8];
}   data_field_t;

data_field_t *get_more_heap(size_t size, data_field_t *prev);
void *malloc(size_t size);
void free(void *ptr);
void copy_data(int *ptr1, int *ptr2, size_t size);
void *realloc(void *ptr, size_t size);
data_field_t *get_data_field(void *ptr);
data_field_t *get_set_head(data_field_t *new_head);
data_field_t *get_last_elem(data_field_t *head);
size_t allign_size(size_t size);
data_field_t *find_in_list(data_field_t *head, size_t size);
