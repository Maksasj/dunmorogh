#ifndef _UTILS_H_
#define _UTILS_H_

#include <iostream>
#include <algorithm>
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

    int i, j;
    char c;
    std::string str;
    for(i = 0; i < length; i++) {
        for (j = 0; j < wordLength; j++) {
            c = rand() % 26 + 'a';
            str += c;
        }
        vec.push_back(str);
        str.clear();
    }
}

#endif