// Group 11: Drew Balfour & Sean Vumbaco
// Project 1 (parts a and b)

// Contains member functions for class Mastermind. Including: 2 constructors, 
// print_secret_code, humanGuess, getResponse, isSolved, and playGame
#include <iostream>
#include <string>
using namespace std;

#include "Mastermind.h"

Mastermind::Mastermind() 
// Default class Mastermind constructor. Takes no arguments.
{
    code = Code(5, 10);
}

Mastermind::Mastermind(int n, int m) 
// Class Mastermind constructor that specifies the length and digit range of
// the code data member. Takes 2 int arguments. 
{
    code = Code(n, m);
}

void Mastermind::print_secret_code() const 
// Prints the code data member of a Mastermind object. Function iterates
// through the code object and prints each value in the vector. Takes no 
// arguments. Does not return data. Assumes no data members will be changed. 
{
    string str = "[";

    for (int i = 0; i < code.get_code_length(); i++) {
        str += to_string(code.get_code()[i]);

        if (i < code.get_code_length() - 1) {
            str += ", ";
        }
    }
    str += "]";
    cout << str << endl;
} // end print_secret_code

Code Mastermind::humanGuess() 
// Reads a guess from the keyboard. Function receives data from the user and 
// stores it in a temporary code object. Returns the code object that 
// represents the guess. Assumes data will be entered upon function call.
{
    vector<int> guesses(0);
    int code_length = code.get_code_length();
    int guess;

    for (int i = 0; i < code_length; i++) {
        cin >> guess;
        guesses.push_back(guess);
    }

    Code guess_code(code_length, code.get_digit_range(), guesses);
    return guess_code;
} // end humanGuess

Response Mastermind::getResponse(Code guess) 
// Generates a response. Function is passed 1 Code object and generates a 
// Response object. Returns this response object indicating the number of 
// correct and incorrect guesses. Assumes the data passed is a Code object
// that is the same size as Mastermind's code data member. 
{
    Response response(code.checkCorrect(guess), code.checkIncorrect(guess));
    return response;
}

bool Mastermind::isSolved(Response response) 
// Indicates whether the code has been solved. Function is passed a Response 
// object and returns whether the number correct equals the length of the code.
// Returns a bool. Assumes a Response object is passed.
{
    return response.get_num_correct() == code.get_code_length();
}

void Mastermind::playGame() 
// Initializes a random code, prints it to the screen, and then iteratively 
// gets a guess from the user and prints the response until either the 
// codemaker or the codebreaker has won. Function takes no arguments. Returns
// no data. Assumes user input will be entered upon function call. 
{
    // Prints the secret code. Used for debugging purposes.
    // print_secret_code();
    cout << "Welcome to Mastermind!" << endl;
    cout << "Please enter your first guess below:" << endl;
    bool status = false;
    Response guess(0, 0);

    for (int i = 0; i < 10; i++)
    {
        if (!status)
        {
            guess = getResponse(humanGuess());
            cout << endl << "Response: ";
            status = isSolved(guess);
            cout << guess << endl;
        } 
        else 
        {
            break;
        }
    }

    if (status)
    {
        cout << "CODEBREAKER WINS!" << endl;
    }
    else
    {
        cout << "CODEMAKER WINS!" << endl;
    }
}