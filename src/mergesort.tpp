#ifndef _DUNMOROGH_MERGESORT_H_
#define _DUNMOROGH_MERGESORT_H_

#include <vector>
#include <functional>

#include "types.tpp"

namespace dunmorogh {
    template<typename T>
    void merge(std::vector<T>& left, std::vector<T>& right, std::vector<T>& out, const std::function<bool(const T& a, const T& b)>& lambda) {
        const u64 leftSize = left.size();
        const u64 rightSize = right.size();

        u64 l = 0, r = 0, i = 0;
        while (l < leftSize && r < rightSize) {
            const T& firstElement = left[l];
            const T& secondElement = right[r];

            if(lambda(firstElement, secondElement)) {
                out[i] = secondElement;
                ++r;
            } else {
                out[i] = firstElement;
                ++l;
            }
            ++i;
        }

        while (l < leftSize) {
            out[i] =  left[l];
            ++l;
            ++i;
        }
        
        while (r < rightSize) {
            out[i] = right[r];
            ++r;
            ++i;
        }
    }

    template<typename T>
    void merge_sort(std::vector<T>& input, const std::function<bool(const T& a, const T& b)>& lambda) {
        const u64 length = input.size();
        const u64 middle = length / 2;

        if(length <= 1) 
            return;
        
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
