#include <iostream>
#include <vector>
#include <algorithm>

/*
 * Hoare's scheme is more efficient than Lomuto's partition 
 * scheme because it does three times fewer swaps on average, 
 * and it creates efficient partitions even when all values are equal
 * 
 * the pivot's final location is not necessarily at the 
 * index that was returned, and the next two segments that the 
 * main algorithm recurs on are (lo..p) and (p+1..hi) 
 * as opposed to (lo..p-1) and (p+1..hi) as in Lomuto's scheme
 */

/*
    example case where retured position is not pivot position
    4 1 3 2 5 6
    choose pivot as 4 ; after parttion 
    index returned is 2, pivot position is 3 
    
    another example : 5 5 4 6 1 2 3 choose pivot as 5
*/

int hoaresPartition(std::vector<int> &v, int low, int high) {

    int i = low - 1, j = high + 1;
    int p = v[high];
    while (true) {
        while (v[++i] < p)
            ;
        while (v[--j] > p)
            ;
        if (i >= j) {
            return i-1;
        }
        std::swap(v[i], v[j]);
    }
    return i-1;
}


void quicksort(std::vector<int> &v, int low, int high) {

    if (high <= low) { // single element is already sorted
        return;
    }
    int p = hoaresPartition(v, low, high);
    quicksort(v, low, p);
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

