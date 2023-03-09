/*
Author: Marcela Soriano Cornejo
Course: CSCI-136
Instructor: Genady Maryash
Assignment: lab4D
Prints lower triangle shape (with *) with side length # input
*/

#include <iostream>
using namespace std;

int main() {
    int length;
    cout << "Input side length: ";
    cin >> length;
    cout << "Shape:\n";
    for (int i = 1; i <= length; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
