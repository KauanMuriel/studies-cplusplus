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
        void decript_string(char* string);
        void encript_string(char* string);
        void change_string(char* string, int keyOperation);
        void get_encrypted_lines_from_file(std::list<std::string>* encrypted_lines, std::fstream &file);
        void write_encrypted_lines(std::list<char*>* encrypted_lines, std::ofstream &output_file);
        void read_lines(std::list<char*>* lines, std::fstream &file);
};