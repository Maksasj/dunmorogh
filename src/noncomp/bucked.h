#ifndef _DUNMOROGH_BUCKET_H_
#define _DUNMOROGH_BUCKET_H_

#include <functional>
#include <algorithm>

#include "../types.hpp"

namespace dunmorogh {
    /**
     * @tparam T - i8, i16, i32, i64, u8, u16, u32, u64 
     */
    template<typename T>
    inline void bucket_sort(std::vector<T>& input) {
        const T maxElement = *std::max_element(input.begin(), input.end());

        std::vector<T> buckets(maxElement + 1, 0);

        for(auto& i : input)
            ++buckets[i];

        i32 index = 0;
        for(i32 i = 0; i < buckets.size(); ++i)
            for(i32 j = 0; j < buckets[i]; ++j)
                input[index++] = i;
    };
}

#endif
