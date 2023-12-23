#ifndef CIRCULARLINKEDLIST
#define CIRCULARLINKEDLIST

#include <vector>
struct Node {
    int data;
    Node *next;
};

class CircularLinkedList {
    public:
        Node* head;
        Node* tail;
        CircularLinkedList();
        void insert_tail(int value);
        void clear();
        void display();
        std::vector<Node> to_vector();
};

#endif