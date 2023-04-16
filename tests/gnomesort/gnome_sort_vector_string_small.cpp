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
        generate_random_strings(data, 5, 10);

        gnome_sort<vector, string>(data, greater<string>());

        ensure((is_container_sorted<string>(data, greater<string>())));
    }

    TEST_CASE {
        vector<string> data;
        generate_random_strings(data, 5, 10);

        gnome_sort<vector, string>(data, less<string>());

        ensure((is_container_sorted<string>(data, less<string>())));
    }

    return 0;
}