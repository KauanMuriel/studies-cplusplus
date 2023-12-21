#include "../include/Encriptor.hpp"
#include <cstdlib>
#include <iostream>

int main() {
    Encriptor* encriptor = new Encriptor();
    char string[4] = "ALA";
    encriptor->encript(string, 4);
    std::cout << "Encripted: " << string << "\n";
    encriptor->decript(string, 4);
    std::cout << "Decripted: " << string << "\n";

    return 0;
}