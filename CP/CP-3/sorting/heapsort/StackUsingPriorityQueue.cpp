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

/* Max priority-queue */
template <class T>
class MaxPriorityQueue {

    private:
        std::vector<T> v;
        int heapSize;

        void HeapIncreaseKey(int i, T newKey) {
            if (newKey < v[i]) {
                throw std::logic_error("new key is smaller than current key");
            }
            while (i > 0 && newKey > v[parent(i)]) {
                v[i] = v[parent(i)];
                i = parent(i);
            }
            v[i] = newKey;
        }

        void maxHeapify(int i) {

            while (true) {
                int leftIdx = left(i);
                int rightIdx = right(i);

                int largest = i;
                if (leftIdx < heapSize && v[leftIdx] > v[largest]) {
                    largest = leftIdx;
                }
                if (rightIdx < heapSize && v[rightIdx] > v[largest]) {
                    largest = rightIdx;
                }
                if (largest != i) {
                    std::swap(v[i], v[largest]);
                    i = largest;
                } else {
                    break;
                }
            }
        }

    public:
        MaxPriorityQueue()  {heapSize = 0;}
        T Maximum() {
            if (heapSize == 0) {
                throw std::underflow_error("empty Max PQ");
            } else {
                return v[0];
            }
        }

        T ExtractMax(void) {
            if (heapSize == 0) {
                throw std::underflow_error("heap underflow");
            }
            T max = v[0];
            heapSize--;
            v[0] = v[heapSize];
            maxHeapify(0);
            return max;
        }

        void MaxHeapInsert(T key) {
            v.emplace_back(key);
            HeapIncreaseKey(heapSize, key);
            heapSize++;
        }

        bool isMaxHeap() {

            int n = heapSize;

            for (int i = 0; i < n/2; ++i) {
                assert(v[i] >= v[left(i)]);
                if ( 2 * i + 2 < heapSize) {
                    assert(v[i] >= v[right(i)]);
                }
            }
            return true;
        }
        bool empty() {
            return true;
        }
};

template <class T>
class Stack {
    private:
        MaxPriorityQueue<std::pair<int, T>> maxPQ;
        int counter;
    public:
        Stack() {
            counter = 0;
        }
        void push(T x){
            maxPQ.MaxHeapInsert({counter, x});
            counter++;
        }

        T pop() {
            auto ele = maxPQ.ExtractMax();
            counter--;
            return ele.second;
        }

        bool isEmpty() {
            return counter == 0;
        }
};


int main(int argc, char *argv[]) {

    int n = atoi(argv[1]);
    srand(time(NULL));

    Stack<int> st;
    std::vector<int> v(n), result(n);

    for (int i = 0; i < n; ++i) {
        v[i] = rand() % 101;
        st.push(v[i]);
    }
    for (int i = 0; i < n; ++i) {
        result[i] = st.pop();
    }
    std::reverse(v.begin(), v.end());
    assert(v == result);
    return 0;
}


