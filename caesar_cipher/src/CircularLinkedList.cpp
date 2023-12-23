#include "../include/CircularLinkedList.hpp"
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <vector>

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

std::vector<Node> CircularLinkedList::to_vector() {
    std::vector<Node> vector;
    Node* currentNode = head;
    do {
        vector.push_back(*currentNode);
        currentNode = currentNode->next;
    } while (currentNode != head);
    return vector;
}

void CircularLinkedList::clear() {
    if (head == nullptr) return;

    Node* current = head;

    do {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    } while(current != head);

    head = tail = nullptr;
}