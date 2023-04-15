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
        vector<string> data;
        generate_random_strings(data, 5, 1000);

        merge_sort<string>(data, std::greater<string>());

        ensure((is_container_sorted<string>(data, std::greater<string>())));
    }

    TEST_CASE {
        vector<string> data;
        generate_random_strings(data, 5, 1000);

        merge_sort<string>(data, std::less<string>());

        ensure((is_container_sorted<string>(data, std::less<string>())));
    }

    return 0;
}