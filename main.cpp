// Lab 22: Upgrade the DLL Class
// COMSC-210 - Ibrahim Alatig 

#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"

using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> &trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string names [], string colors []);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(static_cast<unsigned>time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i]); {
        i++;
    }
    fin.close();
    
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin >> names[i]); {
        i++;
    }
    fin.close();

    list<Goat> trip; // List to manage goats
    do {
        int choice = main_menu();
        switch (choice) {
            case 1: 
                add_goat(trip, names, colors); 
                break;
            case 2: 
                delete_goat(trip); 
                break;
            case 3: 
                display_trip(trip); 
                break;
            case 4: 
                cout << "Goodbye!" << endl;
                again = false;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (again);

    return 0;
}

