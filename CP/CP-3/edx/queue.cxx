#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>

template <class T>
class Queue {
    private:
        std::vector<T> v;
        int head;
        int tail;
        int length;
    public:
        Queue (int maxSize) : head(0), tail(0), length(maxSize) {
            v.resize(maxSize);
        }
        void enqueue(T const &ele) {
            if (isFull()) {
                throw std::out_of_range("queue Overflow");
            } else {
                v[tail] = ele;
                tail = (tail + 1) % length;   
            }
        }
        T dequeue() {
            if (empty()) {
                throw std::out_of_range("empty queue");
            } else {
                int result = v[head];
                head = (head + 1)% length;
                return result;
            }
        }
        bool isFull() {
            return (tail + 1) % length == head;
        }
        bool empty() {
            return head == tail;
        }   
};

int main ()
{
    std::ifstream ifs("input.txt");
    std::ofstream ofs("output.txt");

    int n;
    
    ifs >> n;
    Queue<int> s(n);    
    for (int i = 0; i < n; ++i) {
        char ch;
        
        ifs >> ch;
        if (ch == '+') {
            int ele;
            ifs >> ele;
            s.enqueue(ele);    
        } else {
            ofs << s.dequeue() << std::endl;
        }       
    }
    return 0;
}

