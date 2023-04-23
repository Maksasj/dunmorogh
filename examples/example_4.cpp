#include <vector>
#include <string>

#include "dunmorogh.h"
#include "utils.h"

int main() {
    using namespace std;
    using namespace dunmorogh;

    vector<int> data;
    generate_random_data(data, 10);

    for(auto& i : data) {
        std::cout << i << " ";
    }

    std::cout << "\n";

    radix_sort_msd(data);

    for(auto& i : data) {
        std::cout << i << " ";
    }
    
    return 0;
}