/*
Author: Marcela Soriano Cornejo
Course: CSCI-136
Instructor: Genady Maryash
Assignment: LAB7B
Indent
*/

#include <iostream>
#include <string>

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
    int level = 0;
    string line;
    while (getline(cin, line)) {
        line = removeLeadingSpaces(line);
        int openBraces = 0;
        int closeBraces = 0;
        for (char c : line) {
            if (c == '{') {
                openBraces++;
            } else if (c == '}') {
                closeBraces++;
            }
        }
        for (int i = 0; i < level; i++) {
            cout << '\t';
        }
        cout << line << endl;
        level += openBraces - closeBraces;
        if (line.find("}") == level) {
            level--;
        }
    }
    return 0;
}
