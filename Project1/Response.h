#ifndef RESPONSE_H
#define RESPONSE_H

#include <iostream>
using namespace std;

class Response {
    private:
        int num_correct;
        int num_incorrect;
    public:
        Response(int corr, int incorr);
        int get_num_correct() const;
        int get_num_incorrect() const;
        void set_num_correct(int new_value);
        void set_num_incorrect(int new_value);
        friend bool operator==(const Response& response1, const Response& response2);
        friend ostream& operator<<(ostream& out, Response& response);
        };

#endif //RESPONSE_H