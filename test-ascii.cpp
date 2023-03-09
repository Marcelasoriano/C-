/*
Author: Marcela Soriano Cornejo
Course: CSCI-136
Instructor: Genady Maryash 
Assignment: LAB6A
Input and output test ASCII 
*/

#include <iostream>
using namespace std;

int main() {
    string input;
    cout << "Input: ";
    getline(cin, input);

    for (char c : input) {
        cout << c << " " << (int)c << endl;
    }

    return 0;
}
