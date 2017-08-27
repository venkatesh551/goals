#include <fstream>
#include <stdexcept>
#include <iostream>

template <class T>
struct Node {
    T data;
    Node *prev;
    Node *next;
    Node (const T & value) : data (value) {
        prev = next = nullptr;
    }
};

template <class T>
class List {
    private:
        
    Node<T> *head, *tail, *mid;
    int count, midpos;
    public:
        
    List() {
        head = tail = mid = nullptr;
        count = midpos = 0;
    }
    void push_back(const T & ele) {
        Node<T> *newNode = new Node<T>(ele);
        if (head == nullptr) { // empty list
            head = mid = tail = newNode;
        } else {
             newNode->prev = tail;
             tail->next = newNode;
             tail = newNode;   
        }
        ++count;
        if (count == 1) {
            midpos = 1;
            mid = head;
        } else if (midpos  < count/2) {
            ++midpos;
            mid = mid->next;
        }
    }
    
    const T pop_back() {
         int result = 0;
         Node<T> *temp = tail;
         if (head == nullptr) { // empty list
             throw std::out_of_range("undeflow");
         }
         else if (tail->prev == nullptr) { // only one node
            result = tail->data;
            head = tail = nullptr;
         } else {
             tail->prev->next = nullptr;
             result = tail->data;
             tail = tail->prev;
         }
         --count;
         if (count == 1) { /* update mid */
            mid = head;
            midpos = 1;
         } else if (midpos > count/2) {
            mid = mid->prev;
            --midpos;
         }
         delete temp;
         return result;
    }
    
    void splitAndJoin() {
        if (count < 2) {
            return;
        }

        tail->next = head;
        head->prev = tail;
        head = mid->next;
        head->prev = nullptr;
        mid->next = nullptr;
        Node<T> *temp = mid;
        if (count % 2 == 0) {
           mid = tail;   
        } else {
            mid = tail->prev;
        }
        tail = temp; 
     }
    
    void printList(std::ofstream &ofs) {
        ofs << count << std::endl;
        for (Node<T> *it = head; it != nullptr; it = it->next) {
            ofs << (it->data) << " ";
        }
        ofs << std::endl;
    }

    
};

int main ()
{
    std::ifstream ifs("input.txt");
    std::ofstream ofs("output.txt");

    int n;
    ifs >> n;
    std::string action;
    List<int> lst;
    for (int i = 0; i < n; ++i) {
        ifs >> action;
        if (action  == "add") {
            int x;
            ifs >> x;
            lst.push_back(x);
        } else if (action == "take") {
            lst.pop_back();
        } else { // action = mum!
            lst.splitAndJoin();
        }
    }
    lst.printList(ofs);
    return 0;
}


