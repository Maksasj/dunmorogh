#include <vector>
#include <string>

#include "dunmorogh.h"
#include "utils.h"

int main() {
    using namespace std;
    using namespace dunmorogh;

    vector<int> data;
    generate_random_data(data, 10);

    dunmorogh_sort<int>(data, std::greater<int>());
    
    return 0;
}