// Group 11: Drew Balfour and Sean Vumbaco 
// Project 3 (parts a and b)

// Contains class Heap declaration

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class T>
class Heap
{
    private:
    // member data
    vector<T> vec;
    int heapsize;
    public:
    // constructors
    Heap();
    Heap(vector<T> v);
    // member functions
    int parent(int p);
    int left(int l);
    int right(int r);
    T getItem(int i);
    void initializeMaxHeap();
    void maxHeapify(int i);
    void buildMaxHeap();
    void heapsort();
    vector<T> getVec();
};

#endif // HEAP_H