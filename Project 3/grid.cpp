// Group 11: Drew Balfour and Sean Vumbaco 
// Project 3 (parts a and b)

// Contains member functions for class Grid.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "grid.h"

Grid::Grid()
// default class constructor...
{
    size = 0;
    gr[0][0];
}

Grid::Grid(string file)
// class constructor...
{
    string g;
    std::ifstream gridfile (file);
    if (gridfile.is_open() )
    {
        while ( gridfile )
        {
            gridfile >> g;
        }
    }
    string s = g.substr(0,2);
    size = stoi(s);
    int len = size*size;
    g = g.substr(4, len);
    int x = len;
    for (int i = 0; i < size; i++) // i = row
    {
        for (int j = 0; j < size; j++) // j = column
        {
            gr[i][j] = g.at(len-x);
            x--;
        }
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
        for (int j = 0; j < size; j++) // j = column
        {
            gr[i][j] = g.at(len-x);
            x--;
        }
    }
}

int Grid::getSize()
{
    return size;
}

arr Grid::getRow(int i, int j)
{
    arr a[size];
    for (int k = 0; k < size; k++)
    {
        int col = (k+j)%size;
        a[k] = gr[i][col];
    }
    return a;
}

arr Grid::getColumn(int i, int j)
{
    arr a[size];
    for (int k = 0; k < size; k++)
    {
        int row = (k+i)%size;
        a[k]=gr[row][j];
    }
    return a;    
}

arr Grid::getDiagonal(int i, int j)
{
    arr a[size];
    for (int k = 0; k < size; k++)
    {
        int col = (k+j)%size;
        int row = (k + i) % size;
        a[k] = gr[row][col];
    }
    return a;
}