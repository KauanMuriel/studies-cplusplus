#include <iostream>

int* insertion_sort(int* array, int length) {
    for (int i = 1; i < length; i++) {
        int key = array[i];
        int k = i -1;
        while (k >= 0 && array[k] > key) {
            array[k + 1] = array[k];
            k--;
        }
        array[k + 1] = key;
    }
    return array;
}

int main() {
    int array[] = {2,7,4,3,9,1,2};
    int length = 7;

    int* newArr = insertion_sort(array, length);
    
    for (int i = 0; i < length; i++) {
        std::cout << i << "° = " << array[i] << "\n";
    }

    return 0;
}