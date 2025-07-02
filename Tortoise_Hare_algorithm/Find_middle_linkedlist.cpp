#include "linkedlist.hpp"

Node* getMiddle (LinkedList& list) {
    
    Node* slow = list.getHead();
    Node* fast = list.getHead();

    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

int main() {
    
    LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);
    list.insertAtEnd(60);

    Node* mid = getMiddle(list);
    std:: cout << mid->data << std::endl;
}