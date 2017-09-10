#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

int hoaresPartition3(std::vector<int> &v, int low, int high) {

    int i = low + 1, j = high;
    int p = v[low];
    while (true) {
        while (v[i] < p)
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

int main(int argc, char *argv[]) {

    int n = std::atoi(argv[1]);
    std::vector<int> v(n);
    std::vector<int> test(n);

    for (int i = 0; i < n; ++i) {
        test[i] = v[i] = rand() % 1017 + 1;
    }
    int max_pos = 0;
    for (int i = 1; i < n; ++i) {
        if (v[i] > v[max_pos]) {
            max_pos = i;
        }
    }
    std::swap(v[max_pos], v[n-1]);
    quicksort(v, 0, n-1);
    std::sort(test.begin(), test.end());
    if (test != v) {
        std::cout << "mismatch\n";
    }
    //printVector(v);
    return 0;
}


