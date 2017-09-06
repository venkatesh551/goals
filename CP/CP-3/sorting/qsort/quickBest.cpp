#include <iostream>
#include <vector>
#include <cassert>

void fill(std::vector<int> &v, int low, int high) {

    if (high -low <= 1)
        return;
    int mid =  (low + high)/2;
    fill(v, low, mid - 1);
    fill(v, mid + 1, high);
    std::swap(v[low], v[mid]);
}

void printVector(std::vector<int> &v) {

    for (const auto &ele : v) {
        std::cout << ele << " ";
    }
    std::cout << "\n";

}

int partition(std::vector<int> &v, int low, int high) {

    int pivot = v[low];
    int i = low+1, j = high;
    while (true) {
        while (i <= j && v[i] < pivot)
            ++i;
        while (v[j] > pivot)
            --j;
        if (i >= j) {
            std::swap(v[j], v[low]);
            return j;
        }
        std::swap(v[i++], v[j--]);
    }
    return j;
}


void qsort(std::vector<int> &v, int low, int high) {

    if (high <= low) {
        return ;
    }
    int j = partition(v, low, high);
    assert(abs(j-low) - abs(high-j) <= 1);
    qsort(v, low, j - 1);
    qsort(v, j + 1, high);
}


int main() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = 1 + i;
    }
    fill(v, 0, n-1);
//    printVector(v);
    std::vector<int> v1(v);
    qsort(v1, 0, n-1);
    return 0;
}

