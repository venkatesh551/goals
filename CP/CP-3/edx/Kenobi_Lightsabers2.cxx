#include <fstream>
#include <deque>
#include <iostream>


int main ()
{
    std::ifstream ifs("input.txt");
    std::ofstream ofs("output.txt");

    int n;
    ifs >> n;
    std::string action;
    std::deque<int> *left = new std::deque<int>();
    std::deque<int> *right = new std::deque<int>();
    for (int i = 0; i < n; ++i) {
        ifs >> action;
        if (action  == "add") {
            int x;
            ifs >> x;
            right->push_back(x);
        } else if (action == "take") {
            right->pop_back(); 
        } else { // action = mum!
            if (left->size() == 0) {
                int count = right->size()/2;
                
                while (count > 0) {
                    left->push_back(right->front());
                    right->pop_front();
                    count--;
                }    
            }
            
            std::deque<int> *temp = left;
            left = right;
            right = temp;
            
        }
        if (left->size() > right->size()) {
            right->push_front(left->back());
            left->pop_back();
            
        } else if ((int)left->size() < ((int) right->size() -1)) {
            left->push_back(right->front());
            right->pop_front();
            
        }
    }
    ofs << (left->size() + right->size()) << std::endl;
    for (auto ele: *(left)) {
        ofs << ele << " ";
    }
    for (auto ele: *(right)) {
        ofs << ele << " ";
    }
    ofs << std::endl;
    delete left;
    delete right;
    return 0;
}


