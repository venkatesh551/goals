#include <iostream>
#include <vector>
#include <algorithm>

int hoaresPartition3(std::vector<int> &v, int low, int high) {

    int i = low + 1, j = high;
    int p = v[low];
    while (true) {
        while (i <= j && v[i] < p)
            ++i;
        while (v[j] > p)
            --j;
        if (i >= j) {
            std::swap(v[low], v[j]);
            return j;
        }
        std::swap(v[i], v[j]);
        ++i; --j;
    }
    return j;
}


void quicksort(std::vector<int> &v, int low, int high) {

    if (high <= low) { // single element is already sorted
        return;
    }
    int p = hoaresPartition3(v, low, high);
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

