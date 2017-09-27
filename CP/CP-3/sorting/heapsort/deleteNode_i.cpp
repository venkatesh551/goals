#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cassert>

/*
    https://stackoverflow.com/questions/38403206/deleting-a-node-ai-from-a-max-heap

When deleting a node from a max heap, the first thing we need to 
do is swap the target element with the last element, then delete the last element.

Now, we're faced with the problem of fixing the max heap since we 
just moved an element around. Let's refer to that element that we just moved as x.

There are three cases:

x is greater than its parent
x is less than its parent
x is equal to its parent
If x is equal to its parent, that's easy - we do nothing.

If x is less than its parent, all we need to do is a MAX-HEAPIFY 
(which I'm assuming you understand how that works from the comments), because
we need to fix any mistakes below x.

If x is greater than its parent, we run into the issue that 
you've brought up. Handling this isn't too tricky - we just need to 
compare x to its parent, and if x is greater than the parent, we swap them. 
Continue this process until x is no longer greater than its parent 
or we reach the root (when x has no parents)
*/




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
}

void isMaxHeap(std::vector<int> &v)
{
    int n = v.size();
    for (int i = 0 ; i < n/2; ++i) {
        assert(v[i] >= v[leftChild(i)]);
        if (2 * i + 2 < n) {
            assert(v[i] >= v[rightChild(i)]);
        }
    }
}

void heapIncreaseKey(std::vector<int> &v, int i, int newKey)
{
    while (i > 0 && newKey > v[parent(i)]){
        v[i] = v[parent(i)];
        i = parent(i);
    }
    v[i] = newKey;
}


int deleteNode(std::vector<int> &v, int i) 
{
    int n = v.size();
    if (i < 0 || i >= n) {
        throw std::out_of_range("invalid index");
    }
    int result = v[i];
    v[i] = v[n-1];
    v.pop_back();
    if (i == 0 || v[i] < v[parent(i)]) {
        maxHeapify(v, i);
    } else if (v[i] > v[parent(i)]) {
        heapIncreaseKey(v, i, v[i]);
    }
    return result;
}

void printHeap(std::vector<int> &v) {

    for (auto c: v) {
        std::cout << " " << c;
    }
    std::cout << "\n";

}

int main(int argc, char *argv[]) {

    srand(time(NULL));

    int n = atoi(argv[1]);
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = rand() % 21;
    }
    buildMaxHeap(v);
    isMaxHeap(v);
    for (int i = 0; i < n; ++i) {
        int randIdx = rand() % n;
        printHeap(v);
        std::cout << "randIdx = " << randIdx << "\n";
        deleteNode(v, randIdx);
        isMaxHeap(v);
        n--;
    }
    return 0;
}


