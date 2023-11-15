// Group 11: Drew Balfour and Sean Vumbaco 
// Project 3 (parts a and b)

// Contains class Grid declaration

#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Grid {
    private:
    // member data
    int size;
    string gr[size][size];
    public:
    // constructors
    Grid();
    Grid(string file);
    Grid(string file, int size);
    int getSize();
    arr getRow(int i, int j);
    arr getDiagonal(int i, int j);
    arr getColumn(int i, int j);
    // member data
};

#endif // GRID_H
