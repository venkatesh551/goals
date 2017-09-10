#include <iostream>
#include <vector>
#include <utility>

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

void qsort(std::vector<int> &v, int low, int high)
{
    if ( high <= low ) {
        return;
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

int main()
{
    // std::vector<int> v = {2, 4, 2, 7, 2};
    // std::vector<int> v = {3, 2, 1, 3, 2, 6, 2, 4, 5} ;
    std::vector<int> v = {2, 3, 4, 2, 2, 1};
    printVector(v);
    qsort(v, 0, v.size()-1);
    printVector(v);
    return 0;
}
