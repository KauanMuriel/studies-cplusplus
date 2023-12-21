#ifndef CIRCULARLINKEDLIST
#define CIRCULARLINKEDLIST

struct Node {
    int data;
    int key;
    Node *next;
};

class CircularLinkedList {
    public:
        Node* head;
        Node* tail;
        CircularLinkedList();
        void insert_tail(int value);
        void display();
};

#endif