/*
Author: Marcela Soriano Cornejo
Course: CSCI-136
Instructor: Genady Maryash
Assignment: lab3D

This program reports the West basin elevation for all days in the interval in the reverse chronological order (from the later date to the earlier).
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

    string dates[365];
    double westBasinElevations[365];
    int i = 0;
    bool inInterval = false;

    while (fin >> dates[i] >> junk >> junk >> junk >> westBasinElevations[i]) {
        fin.ignore(INT_MAX, '\n');

        if (dates[i] == startDate) {
            inInterval = true;
        }

        if (inInterval) {
            if (dates[i] == endDate) {
                inInterval = false;
            }
            i++;
        }
    }

    fin.close();

    for (int j = i - 1; j >= 0; j--) {
        cout << dates[j] << "  " << westBasinElevations[j] << " ft" << endl;
    }

    return 0;
}




    

