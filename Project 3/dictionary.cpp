// Group 11: Drew Balfour and Sean Vumbaco 
// Project 3 (parts a and b)

// Write a program that solves a word search puzzle. The program reads an n x n grid of letters from
// a file and prints out all the words that can be found in the grid. Words can be found in the array
// by starting from any letter and reading left, right, up, down, or along any of the four diagonals.
// Words can also wrap around the edges of the array. Words must be at least 5 characters long.
// The list of k possible words is included in the file dictionary. Several sample word search puzzles
// are also provided.
// The goal is to find an algorithm that solves this problem that runs as quickly as possible for large
// n and k.

// Implement a class called dictionary that reads the words from the dictionary file and stores
// them in a vector, and which includes:
// (a) a function to read the words from the dictionary file,
// (b) a function to print the word vector,
// (c) a function that sorts the words using selectionsort,
// (d) a function to handle word lookups using binary search.

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#include "dictionary.h"
#include "heap.h"

Dictionary::Dictionary()
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
    // printDictionary(); // Comment this out later
    // cout << "Dictionary size: " << dictionary.size() << endl;
}

void Dictionary::printDictionary()
{
    for (int i = 0; i < dictionary.size(); i++)
    {
        cout << dictionary[i] << endl;
    }
}

void Dictionary::selectionSortDictionary()
// Uses selection sort to order the dictionary using comparison of ASCII characters
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
            // swap(dictionary[i], dictionary[minIndex]);
            temp = dictionary[i];
            dictionary[i] = dictionary[minIndex];
            dictionary[minIndex] = temp;
        }
    }
}

// Helper function for quicksort function - partitions dictionary[p] to dictionary[r]
int Dictionary::partition(int p, int r) 
{
    string x = dictionary[r]; // Pivot
    int i = p - 1; // End of left list
    for (int j = p; j <= r; j++ )//for (int j = p; j < r - 1; j++) // Scan unassigned
    {
        if(dictionary[j] < x)//if (dictionary[j] <= x) // Belongs in the left
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

void Dictionary::quickSortDictionary(int low = 0, int high = 88993)
{
    if (low < high) 
    {
        int s = partition(low, high);
        quickSortDictionary(low, s-1); // Sort the two
        quickSortDictionary(s+1, high); // Subarrays recursively
    }
}

// Assumed that dictionary has been SORTED
int Dictionary::binarySearch(string word, int low = 0, int high = 88993)
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
    else
        return -1;
//    int midpoint = (low + high) / 2;
//    if (word == dictionary[midpoint]) // Value has been found
//    {
//        return midpoint;
//    }
//    if (low >= high) // Value has not been found
//    {
//        return -1;
//    }
//    if (word < dictionary[midpoint])
//    {
//        return binarySearch(word, low, midpoint - 1);
//    }
//    //if (word > dictionary[midpoint])
//    else
//    {
//        return binarySearch(word, midpoint+1, high);
//    }
}

void Dictionary::heapSort()
// uses heapsort to sort dictionary
{
    Heap<string> d(dictionary);
    d.heapsort();
    // dictionary = d.vec;
    dictionary = d.getVec();
}