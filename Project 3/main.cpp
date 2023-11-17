// Group 11: Drew Balfour and Sean Vumbaco
// Project 3 (parts a and b)


// Main program file for Project 3, executes findMatches (part a) and
// search(int) (part b)

#include <iostream>
#include <string>

using namespace std;

#include "dictionary.h"
#include "dictionary.cpp"
#include "heap.h"
#include "heap.cpp"
#include "grid.h"
#include "grid.cpp"

void findMatches(Dictionary d, Grid g)
// Passed a dictionary and grid, prints all the words that can be found in the grid
{
    int s = g.getSize();
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            searchLine(d, g.getRow(i, j), s);
            searchLine(d, g.getColumn(i, j), s);
            searchLine(d, g.getDiagonal(i, j), s);
        }
    }
}

void searchLine(Dictionary d, arr a, int size)
{
    string f, b;
    int i, j;
    for (i = 0; i < size; i++)
    {
        f =+ a[i];
        if (d.binarySearch(f) != -1)
            cout << f << endl;
    }
    for (i = size; i > 0; i--)
    {
        j = i % (size);
        b =+ a[j];
        if (d.binarySearch(b) != -1)
        {
            cout << b << endl;
        }
    }
}

void search(Dictionary d, int sortType)
{
    string gridFile;
    cout << "Enter the name of the grid file you would like to use: ";
    cin >> gridFile;
    Grid grid(gridFile);
    cout << endl << "Enter the sorting algorithm to be used.\n0: Selection Sort\n1: Quick Sort\nEnter Here: ";
    cin >> sortType;
    if (sortType) 
    {
        d.quickSortDictionary();
    } 
    else 
    {
        d.selectionSortDictionary();
    }
    findMatches(d, gridFile);
}

int main()
{
    //Part A
    // Grid g1("input15.txt");
    // Grid g2("input30.txt");
    // Grid g3("input50-1.txt");
    Dictionary dict;
    // dict.selectionSortDictionary();
    dict.quickSortDictionary();
    dict.printDictionary();
    cout << "The word sksksksk is located at index " << dict.binarySearch("zymogenic") << endl;
    cout << "Expecting -1..." << endl;
}
