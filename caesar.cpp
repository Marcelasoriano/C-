/*
Author: Marcela Soriano Cornejo
Course: CSCI-136
Instructor: Genady Maryash 
Assignment: LAB6B
Ciphered character shift
*/

#include <iostream>
#include <string>
using namespace std;

// A helper function to shift one character by rshift
char shiftChar(char c, int rshift) {
    // If the character is not alphabetic, return it unchanged
    if (!isalpha(c)) {
        return c;
    }

    // Determine the offset based on the case of the character
    int offset = isupper(c) ? 'A' : 'a';

    // Shift the character and wrap around if necessary
    return (char)(((c - offset + rshift) % 26 + 26) % 26 + offset);
}

// Caesar cipher encryption
string encryptCaesar(string plaintext, int rshift) {
    string ciphertext;

    // Loop through each character in the plaintext
    for (char c : plaintext) {
        // Shift the character and append it to the ciphertext
        ciphertext += shiftChar(c, rshift);
    }

    return ciphertext;
}

int main() {
    string plaintext;
    int rshift;

    // Prompt the user to enter the plaintext and the right shift
    cout << "Enter plaintext: ";
    getline(cin, plaintext);

    cout << "Enter shift    : ";
    cin >> rshift;

    // Encrypt the plaintext using the Caesar cipher with the given right shift
    string ciphertext = encryptCaesar(plaintext, rshift);

    // Print the ciphertext
    cout << "Ciphertext     : " << ciphertext << endl;

    return 0;
}
