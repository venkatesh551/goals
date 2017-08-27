#include <fstream>
#include <iostream>
#include <stack>

template <class T>
class Queue {

    private:
        std::stack<T> s1, s2;

    public:
        void enqueue(const T & ele) {
            s1.push(ele);    
        }
        
        const T dequeue() {
            if (s2.empty()) {
                if (s1.empty()) {
                    throw std::out_of_range("queue underflow");
                }
                while (!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            T result = s2.top();
            s2.pop();
            return result;
        }
        bool isEmpty() {
            return s2.empty() && s1.empty();           
        }
};

int main ()
{
    std::ifstream ifs("input.txt");
    std::ofstream ofs("output.txt");

    int n;
    
    ifs >> n;
    Queue<int> q;    
    for (int i = 0; i < n; ++i) {
        char ch;
        
        ifs >> ch;
        if (ch == '+') {
            int ele;
            ifs >> ele;
            q.enqueue(ele);    
        } else {
            ofs << q.dequeue() << std::endl;
        }       
    }
    return 0;
}

