// Group 11: Drew Balfour & Sean Vumbaco
// Project 1 (parts a and b)


// Contains class Response declaration for Mastermind.

#ifndef RESPONSE_H
#define RESPONSE_H

#include <iostream>
using namespace std;

class Response {
    private:
        // member data
        int num_correct;
        int num_incorrect;
    public:
        // constructor
        Response(int corr, int incorr);
        // member functions
        int get_num_correct() const;
        int get_num_incorrect() const;
        void set_num_correct(int new_value);
        void set_num_incorrect(int new_value);
        friend bool operator==(const Response& response1, const Response& response2);
        friend ostream& operator<<(ostream& out, Response& response);
        };

#endif //RESPONSE_H