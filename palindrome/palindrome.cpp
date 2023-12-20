#include <iostream>

int main() {
    char string[4] = "ALO";
    bool palindrome = true;
    int backingLetter = 2;

    for (int i = 0; i < 3; i++) {
        if (string[i] != string[backingLetter]) palindrome = false;
        backingLetter--;
    }

    std::cout << "Palindromo: " << palindrome;

    return 0;
}