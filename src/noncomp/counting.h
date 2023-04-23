#ifndef _DUNMOROGH_COUNTING_H_
#define _DUNMOROGH_COUNTING_H_

#include <functional>
#include <algorithm>

#include "../types.hpp"

namespace dunmorogh {
    /**
     * @tparam T - i8, i16, i32, i64, u8, u16, u32, u64 
    */
    template<typename T>
    inline void counting_sort(std::vector<T>& input) {
        const T max = *std::max_element(input.begin(), input.end());
        const T min = *std::min_element(input.begin(), input.end());
        const T range = max - min + 1;

        std::vector<i32> count(range);
        std::vector<T> out(input.size());

        for(auto& i : input)
            ++count[i - min];

        for(i32 i = 1; i < count.size(); ++i)
            count[i] += count[i - 1];

        for(i32 i = input.size() - 1; i >= 0; --i) {
            out[count[input[i] - min] - 1] = input[i];
            --count[input[i] - min];
        }

        for(i32 i = 0; i < input.size(); ++i)
            input[i] = out[i];
    };
}

#endif
