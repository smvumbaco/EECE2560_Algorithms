// Group 11: Drew Balfour and Sean Vumbaco 
// Project 3 (parts a and b)

// Contains class Grid declaration

#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Grid
{
    private:
    // member data
    int size;
    vector<vector<string>> grid;
    public:
    // constructors
    Grid();
    Grid(string file);
    Grid(string file, int size);
    // member functions
    int getSize();
    void printGrid();
    vector<string> getRow(int row);
    vector<string> getColumn(int col);
    vector<string> getLeftDiagonal(int row, int col);
    vector<string> getRightDiagonal(int row, int col);
    vector<vector<string>> getGrid();
};

#endif // GRID_H
