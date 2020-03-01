#include <iostream>

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DLList {
private:
    Node* head;
    Node* tail;

public:
    DLList() : head(nullptr), tail(nullptr) {}

    void insertHead(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertTail(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            head = newNode;
            tail = newNode;
        }
         else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void show() {
        Node* runner = head;
        while (runner) {
            std::cout << runner->data << " ";
            runner = runner->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    DLList list;
    list.insertTail(1);
    list.insertTail(2);
    list.insertHead(0);
    list.show();
    return 0;
}