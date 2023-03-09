/*
Author: Marcela Soriano Cornejo
Course: CSCI-136
Instructor: Genady Maryash 
Assignment: LAB6C
Vigenere cipher
*/

#include <iostream>
#include <string>
using namespace std;

// Vigenere cipher encryption
string encryptVigenere(string plaintext, string keyword) {
    string ciphertext;

    // Loop through each character in the plaintext
    for (int i = 0, j = 0; i < plaintext.length(); i++) {
        char c = plaintext[i];

        // If the character is not alphabetic, leave it unchanged
        if (!isalpha(c)) {
            ciphertext += c;
            continue;
        }

        // Determine the offset based on the case of the character
        int offset = isupper(c) ? 'A' : 'a';

        // Compute the right shift based on the keyword
        int k = keyword[j] - 'a';
        j = (j + 1) % keyword.length();

        // Shift the character and append it to the ciphertext
        ciphertext += (char)(((c - offset + k) % 26 + 26) % 26 + offset);
    }

    return ciphertext;
}

int main() {
    string plaintext, keyword;

    // Prompt the user to enter the plaintext and the keyword
    cout << "Enter plaintext: ";
    getline(cin, plaintext);

    cout << "Enter keyword  : ";
    cin >> keyword;

    // Encrypt the plaintext using the Vigenere cipher with the given keyword
    string ciphertext = encryptVigenere(plaintext, keyword);

    // Print the ciphertext
    cout << "Ciphertext     : " << ciphertext << endl;

    return 0;
}
