#ifndef _DUNMOROGH_DUNMOROGHSORT_H_
#define _DUNMOROGH_DUNMOROGHSORT_H_

#include <vector>
#include <functional>

#include "gnomesort.tpp"
#include "types.tpp"
#include "utils.h"

namespace dunmorogh {
    template<typename T>
    void _dunmorogh_sort_iternal(std::vector<T>& input, const std::function<bool(const T& a, const T& b)>& lambda, i32 l, i32 r) {
        if (l < r) {
            if(r - l + 1 <= (input.size() / 16)) {
                _insertion_sort_iternal(input, lambda, l, r + 1);
            } else {
                i32 m = l + (r - l) / 2;
                
                _dunmorogh_sort_iternal(input, lambda, l, m);
                _dunmorogh_sort_iternal(input, lambda, m + 1, r);
                merge(input, lambda, l, m, r);
            }
        }   
    }

    template<typename T>
    void dunmorogh_sort(std::vector<T>& input, const std::function<bool(const T& a, const T& b)>& lambda) {
        const u64 length = input.size();

        if(length <= 1) 
            return;

        f32 percentSorted = percent_sorted<T>(input, lambda);
        if(percentSorted > 0.8f) {
            gnome_sort(input, lambda);
            return;
        }
        
        _dunmorogh_sort_iternal(input, lambda, 0, input.size() - 1);
    }
}

#endif
