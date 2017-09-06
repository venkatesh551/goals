#include <iostream>
#include <algorithm>
#include <vector>

/*
 * Dutch National flag algorithm 
 *
 */

void threeWayPartition(std::vector<int> &v, int pivot)
{
    int n = v.size();
    int low = 0, j = 0, high = n - 1;

    while (j <= high) {
        if (v[j] < pivot) {
            std::swap(v[j], v[low]);
            low++, ++j;
        } else if (v[j] > pivot) {
            std::swap(v[j], v[high]);
            high--;
        } else {
            ++j;
        }
    }

}

void printVector(std::vector<int> &v) {
    for (auto ele: v) {
        std::cout << ele << " ";
    }
    std::cout << "\n";
}

int main() {

    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
    threeWayPartition(v, v[0]);
    printVector(v);

    return 0;
}


