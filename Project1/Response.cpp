// Group 11: Drew Balfour & Sean Vumbaco
// Project 1 (parts a and b)


// Contains member functions for class Response. Including: a constructor, 
// get_num_correct, set_num_correct, get_num_incorrect, set_num_incorrect,
// operator== overload, and operator<< overload

#include <iostream>
using namespace std;

#include "Response.h"

Response::Response(int corr, int incorr) 
// class Constructor. Corr is the number of correct digits in correct positions
// in a Code. Incorr is the number of correct digits in incorrect positions.
{
    num_correct = corr;
    num_incorrect = incorr;
}

int Response::get_num_correct() const
// Returns the number of correct digits in correct positions.
{
    return num_correct;
}

void Response::set_num_correct(int new_value)
// Changes the number of correct digits in correct positions. New_value is the 
// new number of correct digits. Function equates the Response num_correct
// with the new_value. 
{
    num_correct = new_value;
}

int Response::get_num_incorrect() const 
// Returns the number of correct digits in incorrect positions.
{
    return num_incorrect;
}

void Response::set_num_incorrect(int new_value) 
// Changes the number of correct digits in incorrect positions. New_value is 
// the new number of digits. Function equates the Response num_incorrect
// with the new_value.
{
    num_incorrect = new_value;
}

bool operator==(const Response& response1, const Response& response2) 
// Overloads operator == for class Response. Function takes two Responses and
// returns TRUE if both Responses have the same number of correct digits in 
// correct locations and the same number of correct digits in incorrect places
{
    return response1.num_correct == response2.num_correct && 
        response1.num_incorrect == response2.num_incorrect;
}

ostream& operator<<(ostream& out, Response& response) 
// Overloads operator << for class Response. Function takes a Response and
// a stream output to produce a custom stream output for all Responses. 
{
    out << response.num_correct << ", " << response.num_incorrect << endl;
    return out;
}