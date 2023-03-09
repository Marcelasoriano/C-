/*
Author: Marcela Soriano Cornejo
Course: CSCI-136
Instructor: Genady Maryash
Assignment: lab3A

This program asks user for a date and prints the east basin storage on the given date
using tsv table
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

int main() {
    // open the input file stream
    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }

    // skip the header line
    string junk;
    getline(fin, junk);

    // ask the user for the date
    string date;
    cout << "Enter date: ";
    cin >> date;

    // read the file line by line, looking for the matching date
    string curDate;
    double eastSt, eastEl, westSt, westEl;
    bool found = false;
    while (fin >> curDate >> eastSt >> eastEl >> westSt >> westEl) {
        fin.ignore(INT_MAX, '\n');
        if (curDate == date) {
            found = true;
            cout << "East basin storage: " << eastSt << endl;
            break;
        }
    }

    // close the input file stream
    fin.close();

    return 0;
}
