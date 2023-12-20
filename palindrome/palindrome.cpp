#include <iostream>

bool IsPalindrome(char string[], int size) {
    bool palindrome = true;
    int sizeWithoutNullCharacter = size -1;
    int indexBackingLetter = sizeWithoutNullCharacter -1;

    for (int i = 0; i < sizeWithoutNullCharacter; i++) {
        if (string[i] != string[indexBackingLetter]) palindrome = false;
        indexBackingLetter--;
    }
    return palindrome;
}

int main() {
    char string[4] = "ALO";
    std::cout << "Palindrome: " << IsPalindrome(string, 4);
    return 0;
}