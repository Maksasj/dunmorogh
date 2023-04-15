#ifndef _TEST_H_
#define _TEST_H_

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

#define ensure(EXP) if(!(EXP)) return 1;
#define TEST_CASE

template<typename T>
inline bool is_container_sorted(std::vector<T>& container, const std::function<bool(const T&, const T&)>& lambda) {
    return std::adjacent_find(container.begin(), container.end(), lambda) == container.end();
}

#endif