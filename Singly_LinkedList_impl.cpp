#include <iostream>
using namespace std;

class LinkedList {
private :
    struct Node {
        int data;
        Node* next;

        Node(int val) : data(val), next(nullptr) {} //constructor
    };

    Node* head;

public :
    LinkedList() : head(nullptr) {}

    ~LinkedList() { // destructor 
        clear();  
    }

    void clear() {
        while(head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertAtBeginning (int data) {
        Node* newNode = new Node(data);

        newNode->next = head; 
        head = newNode; 
    }

    void insertAtEnd (int data) {
        Node* newNode = new Node(data);

        if (!head) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* curr = head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    void insertAtPosition (int data, int position) { // position : index based
        int index = position;
        if (index <= 0){
            insertAtBeginning(data);
            return;
        }
        int n = size();
        if (n <= index){
            insertAtEnd(data);
            return;
        }
        Node* newNode = new Node(data);
        Node* curr = head;

        for (int i = 0; i < index - 1; ++i) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }

    void deleteAtBeginning () {
        if (head == nullptr){
            cout << "List is Empty" << endl; 
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtEnd () {
        if (head == nullptr){
            cout << "List is Empty" << endl; 
            return;
        }
        if (head->next == nullptr){
            delete head;
            head = nullptr;
            return;
        }

        Node* curr = head;
        while (curr->next->next){
            curr = curr->next;
        }
        delete curr->next;
        curr->next = nullptr;
    }

    void deleteAtPosition(int position) {
        int index = position;
        if (index <= 0) {
            deleteAtBeginning();
            return;
        }
        Node* curr = head;
        for (int i = 0; i < index - 1; ++i) {
            curr = curr->next;
        }
        Node* toDelete = curr->next;
        curr->next = toDelete->next;
        delete toDelete;
    }

    int size () {
        Node* curr = head;
        int count = 0;
        while (curr){
            count++;
            curr = curr->next;
        }
        return count;
    }

    void display(){
        Node* curr = head;
        if (!curr){
            cout << "List is Empty" << endl;
            return;
        }
        while (curr){
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "null" << endl;
    }

    
};



int main() {
    LinkedList list; // Create an instance of LinkedList
    

}