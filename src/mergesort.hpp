#ifndef _DUNMOROGH_MERGESORT_H_
#define _DUNMOROGH_MERGESORT_H_

#include <vector>
#include <functional>

#include "types.hpp"

namespace dunmorogh {
    template<template<class ...> class C, class T, class L>
    void merge(C<T>& input, const L& lambda, const i32& l, const i32& m, const i32& r) {
        const i32 n1 = m - l + 1;
        const i32 n2 = r - m;

       std::vector<T> Left(n1), Right(n2);

        for (i32 i = 0; i < n1; i++)
            Left[i] = input[l + i];
        for (i32 j = 0; j < n2; j++)
            Right[j] = input[m + 1 + j];

        i32 i = 0, j = 0, k = l;
        while(i < n1 && j < n2) {
            if(lambda(Right[j], Left[i])) {
                input[k] = Left[i];
                ++i;
            } else {
                input[k] = Right[j];
                ++j;
            }

            ++k;
        }

        while(i < n1)
            input[k++] = Left[i++];

        while(j < n2)
            input[k++] = Right[j++];
    }

    template<template<class ...> class C, class T, class L>
    void _merge_sort_iternal(C<T>& input, const L& lambda, i32 l, i32 r) {
        if (l < r) {
            i32 m = l + (r - l) / 2;
            _merge_sort_iternal(input, lambda, l, m);
            _merge_sort_iternal(input, lambda, m + 1, r);
            merge(input, lambda, l, m, r);
        }   
    }

    template<template<class ...> class C, class T, class L>
    void merge_sort(C<T>& input, const L& lambda) {
        if(input.size() <= 1) {
            return;
        }

        _merge_sort_iternal(input, lambda, 0, input.size() - 1);
    }
}

#endif
