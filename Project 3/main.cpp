// Group 11: Drew Balfour and Sean Vumbaco
// Project 3 (parts a and b)


// Main program file for Project 3, executes findMatches (part a) and
// search(int) (part b)

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

vector<string> returnWords;

string vectorToString(vector<string> v, bool newLines = false)
// Takes a vector as input and returns a printable string. Used for debugging
{
    string returnString = "";
    if (!newLines)
    {
        while (v.size() > 0)
        {
            // returnString = returnString + v[0];            
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
}

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
{
    string letters = "";
    // string returnWord = "";
    int j;
    int size = v.size();
    for (int i = 0; i < size - 4; i++)
    {
        letters = "";
        for (j = i; j < size; j++)
        {
            letters = letters + v[j];
            if (j >= i + 4) // Ensure the word is at least 5 characters long
            {
                if (d.binarySearch(letters) != -1)
                {
                    // cout << letters << endl;
                    // returnWord = returnWord + letters + " ";
                    if (letters != "" && !itemInVector(letters, returnWords))
                    {
                        returnWords.push_back(letters);
                    }
                }
                // else 
                // {
                //     returnWord = returnWord + "";
                // }
            }
        }
    }
    // return returnWord;
}

void searchLine(Dictionary d, const vector<string>& v, int size) // make this return a vector of strings that were found in the line
{
    vector<string> vRev = reverseVector(v);
    // string returnWord;
    // vector<string> returnWords;

    // returnWord = checkVector(d, v);

    // cout << vectorToString(v) << endl;
    // cout << vectorToString(vRev) << endl;
    checkVector(d, v);
    checkVector(d, vRev);
    // if (returnWord != "")
    // {
    //     returnWords.push_back(returnWord);
    // }
    // returnWord = checkVector(d, vRev);
    // if (returnWord != "")
    // {
    //     returnWords.push_back(returnWord);
    // }

    vector<string> v2 = v;
    vector<string> vRev2 = vRev;
    firstToLast(v2);
    firstToLast(vRev2);
    // cout << vectorToString(v2) << endl;
    // cout << vectorToString(vRev2) << endl;

    while (v2 != v)
    {
        checkVector(d, v2);

        checkVector(d, vRev2);
        // returnWord = checkVector(d, v2);
        // if (returnWord != "" && !itemInVector(returnWord, returnWords))
        // {
        //     returnWords.push_back(returnWord);
        // }
        // returnWord = checkVector(d, vRev2);
        // if (returnWord != "" && !itemInVector(returnWord, returnWords))
        // {
        //     returnWords.push_back(returnWord);
        // }

        firstToLast(v2);
        firstToLast(vRev2);
    }
}

void findMatches(Dictionary d, Grid g) // have this print all the words that were found in the lines
// Passed a dictionary and grid, prints all the words that can be found in the grid
{
    int s = g.getSize();
    for (int i = 0; i < s; i++)
    {
        // cout << "Calling getRow in row " << i << endl;
        searchLine(d, g.getRow(i), s);
        // cout << vectorToString(returnWords, false) << endl;
        // cout << "Calling getColumn in column " << i << endl;
        searchLine(d, g.getColumn(i), s);
        // cout << vectorToString(returnWords, false) << endl;
        for (int j = 0; j < s; j++)
        {
            if (i == 0)
            {
                if (j <= s - 5)
                {
                    // cout << "Calling LeftDiagonal at index " << i << ", " << j << endl;
                    vector<string> leftDiag = g.getLeftDiagonal(i, j);
                    // cout << vectorToString(leftDiag) << endl;
                    searchLine(d, leftDiag, leftDiag.size());
                    // cout << vectorToString(returnWords, false) << endl;
                }
                if (j >= 4)
                {
                    // cout << "Calling RightDiagonal at index " << i << ", " << j << endl;
                    vector<string> rightDiag = g.getRightDiagonal(i, j);
                    // cout << vectorToString(rightDiag, false) << endl;
                    searchLine(d, rightDiag, rightDiag.size());
                    // cout << vectorToString(returnWords, false) << endl;
                }
            }
            else 
            {
                if (i <= s - 5)
                {
                    // cout << "Calling LeftDiagonal at index " << i << ", " << 0 << endl;
                    vector<string> leftDiag = g.getLeftDiagonal(i, 0);
                    // cout << vectorToString(leftDiag) << endl;
                    searchLine(d, leftDiag, leftDiag.size());
                    // cout << vectorToString(returnWords, false) << endl;

                    // cout << "Calling RightDiagonal at index " << i << ", " << s - 1 << endl;
                    vector<string> rightDiag = g.getRightDiagonal(i, s - 1);
                    // cout << vectorToString(rightDiag, false) << endl;
                    searchLine(d, rightDiag, rightDiag.size());
                    // cout << vectorToString(returnWords, false) << endl;
                    
                    break;
                }
            }
        }
    }
    cout << vectorToString(returnWords, true) << endl;
}

void search(Dictionary d, int sortType)
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
    // cout << endl << "Enter the sorting algorithm to be used.\n0: Selection Sort\n1: Quick Sort\n2: Heap Sort\nEnter Here: ";
    // cin >> sortType;
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
}

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

    // SEARCH TESTING
    search(dict, 1); // quickSort
    // search(dict, 2); // heapSort
    // search(dict, 0); // selectionSort
}
