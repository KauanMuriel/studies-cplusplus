#include "CircularLinkedList.hpp"
#include <string>
#include <vector>
#include <list>

class Encriptor {
    public:
        Encriptor();
        void encript_file(std::string file_path);
        std::vector<Node> get_keys();
    private:
        int keyLength = 5;
        CircularLinkedList* keySequence;
        void decript_string(char* string, int size);
        void encript_string(char* string, int size);
        void change_string(char* string, int size, int keyOperation);
        void get_encrypted_lines_from_file(std::list<std::string>* encrypted_lines, std::fstream &file);
        void write_encrypted_lines(std::list<std::string>* encrypted_lines, std::ofstream &output_file);
};