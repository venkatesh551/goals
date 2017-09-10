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
        while (i <= j && v[i] <= pivot){
            if (v[i] == pivot) {
                std::swap(v[p], v[i]);
                ++p;
            }
            ++i;
        }
        while (i <= j && v[j] >= pivot) {
            if (v[j] == pivot) {
                std::swap(v[j], v[q]);
                --q;
            }
            --j;
        }
        if (i >= j) {
            break;
        }
        std::swap(v[i++], v[j--]);
    }
    int pivotCount = high - q + p - low;
    int start = low;
    for (int k = p; k < i; ++k) {
        v[start++] = v[k];
    }
    int end = high;
    for (int k = q ; k > j; --k){
        v[end--] = v[k];
    }
    for (int k = 0; k < pivotCount; ++k) {
        v[start++] = pivot;
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
    std::vector<int> v = {3, 2, 1, 3, 2, 6, 2, 4, 5} ;
    printVector(v);
    qsort(v, 0, v.size()-1);
    printVector(v);
    return 0;
}
