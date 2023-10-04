// Project 1
// 
// Contains 2 Code constructors, and declarations for get_code_length, 
//get_digit_range, in_code, in_vector, checkCorrect, checkIncorrect,
// and operator<<
//
// Sean Vumbaco and Drew Balfour
// Group 11
//

#include <iostream>
#include <vector>
#include <random>
#include <string>
using namespace std;

#include "Code.h"

// default class constructor
Code::Code() {
    code_length = 5;
    digit_range = 10;
    init();
}

// class constructor given code_length and digit_range
Code::Code(int n, int m) {
    code_length = n;
    digit_range = m;
    init();
}

// class constructor given code_length, digit_range, and code
// used for codebreaker guesses
Code::Code(int n, int m, vector<int> v) {
    code_length = n;
    digit_range = m;
    for (int i = 0; i < code_length; i++) {
        code.push_back(v[i]);
    }
}

void Code::init() {
    // Generate a seed for the random number generator
    random_device rd;
    mt19937 gen(rd());

    // Define the range of the random number generator
    uniform_int_distribution<int> distribution(0, digit_range-1);

    // Build the vector and initialize with random integers
    for (int i = 0; i < code_length; i++) {
        code.push_back(distribution(gen));
    }
}

int Code::get_code_length() const {
    return code_length;
}

int Code::get_digit_range() const {
    return digit_range;
}

vector<int> Code::get_code() const {
    return code;
}

// Returns the index at which num is at in the code or a -1 if it is not in the code
int Code::in_code(int num) const {
    for (int i = 0; i < code_length; i++) {
        if (code[i] == num) {
            return i;
        }
    }
    return -1;
}

// Returns true if num is in int_vector and false otherwise
int Code::in_vector(int num, vector<int> int_vector) const {
    for (int i = 0; i < int_vector.size(); i++) {
        if (num == int_vector[i]) {
            return true;
        }
    }
    return false;
}

// Returns the number of correct digits in the correct location
int Code::checkCorrect(Code &guess) const {
    int cor = 0;
    for (int i = 0; i < code_length; i++) {             // iterate through all elements of code
        if (code[i] == guess.code[i]) {                 // compares elements of code vector to given guess code vector
            cor++;                                      // add value to # of correct digits in correct locations
        }
    }
    return cor;                                         // return # of correct digits in correct locations
}

// Returns the number of correct digits in the incorret location
int Code::checkIncorrect(Code &guess) const {
    int incorr = 0;
    int index;
    vector<int> indices(0); // Indices in guess.code that have already been considered
    for (int i = 0; i < code.size(); i++) {
        index = Code::in_code(guess.code[i]);
        if (index >= 0) { // In guess code at index
            if (index != i) { // NOT at the same index as code
                if (!Code::in_vector(index, indices)) { // Index is NOT in vector of already-considered indices
                    incorr++;
                    indices.push_back(index);
                }
            } else { // At the same index as code
                indices.push_back(index);
            }
        }
    }
    return incorr;
}

ostream& operator<<(ostream& out, Code& input_code) {
    string str = "[";
    for (int i = 0; i < input_code.code_length; i++) {
        str += to_string(input_code.code[i]);
        if (i < input_code.code_length - 1) {
            str += ", ";
        }
    }
    str += "]";
    out << str;
    return out;
}