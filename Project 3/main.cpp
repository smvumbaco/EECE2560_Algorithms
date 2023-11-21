// Group 11: Drew Balfour and Sean Vumbaco
// Project 3 (parts a and b)


// Main program file for Project 3
// Part a: Executes findMatches
// Part b: Executes search(int)

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "dictionary.h"
#include "dictionary.cpp"
#include "heap.h"
#include "heap.cpp"
#include "grid.h"
#include "grid.cpp"

// Global variable
vector<string> returnWords;

string vectorToString(vector<string> v, bool newLines = false)
// Takes a vector as input and returns a printable string. Used for debugging
{
    string returnString = "";
    if (!newLines)
    {
        while (v.size() > 0)
        {
            returnString = returnString + v[0] + " ";
            v.erase(v.begin());
        }
    } 
    else 
    {
        while (v.size() > 0)
        {
            returnString = returnString + v[0] + "\n";
            v.erase(v.begin());
        }
    }
    return returnString;
} // end vectorToString

bool itemInVector(string item, const vector<string> v)
// Returns true if item is in vector, false otherwise
{
    // Iterate through the vector
    for (const std::string& element : v) {
        // Check if the current element is equal to the target
        if (element == item) {
            // Return true if found
            return true;
        }
    }
    // Return false if not found
    return false;
}

vector<string> reverseVector(const vector<string> v) 
// Use the rbegin() and rend() iterators to traverse the vector in reverse
{
    return vector<string>(v.rbegin(), v.rend());
}

void firstToLast(vector<string>& v)
// Removes the element at index 0 of the input vector and appends it to the end 
{
    if (!v.empty()) {
        // Remove the element at index 0
        string firstElement = v[0];
        v.erase(v.begin());

        // Add the removed element to the end
        v.push_back(firstElement);
    }
}

void checkVector(Dictionary d, vector<string> v)
// checks a given vector of strings to see if there are any words from the
// given dictionary contained within
{
    string letters = "";
    int j;
    int size = v.size();
    for (int i = 0; i < size - 4; i++)
    {
        letters = "";
        for (j = i; j < size; j++)
        {
            letters = letters + v[j];
            // Ensure the word is at least 5 characters long
            if (j >= i + 4)
            {
                if (d.binarySearch(letters) != -1)
                {
                    // add letters to returnWords string vector if it's not already
                    // there and if it is a word
                    if (letters != "" && !itemInVector(letters, returnWords))
                    {
                        returnWords.push_back(letters);
                    }
                }
            }
        }
    }
} // end checkVector

void searchLine(Dictionary d, const vector<string>& v, int size)
// checks a given vector in order and in reverse order from every element
{
    vector<string> vRev = reverseVector(v);
    checkVector(d, v);
    checkVector(d, vRev);
    vector<string> v2 = v;
    vector<string> vRev2 = vRev;
    firstToLast(v2);
    firstToLast(vRev2);
    // keep checking vectors until v2 is the same as the original v
    while (v2 != v)
    {
        checkVector(d, v2);
        checkVector(d, vRev2);
        firstToLast(v2);
        firstToLast(vRev2);
    }
} // end searchLine

void findMatches(Dictionary d, Grid g)
// Passed a dictionary and grid, prints all the words that can be found in the grid
{
    int s = g.getSize();
    for (int i = 0; i < s; i++)
    {
        searchLine(d, g.getRow(i), s);
        searchLine(d, g.getColumn(i), s);
        for (int j = 0; j < s; j++)
        {
            if (i == 0)
            {
                // ensures that any words created would be at least 5 letters
                if (j <= s - 5)
                {
                    vector<string> leftDiag = g.getLeftDiagonal(i, j);
                    searchLine(d, leftDiag, leftDiag.size());
                }
                // ensures that any words created would be at least 5 letters
                if (j >= 4)
                {
                    vector<string> rightDiag = g.getRightDiagonal(i, j);
                    searchLine(d, rightDiag, rightDiag.size());
                }
            }
            else 
            {
                // ensures that any words created would be at least 5 letters
                if (i <= s - 5)
                {
                    vector<string> leftDiag = g.getLeftDiagonal(i, 0);
                    searchLine(d, leftDiag, leftDiag.size());
                    vector<string> rightDiag = g.getRightDiagonal(i, s - 1);
                    searchLine(d, rightDiag, rightDiag.size());
                    break;
                }
            }
        }
    }
    cout << vectorToString(returnWords, true) << endl;
} // end findMatches

void search(Dictionary d, int sortType)
// reads the name of a grid file from the keyboard and prints out all words
// from the given dictionary that can be found in the grid.
{
    string gridFile;
    bool goodInput = false;
    while (!goodInput)
    {
        cout << "Enter the name of the grid file you would like to use: ";
        cin >> gridFile;
        try 
        {
            Grid grid(gridFile);
            goodInput = true;
        }
        catch (const exception e)
        {
            cerr << "Exception caught: " << endl << e.what() << endl << endl;
        }
    }
    // User selection of sorting type
    if (sortType == 1) 
    {
        d.quickSort();
    } 
    else if (sortType == 2) 
    {
        d.heapSort();
    }
    else {
        d.selectionSort();
    }
    findMatches(d, gridFile);
} // end search

int main()
{
    //Part A
    Dictionary dict;

    // SORTING TESTING
    // dict.selectionSort();
    // dict.quickSort();
    // dict.heapSort();

    // FIND MATCHES TESTING GRID 1
    // Grid g1("input15");
    // g1.printGrid();
    // cout << "Finding matches for grid 1..." << endl;
    // findMatches(dict, g1);

    // FIND MATCHES TESTING GRID 2
    // Grid g2("input30");
    // g2.printGrid();
    // cout << "Finding matches for grid 2..." << endl;
    // findMatches(dict, g2);

    // FIND MATCHES TESTING GRID 3
    // Grid g3("input50");
    // g3.printGrid();
    // cout << "Finding matches for grid 3..." << endl;
    // findMatches(dict, g3);

    // BINARY SEARCH TESTING
    // cout << dict.binarySearch("students") << endl;
    // cout << dict.binarySearch("educate") << endl;
    // cout << dict.binarySearch("educated") << endl;
    // cout << dict.binarySearch("northeastern") << endl;
    // cout << dict.binarySearch("primroses") << endl;

    // DICTIONARY TESTING
    // Dictionary dict;
    // dict.selectionSortDictionary();
    // dict.quickSortDictionary();
    // dict.heapSort();
    // dict.printDictionary();
    // cout << "The word sksksksk is located at index " << dict.binarySearch("zymogenic") << endl;
    // cout << "Expecting -1..." << endl;

    // PART B
    // SEARCH TESTING
    search(dict, 1); // quickSort
    // search(dict, 2); // heapSort
    // search(dict, 0); // selectionSort
}
