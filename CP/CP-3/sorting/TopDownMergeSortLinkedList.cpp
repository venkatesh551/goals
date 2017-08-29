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

void FrontBackSplit(Node *head, Node **a, Node **b) {
    if (head == nullptr || head->next == nullptr) {
        *b = nullptr;
    } else {
        Node *slow = head, *fast = head->next;
        while (fast != nullptr) {
            fast = fast->next;
            if (fast) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        *b = slow->next;
        slow->next = nullptr;
    }
    *a = head;
}

Node* TopDownMergeSortLL(Node *head) {

    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    Node *a = nullptr, *b = nullptr;
    FrontBackSplit(head, &a, &b);
    Node *left = TopDownMergeSortLL(a);
    Node *right = TopDownMergeSortLL(b);
    return merge(left, right);
}


int main()
{
    Node* head = nullptr;
 
    /* Use push() to construct below list
     14->21->11->30->10  */
    push(&head, 10);
    push(&head, 30);
    push(&head, 11);
    push(&head, 21);
    push(&head, 14);
    printList(head);    
    head = TopDownMergeSortLL(head);
    printList(head);
    return 0;
}

