/*
Author: Marcela Soriano Cornejo
Course: CSCI-136
Instructor: Genady Maryash
Assignment: lab3C

This program checks each day in the interval and report which basin had higher elevation on that day by printing “East” or “West”, or print “Equal” if both basins are at the same level.
*/

#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

int main() {
    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }

    string junk;
    getline(fin, junk);

    string startDate, endDate;
    cout << "Enter starting date: ";
    cin >> startDate;
    cout << "Enter ending date: ";
    cin >> endDate;

    string date;
    double eastSt, eastEl, westSt, westEl;
    bool inInterval = false;

    while (fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
        fin.ignore(INT_MAX, '\n');

        if (date == startDate) {
            inInterval = true;
        }

        if (inInterval) {
            if (date == endDate) {
                inInterval = false;
            }

            if (eastEl > westEl) {
                cout << date << " East" << endl;
            } else if (westEl > eastEl) {
                cout << date << " West" << endl;
            } else {
                cout << date << " Equal" << endl;
            }
        }
    }

    fin.close();

    return 0;
}
