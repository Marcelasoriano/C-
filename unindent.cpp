/*
Author: Marcela Soriano Cornejo
Course: CSCI-136
Instructor: Genady Maryash
Assignment: LAB7A
Unindent
*/


#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string removeLeadingSpaces(string line)
{
    string result;
    bool found_non_space = false;
    for (char c : line) {
        if (isspace(c)) {
            if (found_non_space) {
                result += c;
            }
        } else {
            result += c;
            found_non_space = true;
        }
    }
    return result;
}

int main()
{
    string line;
    while (getline(cin, line)) {
        cout << removeLeadingSpaces(line) << endl;
    }
    return 0;
}
