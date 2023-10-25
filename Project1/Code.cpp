// Group 11: Drew Balfour & Sean Vumbaco
// Project 1 (parts a and b)


// Contains member functions for class Code. Including: 3 constructors, init,
// get_code_length, get_digit_range, get_code, in_vector, checkCorrect,
// checkIncorrect, operator<< overload

#include <iostream>
#include <vector>
#include <random>
#include <string>
using namespace std;

#include "Code.h"

Code::Code() 
// default class Code constructor
{
    code_length = 5;
    digit_range = 10;
    init();
}

Code::Code(int n, int m) 
// class constructor. n is the code_length and m is the digit_range.
// Constructor initialized a new secret Code 
{
    code_length = n;
    digit_range = m;
    init();
}

Code::Code(int n, int m, vector<int> v) 
// class constructor. n is the code_length and m is the digit_range.
// Constructor sets the secret code to the given vector v.
{
    code_length = n;
    digit_range = m;
    for (int i = 0; i < code_length; i++) 
    {
        code.push_back(v[i]);
    }
}

void Code::init() 
// Initializes the secret code randomly.
{
    // Generate a seed for the random number generator
    random_device rd;
    mt19937 gen(rd());

    // Define the range of the random number generator
    uniform_int_distribution<int> distribution(0, digit_range-1);

    // Build the vector and initialize with random integers
    for (int i = 0; i < code_length; i++) 
    {
        code.push_back(distribution(gen));
    }
}

int Code::get_code_length() const 
// Returns Code private data member code_length as an int
{
    return code_length;
}

int Code::get_digit_range() const 
// Returns Code private data member digit_range as an int
{
    return digit_range;
}

vector<int> Code::get_code() const 
// Returns Code private data member code as a vector<int>
{
    return code;
}

int Code::in_vector(int num, vector<int> int_vector) const 
// Returns true if num is in int_vector and false otherwise
{
    for (int i = 0; i < int_vector.size(); i++) 
    {
        if (num == int_vector[i]) 
        {
            return true;
        }
    }
    return false;
}

int Code::checkCorrect(Code &guess) const 
// Returns the number of correct digits in the correct location
// Assumes guess is the same length as 
// return # of correct digits in correct locations
{
    int cor = 0;
    for (int i = 0; i < code_length; i++) 
    {             
        if (code[i] == guess.code[i]) 
        {                 
            cor++;                                      
        }
    }
    return cor;                                         
}

int Code::checkIncorrect(Code &guess) const 
// Counts the number of correct digits in the incorret location. Function
// takes a Code and compares every index of the Code's code and compares it
// to this object's code. Returns the number of correct digits in the incorret 
// location. Assumes guess and secret code are always the same size
{
    int incorr = 0;
    vector<int> i_indices;
    vector<int> j_indices;
    for (int k = 0; k < code_length; k++) 
    {
        if (code[k] == guess.code[k]) 
        // accounts for values counted by checkCorrect
        {
                i_indices.push_back(k);
                j_indices.push_back(k);
        }
    }
    for (int i = 0; i < code_length; i++) 
    { 
        for (int j = 0; j < code_length; j++) 
        { 
            if (i != j && code[i] == guess.code[j] && 
                !in_vector(i, i_indices) && !in_vector(j, j_indices))
            {
                incorr++;
                i_indices.push_back(i);
                j_indices.push_back(j);
            }
        }
    }
    return incorr;
} // end checkIncorrect

ostream& operator<<(ostream& out, Code& input_code) 
// Overloads operator << for class Code. Function takes a Code and
// a stream output to produce a custom stream output for all Codes. 
{
    string str = "[";
    // print code vector as the element in each indeces separated by a comma
    for (int i = 0; i < input_code.code_length; i++) 
    {
        str += to_string(input_code.code[i]);
        if (i < input_code.code_length - 1) 
        {
            str += ", ";
        }
    }
    str += "]";
    out << str;
    return out;
} // end operator<<