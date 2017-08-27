#include <iostream>
#include <vector>

template <class T>
struct Node {
    T data;
    Node *next;  

    static Node* createNode(T val) {
        Node * node = new Node();
        node->data = val;
        node->next = nullptr;
    }
};

template <class T>
class List{
    private:
        Node<T> *head, *tail;
    public:
        List () {
          head = tail = nullptr;
        }
        ~List() {
            while (head != nullptr) {
                Node<T> *temp = head->next;
                delete head;
                head = temp;
            }
        }
        void push(T val) {
            auto newNode = Node<T>::createNode(val);
            if (head == nullptr) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        
        
        void mergeSort(Node<T> **head) {
            
            if (head == nullptr || head->next == nullptr) {
                return;
            }
            FrontbackSplit();
            
        }
    
};


int main()
{
    int n;
    
    std::cin >> n;
    Node<int> head;
    for (int i = 0; i < n; ++i) {
        int x;
    }
    
    
    return 0;
}
