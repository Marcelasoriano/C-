/*
Author: Marcela Soriano Cornejo
Course: CSCI-136
Instructor: Genady Maryash 
Assignment: LAB6D
Decryption
*/

#include <iostream>
#include <string>
using namespace std;

// A helper function to shift one character by lshift
char shiftChar(char c, int lshift) {
    // If the character is not alphabetic, return it unchanged
    if (!isalpha(c)) {
        return c;
    }

    // Determine the offset based on the case of the character
    int offset = isupper(c) ? 'A' : 'a';

    // Shift the character and wrap around if necessary
    return (char)(((c - offset - lshift + 26) % 26 + 26) % 26 + offset);
}

// Caesar cipher decryption
string decryptCaesar(string ciphertext, int rshift) {
    string plaintext;

    // Loop through each character in the ciphertext
    for (char c : ciphertext) {
        // Shift the character and append it to the plaintext
        plaintext += shiftChar(c, rshift);
    }

    return plaintext;
}

// Vigenere cipher decryption
string decryptVigenere(string ciphertext, string keyword) {
    string plaintext;

    // Loop through each character in the ciphertext
    for (int i = 0, j = 0; i < ciphertext.length(); i++) {
        char c = ciphertext[i];

        // If the character is not alphabetic, leave it unchanged
        if (!isalpha(c)) {
            plaintext += c;
            continue;
        }

        // Determine the offset based on the case of the character
        int offset = isupper(c) ? 'A' : 'a';

        // Compute the left shift based on the keyword
        int k = keyword[j] - 'a';
        j = (j + 1) % keyword.length();

        // Shift the character and append it to the plaintext
        plaintext += (char)(((c - offset - k + 26) % 26 + 26) % 26 + offset);
    }

    return plaintext;
}

int main() {
    string plaintext, ciphertext, decrypted;
    int rshift;
    string keyword;

    // Prompt the user to enter the plaintext
    cout << "Enter plaintext: ";
    getline(cin, plaintext);

    // Encrypt the plaintext using the Caesar cipher with the default right shift
    ciphertext = decryptCaesar(plaintext, 10);

    // Prompt the user to enter the right shift and print the ciphertext and its decryption
    cout << "\n= Caesar =" << endl;

    cout << "Enter shift    : ";
    cin >> rshift;

    decrypted = decryptCaesar(ciphertext, rshift);

    cout << "Ciphertext     : " << ciphertext << endl;
    cout << "Decrypted      : " << decrypted << endl;

    // Encrypt the plaintext using the Vigenere cipher with the default keyword
    ciphertext = decryptVigenere(plaintext, "cake");

    // Prompt the user to enter the keyword and print the ciphertext and its decryption
    cout << "\n= Vigenere =" << endl;

    cout << "Enter keyword  : ";
    cin >> keyword;

    decrypted = decryptVigenere(ciphertext, keyword);

    cout << "Ciphertext     : " << ciphertext << endl;
    cout << "Decrypted      : " << decrypted << endl;

    return 0;
}
