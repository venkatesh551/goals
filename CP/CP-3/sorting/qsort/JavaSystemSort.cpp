#include <iostream>
#include <vector>
#include <utility>
#include <cassert>
#include <algorithm>

std::pair<int, int> fast_3_WayPartition(std::vector<int> &v, int low, int high)
{
    int i = low + 1, j = high;
    int p = low + 1, q = high;
    int pivot = v[low];

    while (true)
    {
        while (i <= j && v[i] < pivot){
            ++i;
        }
        while (v[j] > pivot) {
            --j;
        }
        if (i == j && v[i] == pivot) {
            std::swap(v[i++], v[p++]);
        }
        if (i >= j) {
            break;
        }
        std::swap(v[i], v[j]);
        if (v[i] == pivot) {
            std::swap(v[p++], v[i]);
        }
        if (v[j] == pivot) {
            std::swap(v[q--], v[j]);
        }
        ++i, --j;
    }
    // inplace swap :
    // First equal elements - smaller elements
    int y = i-1;
    for (int k = low; k < p; ++k) {
        std::swap(v[k], v[y--]);
    }
    // greater elements - equal elements
    int x = j + 1;
    for (int k = high; k > q; --k) {
        std::swap(v[k], v[x++]);
    }
    return {low + i - p, high - (q - j)};
}

void InsertionSort(std::vector<int> &v, int low, int high) {

    for (int i = low + 1; i <= high; ++i) {
        int ele = v[i];
        int j = i - 1;
        while (j >= low && ele < v[j]) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = ele;
    }
}

int median3(std::vector<int> &v, int i, int j, int k)
{
    if (v[i] > v[j]) {
        std::swap(v[i], v[j]);
    }
    if (v[i] > v[k]) {
        std::swap(v[i], v[k]);
    }
    if (v[j] > v[k]) {
        std::swap(v[j], v[k]);
    }
    return j;

}

void qsort(std::vector<int> &v, int low, int high)
{
    int n = high - low + 1;
    if ( n <=  10) {
        InsertionSort(v, low, high);
        return;
    } else if ( n <= 20) {
        int eps = n / 8;
        int mid = low + (high - low)/2;
        int m1 = median3(v, low, low + eps, low + 2 * eps);
        int m2 = median3(v, mid - eps, mid, mid + eps);
        int m3 = median3(v, high, high - eps, high - 2 * eps);
        int ninther = median3(v, m1, m2, m3);
        std::swap(v[ninther], v[low]);
    }

    std::pair<int, int> p =  fast_3_WayPartition(v, low, high);
    qsort(v, low, p.first-1);
    qsort(v, p.second + 1, high);
}

void printVector(std::vector<int> &v)
{
    for (const auto ele: v) {
        std::cout << ele << " ";
    }
    std::cout << "\n";
}

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = i;
    }
    std::vector<int> p(v);
    std::random_shuffle(v.begin(), v.end());
    printVector(v);
    qsort(v, 0, v.size()-1);
    assert(v == p);
    return 0;
}

