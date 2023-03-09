/*
Author: Marcela Soriano Cornejo
Course: CSCI-136
Instructor: Genady Maryash
Assignment: lab4C
Prints diagonal shape with asterik # on input
*/

#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Input size: ";
    cin >> size;
    cout << "Shape:\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j || i+j == size-1) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
