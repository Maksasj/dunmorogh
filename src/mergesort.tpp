#ifndef _DUNMOROGH_MERGESORT_H_
#define _DUNMOROGH_MERGESORT_H_

#include <vector>
#include <functional>

#include "types.tpp"

namespace dunmorogh {
    template<typename T>
    void merge(std::vector<T>& input, const std::function<bool(const T& a, const T& b)>& lambda, const i32& l, const i32& m, const i32& r) {
        const i32 n1 = m - l + 1;
        const i32 n2 = r - m;

       std::vector<T> L(n1), R(n2);

        for (i32 i = 0; i < n1; i++)
            L[i] = input[l + i];
        for (i32 j = 0; j < n2; j++)
            R[j] = input[m + 1 + j];

        i32 i = 0, j = 0, k = l;
        while(i < n1 && j < n2) {
            if(lambda(R[j], L[i])) {
                input[k] = L[i];
                ++i;
            } else {
                input[k] = R[j];
                ++j;
            }

            ++k;
        }

        while(i < n1)
            input[k++] = L[i++];

        while(j < n2)
            input[k++] = R[j++];
    }

    template<typename T>
    void _merge_sort_iternal(std::vector<T>& input, const std::function<bool(const T& a, const T& b)>& lambda, i32 l, i32 r) {
        if (l < r) {
            i32 m = l + (r - l) / 2;
            _merge_sort_iternal(input, lambda, l, m);
            _merge_sort_iternal(input, lambda, m + 1, r);
            merge(input, lambda, l, m, r);
        }   
    }

    template<typename T>
    void merge_sort(std::vector<T>& input, const std::function<bool(const T& a, const T& b)>& lambda) {
        if(input.size() <= 1) {
            return;
        }

        _merge_sort_iternal(input, lambda, 0, input.size() - 1);
    }
}

#endif
