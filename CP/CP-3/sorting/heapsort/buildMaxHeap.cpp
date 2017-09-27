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

void maxHeapify(std::vector<int> &v, int i) {

    int heapSize = v.size();
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
        maxHeapify(v, i);
    }
    for (int i = 0 ; i < n/2; ++i) {
        assert(v[i] >= v[leftChild(i)]);
        if (2 * i + 2 < n) {
            assert(v[i] >= v[rightChild(i)]);
        }
    }

}

void printMaxHeap(std::vector<int> &v) {

    int n = v.size();

    for (int i = 1, k = 0; k < n; i *= 2) {

        for (int j = 0; k < n && j < i; ++j) {
            std::cout << v[k++] << " ";
        }
        std::cout << "\n";
    }


}

int main(int argc, char *argv[]) {

    srand(time(NULL));

    int n = atoi(argv[1]);
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = rand() % 1001;
    }
    buildMaxHeap(v);
    printMaxHeap(v);
    return 0;
}


