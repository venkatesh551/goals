#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <algorithm>

void selectionSort(std::vector<int> &v) {

    int n = v.size();

    for (int i = 0; i < n-1; ++i) {

        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (v[minIdx] > v[j]) {
                minIdx = j;
            }
        }
        if (i != minIdx) {
            std::swap(v[i], v[minIdx]);
        }
    }
    assert(std::is_sorted(v.begin(), v.end()));
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    int n = atoi(argv[1]);
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = rand() % 101;
    }
    selectionSort(v);

    return 0;
}
