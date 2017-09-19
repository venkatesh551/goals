#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cassert>


/* Merging with smaller auxiliary array */

void merge(std::vector<int> &v, std::vector<int> &aux)
{
    int n = aux.size();
    assert(n * 2 == v.size()); // preCondition
    assert(std::is_sorted(v.begin(), v.begin() + n));
    assert(std::is_sorted(v.begin() + n, v.end()));

    for (int i = 0; i < n; ++i){
        aux[i] = v[i];
    }
    int i = 0, j = n, k = 0;
    while ( k < 2 * n) {
        if (i < n && (j >= 2 * n || aux[i] <= v[j])) {
            v[k++] = aux[i++];
        } else {
            v[k++] = v[j++];
        }
    }
    assert(std::is_sorted(v.begin(), v.end())); // postCondition
}

void printVector(std::vector<int> &v) {

    for (const auto &c: v) {
        std::cout << c << " ";
    }
    std::cout << "\n";
}


int main(int argc, char *argv[]) {

    int n = atoi(argv[1]);
    srand(time(NULL));
    std::vector<int> v(2 * n);

    for (int i = 0; i < 2 * n; ++i) {
        v[i] = rand() % 101;
    }
    std::sort(v.begin(), v.begin() + n);
    std::sort(v.begin() + n, v.end());
    std::vector<int> temp(v), aux(n);
    merge(v, aux);
    std::sort(temp.begin(), temp.end());
    assert(temp == v);
    return 0;
}

