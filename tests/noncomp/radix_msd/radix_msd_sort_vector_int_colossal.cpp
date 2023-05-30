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
        generate_random_data(data, 1000000);

        radix_sort_msd(data);

        ensure((is_container_sorted<int>(data, greater<int>())));
    }

    return 0;
}