#include <vector>

#include "dunmorogh.h"
#include "utils.h"

int main() {
    using namespace std;
    using namespace dunmorogh;

    vector<int> data;
    generate_random_data(data, 10);

    for(int& i : data)
        cout << i << " ";

    cout << "\n";
    merge_sort<vector, int>(data, greater<int>());

    for(int& i : data)
        cout << i << " ";
    
    return 0;
}