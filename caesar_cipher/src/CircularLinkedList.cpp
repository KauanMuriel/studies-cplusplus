#include "../include/CircularLinkedList.hpp"
#include <cstddef>
#include <cstdlib>
#include <iostream>

CircularLinkedList::CircularLinkedList() {
    head = nullptr;
    tail = nullptr;
}

void CircularLinkedList::insert_tail(int value) {
    Node* node = new Node();
    node->data = value;
    node->next = nullptr;

    if (head == nullptr) {
        head = node;
        tail = node;
        node->next = head;
    } else {
        tail->next = node;
        tail = node;
        tail->next = head;
    }
}

void CircularLinkedList::display() {
    Node* currentNode = head;
    do {
        std::cout << currentNode->data << " ";
        currentNode = currentNode->next;
    } while (currentNode != head);
}