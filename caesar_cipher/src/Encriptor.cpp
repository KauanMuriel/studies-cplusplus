#include "../include/Encriptor.hpp"
#include <cstdlib>
#include <ctime>

Encriptor::Encriptor() {
    keySequence = new CircularLinkedList();
    srand(time(nullptr));
    for (int i = 0; i < keyLength; i++) {
        keySequence->insert_tail(rand() % (7 - 1) + 1);
    }
}

void Encriptor::encript(char* string, int size) {
    change_string(string, size, 1);
}

void Encriptor::decript(char* string, int size) {
    change_string(string, size, -1);
}

void Encriptor::change_string(char* string, int size, int keyOperation) {
    Node* currentKey = keySequence->head;
    for (int i = 0; i < size - 1; i++) {
        string[i] = string[i] + (keyOperation * currentKey->data);
        currentKey = currentKey->next;
    }
}