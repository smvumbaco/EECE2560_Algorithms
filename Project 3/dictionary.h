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
        void selectionSortDictionary();
        bool binarySearch(string word);     // I changed this to bool so I could use it in a TF statement, lmk if that messes you up
};

#endif