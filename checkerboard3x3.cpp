/*
Author: Marcela Soriano Cornejo
Course: CSCI-136
Instructor: Genady Maryash
Assignment: lab4G
Asks the user to input width and height and prints a checkerboard of 3-by-3 squares. 
*/

#include <iostream>

using namespace std;

#include <iostream>
using namespace std;

int main() {
    int width, height;
    cout << "";
    cin >> width;
    cout << "";
    cin >> height;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if ((i / 3) % 2 == 0) {
                if ((j / 3) % 2 == 0) {
                    cout << "*";
                } else {
                    cout << " ";
                }
            } else {
                if ((j / 3) % 2 == 0) {
                    cout << " ";
                } else {
                    cout << "*";
                }
            }
        }
        cout << endl;
    }
    return 0;
}

