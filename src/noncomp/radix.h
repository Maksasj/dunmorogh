#ifndef _DUNMOROGH_RADIX_H_
#define _DUNMOROGH_RADIX_H_

#include <functional>
#include <algorithm>

#include "../types.hpp"

namespace dunmorogh {
    /**
     * @tparam T - i8, i16, i32, i64, u8, u16, u32, u64 
    */
    template<typename T>
    inline void radix_sort_lsd(std::vector<T>& input) {
        if(input.empty()) return;
    
        const T maxElement = *std::max_element(input.begin(), input.end());

        for(i32 exp = 1; (maxElement / exp) > 0; exp *= 10) {
            std::vector<T> out(input.size());
            std::vector<i32> count(10, 0);

            for(i32 i = 0; i < input.size(); ++i) {
                i32 digit = (input[i] / exp) % 10;
                ++count[digit];
            }

            for(int i = 1; i < count.size(); ++i) {
                count[i] += count[i - 1];
            }

            for(int i = input.size() - 1; i >= 0; --i) {
                i32 digit = (input[i] / exp) % 10;
                out[count[digit] - 1] = input[i];
                --count[digit];
            }

            for(int i = 0; i < input.size(); ++i) {
                input[i] = out[i];
            }
        }
    };

    /**
     * @tparam T - i8, i16, i32, i64, u8, u16, u32, u64 
    */
    template<typename T>
    inline void radix_sort_msd(std::vector<T>& input) {
        if(input.empty()) return;
    
        const T maxElement = *std::max_element(input.begin(), input.end());

        i32 digit = 1;
        while(maxElement / digit > 0) {
            std::vector<i32> bucket[10];

            for(auto& i : input) {
                i32 index = (i / digit) % 10;
                bucket[index].push_back(i);
            }

            i32 index = 0;
            for(i32 j = 0; j < 10; ++j) {
                for(auto& i : bucket[j]) {
                    input[index++] = i;
                }
            }

            digit *= 10;
        }
    };
}

#endif
