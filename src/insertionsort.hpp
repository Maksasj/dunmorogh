#ifndef _DUNMOROGH_INSERTION_H_
#define _DUNMOROGH_INSERTION_H_

#include <functional>

#include "types.hpp"

namespace dunmorogh {
    template<template<class ...> class C, class T>
    inline void _insertion_sort_iternal(C<T>& input, const std::function<bool(const T& a, const T& b)>& lambda, const i32& left, const i32& right) {
        const u64 arraySize = input.size();

        for (i32 i = left + 1; i < right; ++i) {
            const T& key = input[i];
            i32 j = i - 1;
            
            while (j >= left && lambda(input[j], key)) {
                input[j + 1] = input[j];
                --j;
            }

            input[j + 1] = key;
        }
    };

    template<template<class ...> class C, class T>
    void insertion_sort(C<T>& input, const std::function<bool(const T& a, const T& b)>& lambda) {
        _insertion_sort_iternal(input, lambda, 0, input.size());
    };
}

#endif
