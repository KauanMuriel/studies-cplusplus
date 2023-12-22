#include "../include/Encriptor.hpp"
#include <cstdlib>
#include <ios>
#include <string>
using namespace std;

int main() {
    Encriptor* encriptor = new Encriptor();

    encriptor->encript_file("../archives/test.txt");
    return 0;
}