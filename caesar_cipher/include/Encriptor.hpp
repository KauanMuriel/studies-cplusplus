#include "CircularLinkedList.hpp"

class Encriptor {
    public:
        void decript(char* string, int size);
        void encript(char* string, int size);
        Encriptor();
    private:
        int keyLength = 5;
        CircularLinkedList* keySequence;
        void change_string(char* string, int size, int keyOperation);
};