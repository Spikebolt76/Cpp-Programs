#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
using namespace std;

/// @brief Node structure used internally by LinkedList.
struct Node {
    int data;
    Node* next;

    Node() : data(0), next(nullptr) {}
    Node(int val) : data(val), next(nullptr) {}
};

/// @brief A singly linked list class supporting insertion, deletion, traversal, and more.
class LinkedList {
private:
    Node* head; 

public:
    /// @brief Constructor initializes an empty list.
    LinkedList() : head(nullptr) {}

    /// @brief Constructor to initialize the list with an existing head node.
    /// @param headNode Pointer to an existing linked list head.
    LinkedList(Node* headNode) : head(headNode) {}

    /// @brief Constructor to initialize the list with an array of values.
    LinkedList(const initializer_list<int>& values) : head(nullptr) {
        for (const int& value : values) 
            insertAtEnd(value);
    }

    /// @brief Destructor frees all allocated memory.
    ~LinkedList() {
        clear();
    }

    /// @brief Returns the head of the linked list.
    Node* getHead() const {
        return head;
    }

    /// @brief Sets the head pointer of the linked list.
    void setHead(Node* newHead) {
        head = newHead;
    }


    /// @brief Inserts a new node at the front of the list.
    void insertAtFront(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    /// @brief Inserts a new node at the end of the list.
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* curr = head;
        while (curr->next)
            curr = curr->next;
        curr->next = newNode;
    }

    /// @brief Inserts a node at a specified position (0-based index).
    void insertAtPosition(int value, int position) {
        if (position <= 0) {
            insertAtFront(value);
            return;
        }

        const int n = size();
        if (position >= n) {
            insertAtEnd(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* curr = head;
        for (int i = 0; i < position - 1 && curr; ++i)
            curr = curr->next;

        newNode->next = curr->next;
        curr->next = newNode;
    }

    /// @brief Deletes the first node of the list.
    void deleteFromFront() {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    /// @brief Deletes the last node of the list.
    void deleteFromEnd() {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }

        Node* curr = head;
        while (curr->next->next)
            curr = curr->next;

        delete curr->next;
        curr->next = nullptr;
    }

    /// @brief Deletes the node at the given position (0-based index).
    void deleteAtPosition(int position) {
        if (position <= 0) {
            deleteFromFront();
            return;
        }

        Node* curr = head;
        for (int i = 0; i < position - 1 && curr && curr->next; ++i)
            curr = curr->next;

        if (!curr || !curr->next) {
            cout << "Position out of range" << endl;
            return;
        }

        Node* toDelete = curr->next;
        curr->next = toDelete->next;
        delete toDelete;
    }

    /// @brief Returns the number of nodes in the list.
    int size() const {
        int count = 0;
        for (Node* curr = head; curr; curr = curr->next)
            ++count;
        return count;
    }

    /// @brief Prints all elements in the list.
    void display() const {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }

        for (Node* curr = head; curr; curr = curr->next)
            cout << curr->data << " -> ";

        cout << "NULL" << endl;
    }

    /// @brief Frees all nodes and resets the list.
    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    /// @brief Reverses the entire linked list.
    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    /// @brief Sorts the linked list in ascending order using bubble sort.
    void sort() {
        if (!head || !head->next) return;

        bool swapped;
        Node* end = nullptr;
        do {
            swapped = false;
            Node* curr = head;
            while (curr->next != end) {
                if (curr->data > curr->next->data) {
                    swap(curr->data, curr->next->data);
                    swapped = true;
                }
                curr = curr->next;
            }
            end = curr;
        } while (swapped);
    }

    /// @brief Compares this list with another for equality.
    /// @param other The other LinkedList to compare with.
    /// @return true if lists are identical, false otherwise.
    bool isEqual(const LinkedList& other) const {
        Node* curr1 = head;
        Node* curr2 = other.head;
        while (curr1 && curr2) {
            if (curr1->data != curr2->data)
                return false;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return curr1 == nullptr && curr2 == nullptr;
    }

    /// @brief Returns the middle node of the linked list.
    ///        If there are two middles, returns the first one.
    /// @return Pointer to the middle node, or nullptr if the list is empty.
    Node* getMiddle() const {
        if (!head || !head->next) return head;

        Node* slow = head;
        Node* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

#endif // LINKEDLIST_HPP
