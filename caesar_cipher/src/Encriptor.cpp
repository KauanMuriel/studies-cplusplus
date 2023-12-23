#include "../include/Encriptor.hpp"
#include <cstdio>
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
    list<char*> file_lines;
    fstream file;

    file.open(file_path, ios::in);
    if (file.is_open()) {
        read_lines(&file_lines, file);
        for (char* line : file_lines) {
            encript_string(line);
        }
        file.close();
    }

    remove(file_path.c_str());

    ofstream output_file(file_path);

    if (output_file.is_open()) {
        write_encrypted_lines(&file_lines, output_file);
        output_file.close();
    }
}

void Encriptor::encript_string(char* string) {
    change_string(string, 1);
}

void Encriptor::decript_string(char* string) {
    change_string(string, -1);
}

std::vector<Node> Encriptor::get_keys() {
    return keySequence->to_vector();
}

void Encriptor::change_string(char* string, int keyOperation) {
    Node* currentKey = keySequence->head;
    int i = 0;
    while (string[i] != '\0') {
        string[i] = string[i] + (keyOperation * currentKey->data);
        currentKey = currentKey->next;
        i++;
    }
}

void Encriptor::get_encrypted_lines_from_file(list<string>* encrypted_lines, fstream &file) {
    string stringLine;
    char* arrayLine = nullptr;

    while (getline(file, stringLine)) {
        int arrayLength = stringLine.length() + 1;
        arrayLine = new char[arrayLength];
        strcpy(arrayLine, stringLine.c_str());
        encript_string(arrayLine);
        encrypted_lines->push_back(arrayLine);
    }
    delete[] arrayLine;
}

void Encriptor::write_encrypted_lines(list<char*>* encrypted_lines, ofstream &output_file) {
    for (char* &line : *encrypted_lines) {
        if (line[0] != '\0')
            output_file << line;
        output_file << '\n';
    }
    for (Node &key : get_keys()) {
        output_file << key.data;
    }
}

void Encriptor::read_lines(list<char*>* lines, fstream &file) {
    string string_line;

    while (getline(file, string_line)) {
        int array_length = string_line.length() + 1;
        char* array_line = new char[array_length];
        strcpy(array_line, string_line.c_str());
        array_line[string_line.length()] = '\0';
        lines->push_back(array_line);
    }
}