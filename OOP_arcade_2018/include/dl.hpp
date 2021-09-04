/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** dl
*/

#ifndef DL_HPP_
#define DL_HPP_

#include <dlfcn.h>
#include <iostream>

class dl {
    public:
        dl(){};
		~dl(){};
        void *open_dl(char * lib);
        void close_dl(void * lib);
        void *get_sym(void *handle, char * sym);
        void *dl_ret;
    protected:
    private:
};


#endif /* !DL_HPP_ */
