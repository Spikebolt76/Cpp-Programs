#include "linkedlist.hpp"

void merge(LinkedList& left, LinkedList& right, LinkedList& list) {
    Node dummy(0);
    Node* curr = &dummy;
    Node* Lptr = left.getHead();
    Node* Rptr = right.getHead();

    while (Lptr && Rptr) {
        if (Lptr->data <= Rptr->data) {
            curr->next = Lptr;
            Lptr = Lptr->next;
        } else {
            curr->next = Rptr;
            Rptr = Rptr->next;
        }
        curr = curr->next;
        // curr->next = nullptr; // Prevent cycles
    }

    curr->next = Lptr ? Lptr : Rptr; // Attach remaining nodes

    list.setHead(dummy.next);
    left.setHead(nullptr);  // Clear to avoid reuse
    right.setHead(nullptr);
}

// After merge(), all the valid nodes are now owned by list

// So left and right must not delete those reused nodes

// setHead(nullptr) prevents their destructors from deleting nodes now linked into list

void sortList(LinkedList& list) {
    if (!list.getHead() || !list.getHead()->next) 
        return;
    
    Node* middle = list.getMiddle();
    Node* rightHead = middle->next; 
    middle->next = nullptr;          
    LinkedList left(list.getHead());           
    LinkedList right(rightHead);   

    sortList(left);
    sortList(right);
    merge(left, right, list);
}

int main() {
    LinkedList list = {276, 10, 4523, 112, 11, 208, 10, -56, 0, 55, -56, 120, 69, 42, 196, 159};

    cout << "Original Linkedlist: " << endl;
    list.display();

    sortList(list);

    cout << "Sorted Linkedlist: " << endl;
    list.display();

    return 0;
}