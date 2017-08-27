#include <fstream>
#include <queue>
#include <map>

template <class T>
class Queue {

    private:
        std::queue<T> q;
        std::map<T, int> count;
    public:
        void enqueue(const T & ele) {
            q.push(ele);
            count[ele]++;
        }
        
        void dequeue() {
            T ele = q.front();
            q.pop();
            if (--count[ele] == 0) {
                count.erase(ele);
            }
        }
        
        T minimum() {
           return count.begin()->first;
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
        } else if (ch == '-') {
            q.dequeue();
        } else {
            ofs << q.minimum() << std::endl;
        }
    }
    return 0;
}

