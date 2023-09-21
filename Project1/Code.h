#ifndef CODE_H
#define CODE_H

#include <iostream>
#include <vector>
using namespace std;

class Code {
    private:
        int code_length;
        int digit_range;
        void init();
    public:
        Code(int n, int m);
        int checkCorrect(Code &guess);
        int checkIncorrect(Code &guess);
};

#endif //CODE_H