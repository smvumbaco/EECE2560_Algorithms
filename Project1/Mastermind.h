// Group 11: Drew Balfour & Sean Vumbaco
// Project 1 (parts a and b)

// Contains class Mastermind delclaration.

#ifndef MASTERMIND_H
#define MASTERMIND_H

#include <iostream>
using namespace std;

#include "Code.h"
#include "Response.h"

class Mastermind {
    private:
    // member data
        Code code;
    public:
        // constructors
        Mastermind();
        Mastermind(int n, int m);
        // member functions
        void print_secret_code() const;
        Code humanGuess();
        Response getResponse(Code guess);
        bool isSolved(Response response);
        void playGame();
};

#endif //MASTERMIND_H