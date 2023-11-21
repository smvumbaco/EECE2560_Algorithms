// Group 11: Drew Balfour and Sean Vumbaco 
// Project 3 (parts a and b)

// Contains member functions for class Grid.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include "grid.h"

Grid::Grid()
// default class constructor...
{
    size = 0;
    // gr[0][0];
}

Grid::Grid(string file)
// class constructor...
{
    string letter, gridString;
    ifstream gridfile(file);
    if (gridfile.is_open() )
    {
        while ( gridfile )
        {
            // gridfile >> g;
            gridfile >> letter;
            gridString += letter;
        }
    }
    // cout << gridString << endl;
    // string s = g.substr(0,2);
    // string s = g.substr(5);
    string s = file.substr(5);
    size = stoi(s);
    int len = size*size;
    // g = g.substr(4, len);
    gridString = gridString.substr(4, len);
    // cout << gridString << endl;
    int x = len;
    for (int i = 0; i < size; i++) // i = row
    {
        vector<string> v;
        for (int j = 0; j < size; j++) // j = column
        {
            // v.push_back(g.at(len-x));
            v.push_back(string(1, gridString.at(len-x)));
            x--;
        }
        grid.push_back(v);
    }
}

Grid::Grid(string file, int s)
// class constructor...
{
    size = s;
    int len = size*size;
    int x = len;
    string g;
    std::ifstream gridfile (file);
    if (gridfile.is_open() )
    {
        while ( gridfile )
        {
            gridfile >> g;
        }
    }
    g = g.substr(4, len);
    for (int i = 0; i < size; i++) // i = row
    {
        vector<string> v;
        for (int j = 0; j < size; j++) // j = column
        {
            // v.push_back(g.at(len-x));
            v.push_back(string(1, g.at(len-x)));
            x--;
        }
        grid.push_back(v);
    }
}

int Grid::getSize()
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
{
    // vector<string> a();
    vector<string> a;
    for (int i = 0; i < size; i++) 
    {
        a.push_back(grid[row][i]);
    }
    // for (int k = 0; k < size; k++)
    // {
    //     int col = (k+j)%size;
    //     // a.push_back = grid[i][col];
    //     a.push_back(grid[i][col]);
    // }
    return a;
}

vector<string> Grid::getColumn(int col)
{
    // vector<string> a();
    vector<string> a;
    for (int i = 0; i < size; i++) 
    {
        a.push_back(grid[i][col]);
    }
    // for (int k = 0; k < size; k++)
    // {
    //     int row = (k+i)%size;
    //     // a.push_back = grid[row][j];
    //     a.push_back(grid[row][j]);
    // }
    return a;    
}

// string vectorToString(vector<string> v)
// {
//     string returnString = "";
//     while (v.size() > 0)
//     {
//         returnString = returnString + v[0];
//         v.erase(v.begin());
//     }
//     return returnString;
// }

vector<string> Grid::getLeftDiagonal(int row, int col)
{
    // vector<string> a();
    vector<string> a;
    int i = row;
    int j = col;
    while (i < size && j < size)
    {
        a.push_back(grid[i][j]);
        i++;
        j++;
    }
    i = row - 1;
    j = col - 1;
    while (i > 0 && j > 0)
    {
        a.insert(a.begin(), grid[i][j]);
        i--;
        j--;
    }
    // for (int k = 0; k < size; k++)
    // {
    //     int col = (k+j)%size;
    //     int row = (k + i) % size;
    //     // a.push_back = grid[row][col];
    //     a.push_back(grid[row][col]);
    // }

    // cout << "Left Diagonal: " << vectorToString(a) << endl;
    return a;
}

// vector<string> Grid::getRightDiagonal(int row, int col)
vector<string> Grid::getRightDiagonal(int row, int col)
{
    vector<string> a;
    int i = row;
    int j = col;

    // Traverse the right diagonal in the upward direction
    while (i >= 0 && j < size)
    {
        // cout << "Inserting letter " << grid[i][j] << " at the back of rightDiag" << endl;
        a.push_back(grid[i][j]);
        // cout << "-" << endl;
        // cout << grid[i][j] << endl;
        // cout << i << endl;
        // cout << j << endl;
        // cout << "-" << endl;
        i--;
        j++;
    }

    i = row + 1;
    j = col - 1;

    // Traverse the right diagonal in the downward direction
    while (i < size && j >= 0)
    {
        // cout << "Inserting letter " << grid[i][j] << " at the front of rightDiag" << endl;
        a.insert(a.begin(), grid[i][j]);
        // cout << "-" << endl;
        // cout << grid[i][j] << endl;
        // cout << i << endl;
        // cout << j << endl;
        // cout << "-" << endl;
        i++;
        j--;
    }

    // cout << "Right Diagonal: " << vectorToString(a) << endl;
    return a;
}

// {
//     vector<string> a;
//     int i = row;
//     int j = col;
//     while (i < size && j > 0)
//     {
//         cout << "Inserting letter " << grid[i][j] << " at the back of rightDiag" << endl;
//         a.push_back(grid[i][j]);
//         i++;
//         j--;
//     }
//     i = row - 1;
//     j = col + 1;
//     while (i > 0 && j < size)
//     {
//         cout << "Inserting letter " << grid[i][j] << "at the front of rightDiag" << endl;
//         a.insert(a.begin(), grid[i][j]);
//         i--;
//         j++;
//     }
//     cout << "Right Diagonal: " << vectorToString(a) << endl;
//     return a;
// }

vector<vector<string>> Grid::getGrid()
{
    return grid;
}
