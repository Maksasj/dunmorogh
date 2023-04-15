#ifndef _DUNMOROGH_DUNMOROGHSORT_H_
#define _DUNMOROGH_DUNMOROGHSORT_H_

#include <vector>
#include <functional>

#include "gnomesort.tpp"
#include "types.tpp"
#include "utils.h"

namespace dunmorogh {
    template<typename T>
    void dunmorogh_sort(std::vector<T>& input, const std::function<bool(const T& a, const T& b)>& lambda) {
        const u64 length = input.size();
        const u64 middle = length / 2;

        if(length <= 1) 
            return;

        f32 percentSorted = percent_sorted<T>(input, lambda);
        if(percentSorted > 0.6f) {
            gnome_sort(input, lambda);
            return;
        }

        std::vector<T> left;
        std::vector<T> right;

        for(i32 i = 0; i < length; i++) {
            if(i < middle)
                left.push_back(input[i]);
            else
                right.push_back(input[i]);
        }

        merge_sort(left, lambda);
        merge_sort(right, lambda);

        merge(left, right, input, lambda);
    }
}

#endif
