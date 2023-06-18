#ifndef _DUNMOROGH_GNOMESORT_H_
#define _DUNMOROGH_GNOMESORT_H_

#include <functional>
#include "types.hpp"

namespace dunmorogh {
    template<template<class ...> class C, class T, class L>
    void gnome_sort(C<T>& input, const L& lambda) {
        size_t i = 0;
        while(i < input.size()) {
            if(i == 0 || lambda(input[i], input[i - 1]))
                ++i;
            else {
                std::swap(input[i], input[i - 1]);
                --i;
            }
        }
    };
}

#endif
