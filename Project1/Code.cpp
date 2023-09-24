#include <iostream>
#include <vector>
using namespace std;

#include "Code.h"

Code::Code(int n, int m) {
    code_length = n;
    digit_range = m;
    init();
}

Code::Code(int n, int m, vector<int> v()) {
    if (n == v.size()) {
        code_length = n;
        digit_range = m;
        digits[code_length] = v();
    }
}

void Code::init() {
    // Randomly initializes the code of length m based on a digit range from 0 to m-1
}

int Code::checkCorrect(Code &guess) const {
    // Returns the number of correct digits in the correct location
    int cor = 0;
    for (i = 0, i < code_length, i++) {
        if (digits[i] == &guess.digits[i])
        {
            cor++;
        }
    }
    return cor;
}

int Code::checkIncorrect(Code &guess) const {
    // Returns the number of correct digits in the incorret location
}


string Code::print() const {
    for (i = 0, i < code_length, i++) {
        cout << digits[i] << " " << endl
    }
}