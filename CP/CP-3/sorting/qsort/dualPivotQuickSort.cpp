#include <iostream>
#include <vector>
#include <cstdlib>
#include <utility>

std::pair<int,int> dualPivotPartition(std::vector<int> &v, int low, int high)
{
    if (v[low] > v[high]) {
        std::swap(v[low], v[high]);
    }
    int pivot1 = v[low], pivot2 = v[high];
    int i = low + 1, lt = i, gt = high - 1;
    while ( i <= gt)
    {
        if (v[i] < pivot1) {
            std::swap(v[i++], v[lt++]);
        } else if (v[i] > pivot2) {
            std::swap(v[i], v[gt--]);
        } else{
            ++i;
        }
    }
    std::swap(v[low], v[lt-1]);
    std::swap(v[high], v[gt+1]);
    return {lt, gt};

}

void printVector(std::vector<int> &v)
{
    for (const auto &ele : v) {
        std::cout << ele << " ";
    }
    std::cout << "\n";

}

void qsort(std::vector<int> &v, int low, int high)
{
    if (high <= low) {
        return;
    }
    std::pair<int, int> res = dualPivotPartition(v, low, high);
    int lt = res.first, gt = res.second;
    qsort(v, low, lt-2);
    if (v[lt] != v[gt]) {
        qsort(v, lt, gt);
    }
    qsort(v, gt+2, high);
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    int n = atoi(argv[1]);
    std::vector<int> v(n);
    for (int i = 0; i < n ; ++i) {
        v[i] = rand() % 101;
    }
    qsort(v, 0, v.size()-1);
    // printVector(v);
    return 0;
}
