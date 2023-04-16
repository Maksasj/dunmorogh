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
        generate_random_data(data, 1000);

        gnome_sort<vector, int>(data, greater<int>());

        ensure((is_container_sorted<int>(data, greater<int>())));
    }

    TEST_CASE {
        vector<int> data;
        generate_random_data(data, 1000);

        gnome_sort<vector, int>(data, less<int>());

        ensure((is_container_sorted<int>(data, less<int>())));
    }

    return 0;
}