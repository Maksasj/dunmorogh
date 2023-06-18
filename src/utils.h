#ifndef _UTILS_H_
#define _UTILS_H_

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <random>
#include <chrono>

template<typename T>
void generate_random_data(std::vector<T>& vector, const unsigned long& length) {
    using namespace std;
    
    for(auto i = 0; i < length; ++i) 
        vector.push_back(i);

    auto rng = default_random_engine { };
    rng.seed(chrono::steady_clock::now().time_since_epoch().count());
    shuffle(vector.begin(), vector.end(), rng);
}

void generate_random_strings(std::vector<std::string> &vec, const unsigned long& wordLength, const unsigned long& length) {
    using namespace std;

    unsigned long i, j;
    char c;
    std::string str;
    for(i = 0; i < length; ++i) {
        for (j = 0; j < wordLength; ++j) {
            c = rand() % 26 + 'a';
            str += c;
        }
        vec.push_back(str);
        str.clear();
    }
}

template<typename T>
float percent_sorted(const std::vector<T>& vec, const std::function<bool(const T& a, const T& b)>& lambda) {
    int sorted = 0;

    for (size_t i = 0; i < vec.size() - 1; ++i)
        if (lambda(vec[i], vec[i+1]))
            ++sorted;

    return static_cast<float>(sorted) / (vec.size() - 1);
}

template<typename T>
inline bool is_container_sorted(std::vector<T>& container, const std::function<bool(const T&, const T&)>& lambda) {
    return std::adjacent_find(container.begin(), container.end(), lambda) == container.end();
}

#endif