#include <vector>
#include <string>

#include "dunmorogh.h"
#include "utils.h"

int main() {
    using namespace std;
    using namespace dunmorogh;

    vector<string> data;
    generate_random_strings(data, 5, 10);

    for(auto& i : data)
        cout << i << " ";

    cout << "\n";
    merge_sort<vector, string>(data, greater<string>());

    for(auto& i : data)
        cout << i << " ";
    
    return 0;
}