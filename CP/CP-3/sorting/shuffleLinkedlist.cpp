#include <iostream>
#include <ctime>
#include <cstdlib> 

struct Node {
  int data;
  Node *next;  
};

void printList(Node *head) {
    
    while (head) {
        std::cout << head->data << "->";
        head = head->next;
    }
    std::cout << "\n";
}

/* Given a reference (pointer to pointer) to the head
  of a list and an int, push a new node on the front
  of the list. */
void push(Node** head_ref, int new_key)
{
    /* allocate node */
    Node* new_node = new Node;
 
    /* put in the key  */
    new_node->data  = new_key;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

Node* shuffleMerge(Node *a, Node *b) {
    Node dummy, *result = &dummy;
    dummy.next = nullptr;
    while (a && b) {
        int toss = rand() % 2;
        if (toss == 0) {
            result->next = a;
            a = a->next;
        } else {
            result->next = b;
            b = b->next;
        }
        result = result->next;
    }
    if (a) {
        result->next = a;
    } else {
        result->next = b;
    }
    return dummy.next;
}


void AlternateSplit(Node *head, Node **a, Node **b) {    
    int x = 0;
    Node dummyleft, dummyright, *left = &dummyleft, *right = &dummyright;
    while (head) {
        left->next = head;
        left = left->next;
        head = head->next;
        if (head) {
            right->next = head;
            right = right->next;
            head = head->next;
        }
    }
    left->next = nullptr;
    right->next = nullptr;
    *a = dummyleft.next;
    *b = dummyright.next; 
}

Node* ShuffleLinkedList(Node *head) {

    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    Node *a = nullptr, *b = nullptr;
    AlternateSplit(head, &a, &b);
    Node *left = ShuffleLinkedList(a);
    Node *right = ShuffleLinkedList(b);
    return shuffleMerge(left, right);
}


int main()
{
    Node* head = nullptr;
    /* initialize random seed: */
    srand (time(NULL)); 
    /* Use push() to construct below list
     14->21->11->30->10  */
    push(&head, 10);
    push(&head, 30);
    push(&head, 11);
    push(&head, 21);
    push(&head, 14);
    printList(head);    
    head = ShuffleLinkedList(head);
    printList(head);
    return 0;
}

