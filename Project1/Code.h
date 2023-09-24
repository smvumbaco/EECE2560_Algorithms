#ifndef CODE_H
#define CODE_H

#include <iostream>
#include <vector>
using namespace std;

class Code {
    private:
        int code_length;
        int digit_range;
        vector<int> digits();
        void init();
    public:
        Code(int n, int m);
        Code(int n, int m, vector<int> v());
        int checkCorrect(Code &guess);
        int checkIncorrect(Code &guess);
        string print();
};

#endif //CODE_H