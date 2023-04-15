#include <algorithm>
#include <vector>
#include <random>

#include "utils.h"
#include "test.h"
#include "dunmorogh.h"

int main() {
    using namespace std;
    using namespace dunmorogh;

    TEST_CASE {
        vector<int> data;
        generate_random_data(data, 50000);

        dunmorogh_sort<int>(data, std::greater<int>());

        ensure((is_container_sorted<int>(data, std::greater<int>())));
    }

    TEST_CASE {
        vector<int> data;
        generate_random_data(data, 50000);

        dunmorogh_sort<int>(data, std::less<int>());

        ensure((is_container_sorted<int>(data, std::less<int>())));
    }

    return 0;
}