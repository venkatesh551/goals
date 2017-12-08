#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <cassert>


void shellsort(std::vector<int> &v) {

    int n = v.size();
    int h = 1;

    while (h < n/3){
        h =  3 * h + 1;
    }

    while (h >= 1) {
        for (int i = h; i < n; ++i) {
            for (int j = i; j >= h && v[j] < v[j-h]; j -= h) {
                std::swap(v[j], v[j-h]);
            }
        }
        h /= 3;
    }
    assert(std::is_sorted(v.begin(), v.end()));
}


int main(int argc, char *argv[]) {

    int n = atoi(argv[1]);
    std::vector<int> v(n);
    srand(time(NULL));
    for (int i = 0; i< n; ++i) {
        v[i] = rand() % 10001;
    }
    shellsort(v);
    return 0;
}


