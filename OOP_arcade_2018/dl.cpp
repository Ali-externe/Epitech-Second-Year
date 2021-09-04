/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** dl
*/

#include "include/dl.hpp"

void *dl::open_dl(char *lib)
{
    this->dl_ret = dlopen(lib, RTLD_LAZY);
    if (this->dl_ret == NULL)
        return (nullptr);
    return (this->dl_ret);
}

void dl::close_dl(void *lib)
{
    dlclose(lib);
}

void *dl::get_sym(void *handle, char *sym)
{
    return (dlsym(handle, sym));
}