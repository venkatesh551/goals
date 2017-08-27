#include <fstream>
#include <queue>
#include <stdexcept>

template <class T>
class Stack {
    private:
        std::queue<T> q1, q2;
    public:
        void push(T const &ele) {
            q1.push(ele);
        }
        T pop() {
            if (empty()) {
                throw std::out_of_range("Stack<>::top(): empty stack");
            } else {
                if (q1.empty()) {
                    while (!q2.empty()){
                        q1.push(q2.front());
                        q2.pop(); 
                    }   
                }
                while (q1.size() > 1) {
                    q2.push(q1.front());
                    q1.pop();
                }
                T top_ele = q1.front();
                q1.pop();
                return top_ele;
            }
        }
        bool empty() {
            return q1.empty() && q2.empty();
        }
    
};

int main ()
{
    std::ifstream ifs("input.txt");
    std::ofstream ofs("output.txt");

    int n;
    
    ifs >> n;
    Stack<int> s;    
    for (int i = 0; i < n; ++i) {
        char ch;
        
        ifs >> ch;
        if (ch == '+') {
            int ele;
            ifs >> ele;
            s.push(ele);    
        } else {
            ofs << s.pop() << std::endl;
        }       
    }
    return 0;
}

