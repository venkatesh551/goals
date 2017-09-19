#include <iostream>

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

Node* merge(Node *a, Node *b) {
    Node dummy, *result = &dummy;
    dummy.next = nullptr;
    while (a && b) {
        if (a->data <= b->data) {
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

void BottomUpMergeSortLL(Node **headref) {

    if (*headref == nullptr) {
        return;
    }
    Node *lists[32] = {nullptr};
    Node *result = *headref;
    int i;
    while (result != nullptr) {
        
        Node *nextNode = result->next;
        result->next = nullptr;
        
        for (i = 0; i < 32 && (lists[i] != nullptr); ++i) {
            result = merge(lists[i], result);
            lists[i] = nullptr;
        }
        if (i == 32) {
            --i;
        }
        lists[i] = result;
        result = nextNode;        
    }
    result = nullptr;
    for (i = 0; i < 32; ++i) {
        result = merge(lists[i], result);
    }
    *headref = result;
}


int main()
{
    Node* head = nullptr;
    int x = 21;
 
    /* Use push() to construct below list
     14->21->11->30->10  */
    push(&head, 10);
    push(&head, 30);
    push(&head, 11);
    push(&head, 21);
    push(&head, 14);
    printList(head);    
    BottomUpMergeSortLL(&head);
    printList(head);
    return 0;
}
