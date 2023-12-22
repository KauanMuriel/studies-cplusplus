#include "../include/Encriptor.hpp"
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>

using namespace std;

Encriptor::Encriptor() : keySequence(new CircularLinkedList()) {
    srand(time(nullptr));
    for (int i = 0; i < keyLength; i++) {
        keySequence->insert_tail(rand() % (7 - 1) + 1);
    }
}

void Encriptor::encript_file(string file_path) {
    list<string> encryptedLines;
    fstream file;

    file.open(file_path, ios::in);
    if (file.is_open()) {
        get_encrypted_lines_from_file(&encryptedLines, file);
        file.close();
    }

    remove(file_path.c_str());

    ofstream output_file(file_path);

    if (output_file.is_open()) {
        write_encrypted_lines(&encryptedLines, output_file);
        output_file.close();
    }
}

void Encriptor::encript_string(char* string, int size) {
    change_string(string, size, 1);
}

void Encriptor::decript_string(char* string, int size) {
    change_string(string, size, -1);
}

std::vector<Node> Encriptor::get_keys() {
    return keySequence->to_vector();
}

void Encriptor::change_string(char* string, int size, int keyOperation) {
    Node* currentKey = keySequence->head;
    for (int i = 0; i < size - 1; i++) {
        string[i] = string[i] + (keyOperation * currentKey->data);
        currentKey = currentKey->next;
    }
}

void Encriptor::get_encrypted_lines_from_file(list<string>* encrypted_lines, fstream &file) {
    string stringLine;
    char* arrayLine = nullptr;

    while (getline(file, stringLine)) {
        int arrayLength = stringLine.length() + 1;
        arrayLine = new char[arrayLength];
        strcpy(arrayLine, stringLine.c_str());
        encript_string(arrayLine, arrayLength);
        encrypted_lines->push_back(arrayLine);
    }
    delete[] arrayLine;
}

void Encriptor::write_encrypted_lines(list<string>* encrypted_lines, ofstream &output_file) {
    for (string &line : *encrypted_lines) {
        output_file << line << '\n';
    }
    for (Node &key : get_keys()) {
        output_file << key.data;
    }
}