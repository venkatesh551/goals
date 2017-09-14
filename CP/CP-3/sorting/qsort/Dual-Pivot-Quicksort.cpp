#include <iostream>
#include <vector>
#include <utility>

std::pair<int, int> dualPivotPartition(std::vector<int> &v, int low, int high)
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
    return {low + i - p, high - (q - j)};
}

void qsort(std::vector<int> &v, int low, int high)
{
    if ( high -low <= 27 ) {
        InsertionSort(v, low, high);
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
    std::vector<int> v ;
    printVector(v);
    qsort(v, 0, v.size()-1);
    printVector(v);
    return 0;
}
