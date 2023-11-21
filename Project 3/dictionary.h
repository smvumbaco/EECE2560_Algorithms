// Group 11: Drew Balfour & Sean Vumbaco
// Project 3 (parts a and b)

// Contains class Dictionary declaration

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Dictionary {
    private:
        vector<string> dictionary;
    public:
        Dictionary();
        void printDictionary();
        void selectionSort();
        int partition(int p, int r);
        void quickSort(int low, int high);
        int binarySearch(string word, int low, int high);
        void heapSort();
};

#endif