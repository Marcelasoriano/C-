/*
Author: Marcela Soriano Cornejo
Course: CSCI-136
Instructor: Genady Maryash
Assignment: lab3B

This program finds the minimum and maximum storage in East basin in 2018 given tsv table.
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <cfloat>

using namespace std;

int main() {
    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); // exit if failed to open the file
    }
    string junk; // to store the header line
    getline(fin, junk);
    
    // initialize the minimum and maximum storage to extreme values
    double minStorage = DBL_MAX;
    double maxStorage = -DBL_MAX;

    string date;
    double eastSt, eastEl, westSt, westEl;

    while (fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
        fin.ignore(INT_MAX, '\n'); // skip remaining columns
        if (date.substr(6,4) == "2018") { // only consider data from 2018
            if (eastSt < minStorage) {
                minStorage = eastSt;
            }
            if (eastSt > maxStorage) {
                maxStorage = eastSt;
            }
        }
    }
    fin.close();

    cout << "minimum storage in East basin: " << minStorage << " billion gallons" << endl;
    cout << "maximum storage in East basin: " << maxStorage << " billion gallons" << endl;

    return 0;
}

