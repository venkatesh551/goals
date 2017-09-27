#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cassert>

inline int parent(int i) {

    return (i - 1)/2;
}

inline int left(int i) {

    return 2 * i + 1;

}

inline int right(int i) {

    return 2 * i + 2;
}

/* min priority-queue */
template <class T>
class MinPriorityQueue {

    private:
        std::vector<T> v;
        int heapSize;

        void HeapDecreaseKey(int i, T newKey) {
            if (newKey > v[i]) {
                throw std::logic_error("new key is smaller than current key");
            }
            while (i > 0 && newKey < v[parent(i)]) {
                v[i] = v[parent(i)];
                i = parent(i);
            }
            v[i] = newKey;
        }

        void minHeapify(int i) {

            while (true) {
                int leftIdx = left(i);
                int rightIdx = right(i);

                int smallest = i;
                if (leftIdx < heapSize && v[leftIdx] < v[smallest]) {
                    smallest = leftIdx;
                }
                if (rightIdx < heapSize && v[rightIdx] < v[smallest]) {
                    smallest = rightIdx;
                }
                if (smallest != i) {
                    std::swap(v[i], v[smallest]);
                    i = smallest;
                } else {
                    break;
                }
            }
        }

    public:
        MinPriorityQueue()  {heapSize = 0;}
        T minimum() {
            if (heapSize == 0) {
                throw std::underflow_error("empty min PQ");
            } else {
                return v[0];
            }
        }

        T ExtractMin(void) {
            if (heapSize == 0) {
                throw std::underflow_error("heap underflow");
            }
            T min = v[0];
            heapSize--;
            v[0] = v[heapSize];
            minHeapify(0);
            return min;
        }

        void minHeapInsert(T key) {
            v.emplace_back(key);
            HeapDecreaseKey(heapSize, key);
            heapSize++;
        }

        bool isminHeap() {

            int n = heapSize;

            for (int i = n/2-1; i >=0 ; --i) {
                assert(v[i] <= v[left(i)]);
                if ( 2 * i + 2 < heapSize) {
                    assert(v[i] <= v[right(i)]);
                }
            }
            return true;
        }
};


int main(int argc, char *argv[]) {

    int n = atoi(argv[1]);
    srand(time(NULL));

    MinPriorityQueue<int> minPQ;
    for (int i = 0; i < n ; ++i) {
 //       int x = rand() % 1001;
        minPQ.minHeapInsert(i);
    }
    for (int i = 0; i < n; ++i) {
        std::cout << minPQ.ExtractMin() << " ";
        assert(minPQ.isminHeap());
    }
    std::cout << std::endl;
    return 0;
}


