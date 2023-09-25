#ifndef MASTERMIND_H
#define MASTERMIND_H

#include <iostream>
using namespace std;

#include "Code.h"
#include "Response.h"

class Mastermind {
    private:
        Code code;
    public:
        Mastermind();
        Mastermind(int n, int m);
        void print_secret_code() const;
        Code humanGuess();
        Response getResponse(Code& guess);
        bool isSolved(Response& response);
        void playGame();
};

#endif //MASTERMIND_H