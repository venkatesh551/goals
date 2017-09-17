#include <iostream>
#include <vector>
#include <cassert>
#include <cstdlib>

/*

Firstly, three pivots (p, q, and r) are chosen and sorted in increasing order.
    p < q < r
Then, the array is traversed and partitioned into four subarrays
*/

void sortThreeElements(std::vector<int> &v, int i, int j, int k)
{
    if (v[i] > v[j]) {
        std::swap(v[i], v[j]);
    }
    if (v[i] > v[k]) {
        std::swap(v[i], v[k]);
    }
    if (v[j] > v[k]) {
        std::swap(v[j], v[k]);
    }
}

void InsertionSort(std::vector<int> &v, int low, int high) {

    for (int i = low+1; i <= high; ++i) {
        int p = v[i];
        int j = i - 1;
        while (j >= low && p < v[j]) {
            v[j+1] = v[j];
            j -= 1;
        }
        v[j+1] = p;
    }
}

bool issorted(std::vector<int> &v)
{
    int i = 0, n = v.size();
    for (i = 1; i < n && (v[i-1] <= v[i]); ++i)
        ;
    return (i == n);
}


void qsortThreePivotPartition(std::vector<int> &v, int left, int right) {

    if (right - left <= 10) {
        InsertionSort(v, left, right);
        return;
    }

    int mid = left + (right - left)/2;
    sortThreeElements(v, left, mid, right);
    std::swap(v[mid], v[left+1]);
    int p = v[left], q = v[left+1], r = v[right];
    assert(p <= q && q <= r);
    int a = left + 2, b = left + 2, c = right - 1, d = right - 1;

    while (true) {
        while (b <= c && v[b] < q) {
            if (v[b] < p) {  // elements < p
                std::swap(v[b], v[a++]);
            }
            b++;  // >= p && < q
        }
        while (b <= c && v[c] >= q) {
            if (v[c] > r) {
                std::swap(v[c], v[d--]);
            }
            c--; // >= q && <= r
        }
        if (b >= c) {
            break;
        }
        std::swap(v[b], v[c]);
    }
    a--; b--; d++;
    std::swap(v[left+1], v[a]);// move q 
    std::swap(v[a], v[b]); // move 
    a--;
    std::swap(v[left], v[a]); // move p
    std::swap(v[d], v[right]); // move rightmost element
    qsortThreePivotPartition(v, left, a-1);
    qsortThreePivotPartition(v, a + 1, b-1);
    qsortThreePivotPartition(v, b + 1, d-1);
    qsortThreePivotPartition(v, d + 1, right);

}

void printVector(std::vector<int> &v)
{
    for (const auto &ele: v) {
        std::cout << ele << " ";
    }
    std::cout << "\n";
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    int n = atoi(argv[1]);
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = rand() % 10001;
    }
    qsortThreePivotPartition(v, 0, n-1);
//    printVector(v);
    assert(issorted(v));
    return 0;
}

