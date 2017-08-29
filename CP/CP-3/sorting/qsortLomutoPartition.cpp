#include <iostream>
#include <vector>
#include <algorithm>



/*   choose pivot element as last-element
 *   It works by appending all the elements less than pivot to the beginning of the array
 *   now swap the pivot element  with the 
 *   Now, array is smaller-elements < pivot <= elements
 */
int lomutoPartition1(std::vector<int> &v, int low, int high) {
    
    int pivot = v[high];
    int i = low;
    for (int j = low; j < high; ++j) {
        if (v[j] < pivot) { // append to beginning of the array
            std::swap(v[i], v[j]);
            ++i;            
        }
    }
    std::swap(v[i], v[high]);
    return i;
}

/*   choose pivot element as First-element
 *   It works by appending all the elements less than pivot to the beginning of the array
 *   now swap the pivot element  with the 
 *   Now, array is smaller-elements < pivot <= elements
 */

int lomutoPartition2(std::vector<int> &v, int low, int high) {
    
    int pivot = v[low];
    int i = low + 1;
    for (int j = low + 1; j <= high; ++j) {
        if (v[j] < pivot) { // append to beginning of the array
            std::swap(v[i], v[j]);
            i += 1;            
        }
    }
    std::swap(v[i-1], v[low]);
    return i-1;
}


void quicksort(std::vector<int> &v, int low, int high) {
    
    if (high <= low) { // single ellement is already sorted
        return;
    }
    int p = lomutoPartition2(v, low, high);
    quicksort(v, low, p-1);
    quicksort(v, p+1, high);
}

void printVector(std::vector<int> &v) {
    
    for (const auto ele : v) {
        std::cout << ele << " ";        
    }
    
    std::cout << std::endl;
}

int main() {
    
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
    quicksort(v, 0, n-1);
    printVector(v);

    return 0;
}

