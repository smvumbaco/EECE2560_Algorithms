#include <iostream>
using namespace std;

#include "Response.h"

Response::Response(int corr, int incorr) {
    num_correct = corr;
    num_incorrect = incorr;
}

int Response::get_num_correct() const {
    return num_correct;
}

void Response::set_num_correct(int new_value) {
    num_correct = new_value;
}

int Response::get_num_incorrect() const {
    return num_incorrect;
}

void Response::set_num_incorrect(int new_value) {
    num_incorrect = new_value;
}

bool operator==(const Response& response1, const Response& response2) {
    return response1.num_correct == response2.num_correct && response1.num_incorrect == response2.num_incorrect;
}

ostream& operator<<(ostream& out, Response& response) {
    out << response.num_correct << ", " << response.num_incorrect << endl;
    return out;
}