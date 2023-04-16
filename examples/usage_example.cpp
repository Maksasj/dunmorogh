#include <vector>
#include <string>

#include "dunmorogh.h"
#include "utils.h"

int main() {
    using namespace std;
    using namespace dunmorogh;
    
    {   /* Merge sort */
        vector<int> data;
        generate_random_data(data, 100);

        merge_sort<vector, int>(data, greater<int>());

        bool isSorted = is_container_sorted<int>(data, greater<int>()); 
        cout << "Merge sort: " << isSorted << "\n"; // Merge sort: 1
    }

    {   /* Merge sort */
        vector<int> data;
        generate_random_data(data, 100);

        insertion_sort<vector, int>(data, greater<int>());
        
        bool isSorted = is_container_sorted<int>(data, greater<int>()); 
        cout << "Insertion sort: " << isSorted << "\n"; // Insertion sort: 1
    }

    {   /* Merge sort */
        vector<int> data;
        generate_random_data(data, 100);

        gnome_sort<vector, int>(data, greater<int>());
        
        bool isSorted = is_container_sorted<int>(data, greater<int>()); 
        cout << "Gnome sort: " << isSorted << "\n"; // Gnome sort: 1
    }

    {   /* Merge sort */
        vector<int> data;
        generate_random_data(data, 100);

        dunmorogh_sort<vector, int>(data, greater<int>());
        
        bool isSorted = is_container_sorted<int>(data, greater<int>()); 
        cout << "Dunmorogh sort: " << isSorted << "\n"; // Dunmorogh sort: 1
    }

    return 0;
}