// Project 1
// 
// class Code declaration for Mastermind.
// Sean Vumbaco and Drew Balfour
//

#ifndef CODE_H
#define CODE_H

#include <iostream>
#include <vector>
using namespace std;

class Code {
    private:
        int code_length;
        int digit_range;
        vector<int> code;
        void init();
        int in_code(int digit) const;
        int in_vector(int digit, vector<int> int_vector) const;
    public:
        Code();
        Code(int n, int m);
        Code(int n, int m, vector<int> v);
        int get_code_length() const;
        int get_digit_range() const;
        vector<int> get_code() const;
        int checkCorrect(Code &guess) const; // Maybe friend
        int checkIncorrect(Code &guess) const; // Maybe friend
        friend ostream& operator<<(ostream& out, Code& guess);
};

#endif //CODE_H