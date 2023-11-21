// Group 11: Drew Balfour and Sean Vumbaco 
// Project 3 (parts a and b)

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#include "dictionary.h"
#include "heap.h"

Dictionary::Dictionary()
// Constructor for Dictionary object
// Returns nothing, simply defines Dictionary object
// Takes no arguments
// Assumes that "dictionary" is a file in the same directory as Dictionary.cpp
{
    ifstream inputFile("dictionary");
    if (!inputFile.is_open())
    {
        cerr << "Error opening the file.";
    } 
    else 
    {
        string newWord;
        while (inputFile >> newWord) 
        {
            dictionary.push_back(newWord);
        }
    }
    inputFile.close();
}

void Dictionary::printDictionary()
// Prints the dictionary object as a lift of words - used for debugging
// Returns nothing, simply prints dictionary
// Takes no arguments
{
    for (int i = 0; i < dictionary.size(); i++)
    {
        cout << dictionary[i] << endl;
    }
}

void Dictionary::selectionSort()
// Uses selection sort to order the dictionary using comparison of ASCII characters
// Returns nothing, simply manipulates dictionary object
// Takes no arguments
// Assumes dictionary is not empty 
{
    int n = dictionary.size();
    int minIndex;
    string temp;

    for (int i = 0; i < n - 1; i++) 
    {
        minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (dictionary[j] < dictionary[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i) 
        {
            temp = dictionary[i];
            dictionary[i] = dictionary[minIndex];
            dictionary[minIndex] = temp;
        }
    }
}

int Dictionary::partition(int p, int r) 
// Helper function for quicksort function - partitions dictionary[p] to dictionary[r]
// Returns an integer
// Takes 2 arguments related to positioning
// Assumes dictionary is not empty
{
    string x = dictionary[r]; // Pivot
    int i = p - 1; // End of left list
    for (int j = p; j <= r; j++ )
    {
        if(dictionary[j] < x) 
        {
            i += 1; // increase size of left
            // Shift right list right
            string temp = dictionary[i];
            dictionary[i] = dictionary[j];
            dictionary[j] = temp;
        }
    }
    // Move pivot to the middle
    string temp = dictionary[r];
    dictionary[r] = dictionary[i+1];
    dictionary[i+1] = temp;

    return i+1; // Pivot location
}

void Dictionary::quickSort(int low = 0, int high = 88993)
// Uses quick sort to sort items in the dictionary alphabetically
// Returns nothing, simply manipulates dictionary object
// Takes 2 arguments low and high indices
// Assumes dictionary is not empty 
{
    if (low < high) 
    {
        int s = partition(low, high);
        quickSort(low, s-1); // Sort the two
        quickSort(s+1, high); // Subarrays recursively
    }
}

int Dictionary::binarySearch(string word, int low = 0, int high = 88993)
// Finds the index of a word in the dictionary
// Returns an integer of the index of the word to search for
// Takes the word to be found as well as low and high indices to search between
// Assumes the dictionary has been sorted
{
    int midpoint = (low + high) / 2;
    if (low <= high)
    {
        if (word == dictionary[midpoint])
            return midpoint;
        if (word < dictionary[midpoint])
            return binarySearch(word, low, midpoint - 1);
        if (word > dictionary[midpoint])
            return binarySearch(word, midpoint + 1, high);
    }
    return -1; // Handles case where low > high (even initially)
}

void Dictionary::heapSort()
// uses heapsort to sort itms in the dictionary alphabetically
// Returns nothing, simply manipulates dictionary object
// Takes no arguments
// Assumes dictionary is not empty
{
    Heap<string> d(dictionary);
    d.heapsort();
    // dictionary = d.vec;
    dictionary = d.getVec();
}