/*
Author: Marcela Soriano Cornejo
Course: CSCI-136
Instructor: Genady Maryash
Assignment: lab4B
Prints checkerboard
*/

#include <iostream>
using namespace std;

int main() {
    int width, height;
    cout << "Input width: ";
    cin >> width;
    cout << "Input height: ";
    cin >> height;
    cout << "Shape:\n";
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if ((i+j) % 2 == 0) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}


