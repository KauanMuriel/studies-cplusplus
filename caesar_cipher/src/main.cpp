#include "../include/Encriptor.hpp"
#include <cstdio>
#include <cstdlib>
#include <ios>
#include <iostream>
#include <limits>
using namespace std;

void wait_user_confirmation() {
    cout << "Press ENTER to continue...";
    getchar();
    cout << "\n\n";
}

int main() {
    Encriptor* encriptor = new Encriptor();
    bool run = true;

    while (run) {
        int user_choice = 0;
        cout << "Welcome to Encriptor v1.0!\n";
        cout << '\n';
        cout << "This program uses the Caesar cipher to encrypt and decrypt text files.\n";
        cout << "The Caesar cipher is a simple substitution method where each letter in a text is shifted by a number of positions in the ASCII table.\n";
        cout << "\n";
        cout << "How to use:\n";
        cout << "1. Instructions\n";
        cout << "2. Start criptography\n";
        cout << "3. Exit\n";
        
        cin >> user_choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        switch (user_choice) {
            case 1:
                cout << "\n";
                cout << "1. Place the file you want to encrypt or decrypt in the program folder.\n";
                cout << "2. Run the program and start criptography.\n";
                cout << "3. The original file will be replaced with the encrypted file.\n\n";

                wait_user_confirmation();
                break;
            case 2:
                encriptor->encript_file("../archives/test.txt");
                cout << "The file was been encrypted!\n\n";
            case 3:
                wait_user_confirmation();
                run = false;
            default:
                cout << "Invalid option, please type again.\n\n";
        }
    }
}

