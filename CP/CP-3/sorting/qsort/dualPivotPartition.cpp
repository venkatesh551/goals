#include <iostream>
#include <vector>
#include <cstdlib>

void dualPivotPartition(std::vector<int> &v, int low, int high)
{
    if (v[low] > v[high]) {
        std::swap(v[low], v[high]);
    }
    int pivot1 = v[low], pivot2 = v[high];
    int i = low + 1, j = high - 1;

    for (int k = i; k <= j; ++k) // move one element at a time to its correct position
    {
        if (v[k] < pivot1) {
            std::swap(v[k], v[i++]);
        } else if (v[k] > pivot2) {
            while (k < j && v[j] > pivot2) {
                j--;
            }
            std::swap(v[k], v[j--]);
            if (v[k] < pivot1) {
                std::swap(v[k], v[i++]);
            }
        }
    }
    std::swap(v[low], v[i-1]);
    std::swap(v[high], v[j+1]);

}

void printVector(std::vector<int> &v)
{
    for (const auto &ele : v) {
        std::cout << ele << " ";
    }
    std::cout << "\n";

}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    int n = atoi(argv[1]);
    std::vector<int> v(n);
    for (int i = 0; i < n ; ++i) {
        v[i] = rand() % 101;
    }
//    printVector(v);
    dualPivotPartition(v, 0, v.size()-1);
//    printVector(v);
    return 0;
}
