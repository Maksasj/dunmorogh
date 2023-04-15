#ifndef _DUNMOROGH_INSERTION_H_
#define _DUNMOROGH_INSERTION_H_

#include "types.tpp"

namespace dunmorogh {
    template<typename T>
    void insertion_sort(std::vector<T>& input, const std::function<bool(const T& a, const T& b)>& lambda) {
        const u64 arraySize = input.size();

        for (i32 i = 1; i < arraySize; ++i) {
            const T& key = input[i];
            i32 j = i - 1;
            
            while (j >= 0 && lambda(input[j], key)) {
                input[j + 1] = input[j];
                --j;
            }

            input[j + 1] = key;
        }
    };
}

#endif
