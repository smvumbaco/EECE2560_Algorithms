#include <iostream>
#include <vector>
using namespace std;

#include "Code.h"

Code::Code(int n, int m) {
    code_length = n;
    digit_range = m;
    init();
}

void Code::init() {
    // Randomly initializes the code of length m based on a digit range from 0 to m-1
}

int Code::checkCorrect(Code &guess) const {
    // Returns the number of correct digits in the correct location
}

int Code::checkIncorrect(Code &guess) const {
    // Returns the number of correct digits in the incorret location
}