#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cassert>

template <class T>
class D_aryHeap {

    private:
        std::vector<T> v;
        int d;

        int parent(int i) {
            return (i - 1)/d;
        }

        void maxHeapify(int i) {
            int heapSize = v.size();
            int largest = i;
            for (int j = d * i + 1; j <= d * i + d; ++j) {
                if (j < heapSize && v[j] > v[largest]) {
                    largest = j;
                }
            }
            if (largest != i) {
                std::swap(v[largest], v[i]);
                maxHeapify(largest);
            }
        }

        void IncreaseKey(int i, T key) {
            if (key < v[i]) {
                throw std::logic_error("key is smaller");
            }
            while (i > 0 && key > v[parent(i)]){
                v[i] = v[parent(i)];
                i = parent(i);
            }
            v[i] = key;
        }
    public:
        D_aryHeap(int size) : d(size) {
        }

        T extractMax(void) {
            int heapSize = v.size();
            if (heapSize == 0) {
                throw std::underflow_error ("empty heap");
            }
            T max = v[0];
            v[0] = v[heapSize - 1];
            v.pop_back();
            maxHeapify(0);
            return max;
        }

        void push(T key) {
            v.emplace_back(key);
            IncreaseKey(v.size() - 1, key);
        }

};

int main(int argc, char *argv[]) {

    srand(time(NULL));
    D_aryHeap<int> heap(4);
    int n = atoi(argv[1]);
    std::vector<int> v(n), p(n);
    for (int i = 0; i < n; ++i) {
        int x = rand() % 21;
        heap.push(x);
        v[i] = x;
    }
    for (int i = 0; i < n; ++i) {
        p[i] = heap.extractMax();
    }
    std::sort(v.rbegin(), v.rend());
    assert(v == p);
    return 0;
}



