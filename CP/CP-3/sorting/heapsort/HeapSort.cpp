#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cassert>

inline int parent(int i) {
    return (i - 1)/2;
}

inline int leftChild(int i) {
    return 2 * i + 1;
}

inline int rightChild(int i) {
    return 2 *i + 2;
}

void maxHeapify(std::vector<int> &v, int i, int heapSize) {

    while (true) {

        int leftIdx = leftChild(i);
        int rightIdx = rightChild(i);

        int largest = i;
        if (leftIdx < heapSize && v[leftIdx] > v[largest] ) {
            largest = leftIdx;
        }
        if (rightIdx < heapSize && v[rightIdx] > v[largest] ) {
            largest = rightIdx;
        }
        if (largest != i) {
            std::swap(v[largest], v[i]);
            i = largest;
        } else {
            break;
        }
    }
}


void buildMaxHeap(std::vector<int> &v) {

    int n = v.size();

    for (int i = n/2-1; i >= 0; --i) {
        maxHeapify(v, i, n);
    }
    for (int i = 0 ; i < n/2; ++i) {
        assert(v[i] >= v[leftChild(i)]);
        if (2 * i + 2 < n) {
            assert(v[i] >= v[rightChild(i)]);
        }
    }
}

void heapSort(std::vector<int> &v) {

    buildMaxHeap(v);
    int n = v.size();
    for (int i = n-1; i > 0; --i) {
        std::swap(v[i], v[0]);
        maxHeapify(v, 0, i);
    }
    assert(std::is_sorted(v.begin(), v.end()));
/*    for (int i = 0; i < n; ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
    */
}



int main(int argc, char *argv[]) {

    srand(time(NULL));

    int n = atoi(argv[1]);
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = rand() % 1001;
    }
    heapSort(v);
    return 0;
}


