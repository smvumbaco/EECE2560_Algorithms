// Group 11: Drew Balfour and Sean Vumbaco 
// Project 3 (parts a and b)

// Contains member functions for class Grid. Including: constructors, getSize,
// printGrid, getRow, getColumn, getLeftDiagonal, getRightDiagonal, getGrid

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include "grid.h"

Grid::Grid()
// default class constructor: set size of grid to 0
{
    size = 0;
}

Grid::Grid(string file)
// class constructor: takes in the name of a file as a string, opens the file
// and adds all contents to single string. String is then split up into a
// vector of vector to create the grid.
{
    string letter, gridString;
    ifstream gridfile(file);
    // copy all characters in a file into the same string
    if (gridfile.is_open() )
    {
        while ( gridfile )
        {
            gridfile >> letter;
            gridString += letter;
        }
    }
    string s = file.substr(5);
    size = stoi(s);
    int len = size*size;
    gridString = gridString.substr(4, len);
    int x = len;
    // create vector of string vectors to make the grid
    for (int i = 0; i < size; i++) // i = row
    {
        vector<string> v;
        for (int j = 0; j < size; j++) // j = column
        {
            v.push_back(string(1, gridString.at(len-x)));
            x--;
        }
        grid.push_back(v);
    }
} // end Grid(str) constructor

Grid::Grid(string file, int s)
// class constructor: takes in the name of a file as a string, opens the file
// and adds all contents to single string. String is then split up into a
// vector of vector to create the grid. Sets size of grid to s
{
    size = s;
    int len = size*size;
    int x = len;
    string g;
    std::ifstream gridfile (file);
    // copy all characters in given file into a single string
    if (gridfile.is_open() )
    {
        while ( gridfile )
        {
            gridfile >> g;
        }
    }
    g = g.substr(4, len);
    // create vector of string vectors to make the grid
    for (int i = 0; i < size; i++) // i = row
    {
        vector<string> v;
        for (int j = 0; j < size; j++) // j = column
        {
            v.push_back(string(1, g.at(len-x)));
            x--;
        }
        grid.push_back(v);
    }
} // end Grid(str, int) constructor

int Grid::getSize()
// return size of grid
{
    return size;
}

void Grid::printGrid()
// Prints the grid object - used for debugging purposes
{
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

vector<string> Grid::getRow(int row)
// create a string vector containing all strings in the row of the given
// index in the grid
{
    vector<string> a;
    for (int i = 0; i < size; i++) 
    {
        a.push_back(grid[row][i]);
    }
    return a;
}

vector<string> Grid::getColumn(int col)
// create a string vector containing all strings in the column of the given
// index in the grid
{
    vector<string> a;
    for (int i = 0; i < size; i++) 
    {
        a.push_back(grid[i][col]);
    }
    return a;    
}

vector<string> Grid::getLeftDiagonal(int row, int col)
// create a string vector containing all strings on the left diagonal
// of a given cell in the grid at (row, col)
{
    vector<string> a;
    int i = row;
    int j = col;
    // Traverse the left diagonal in the upward direction
    while (i < size && j < size)
    {
        a.push_back(grid[i][j]);
        i++;
        j++;
    }
    i = row - 1;
    j = col - 1;
    // Traverse the left diagonal in the downward direction
    while (i > 0 && j > 0)
    {
        a.insert(a.begin(), grid[i][j]);
        i--;
        j--;
    }
    return a;
} // end getLeftDiagonal

vector<string> Grid::getRightDiagonal(int row, int col)
// create a string vector containing all strings on the right diagonal
// of a given cell in the grid at (row, col)
{
    vector<string> a;
    int i = row;
    int j = col;
    // Traverse the right diagonal in the upward direction
    while (i >= 0 && j < size)
    {
        a.push_back(grid[i][j]);
        i--;
        j++;
    }
    i = row + 1;
    j = col - 1;
    // Traverse the right diagonal in the downward direction
    while (i < size && j >= 0)
    {
        a.insert(a.begin(), grid[i][j]);
        i++;
        j--;
    }
    return a;
} // end getRightDiagonal

vector<vector<string>> Grid::getGrid()
// return grid as a vector of string vectors
{
    return grid;
}
