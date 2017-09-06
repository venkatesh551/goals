#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>


std::pair<int, int> threeWayPartition(std::vector<int> &v, int pivot, int low, int high) {

    int i = low, j = low, n = high;

    while (j <= n) {
        if (v[j] < pivot){
            std::swap(v[i], v[j]);
            ++i, ++j;
        } else if (v[j] > pivot) {
            std::swap(v[j], v[n]);
            n--;
        } else {
            ++j;
        }
    }
    return std::make_pair(i, n);
}

void printVector(std::vector<int> &v)
{
    for (const auto &ele: v) {
        std::cout << ele << " ";
    }
    std::cout <<  "\n";
}


void quicksort(std::vector<int> &v, int low, int high) {

    if (high <= low) {
        return;
    }
    int pivotele = v[low];
    std::pair<int, int>  p = threeWayPartition(v, pivotele, low, high);
    quicksort(v, low, p.first-1);
    quicksort(v, p.second+1, high);

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


