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
    int p = i, q = j;

    while (i <= j)
    {
        if (v[i] < pivot1) {
            std::swap(v[p++], v[i++]);
        } else if (v[i] > pivot2) {
            std::swap(v[j], v[i]);
        } else {
            ++i;
        }

        if (v[j] > pivot2) {
            std::swap(v[j--], v[q--]);
        }
        else if (v[j] < pivot1) {
            std::swap(v[j], v[i]);
        } else {
            --j;
        }
    }
    std::swap(v[low], v[p-1]);
    std::swap(v[high], v[q+1]);

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
    printVector(v);
    dualPivotPartition(v, 0, v.size()-1);
    printVector(v);
    return 0;
}
