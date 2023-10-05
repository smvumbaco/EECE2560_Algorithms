#include <iostream>
#include <string>
using namespace std;

#include "Mastermind.h"

// default class constructor
Mastermind::Mastermind() {
    code = Code(5, 10);
}

// class constructor given code_length and digit_range for class Code
Mastermind::Mastermind(int n, int m) {
    code = Code(n, m);
}

// Look into this later...
void Mastermind::print_secret_code() const {
    // a function that prints the secret code
    // cout << code << endl;
    // string str = "[";
    // for (int i = 0; i < code.get_code_length(); i++) {
    //     str += to_string(code.get_code()[i]);
    //     if (i < code.get_code_length() - 1) {
    //         str += ", ";
    //     }
    // }
    // str += "]";
    // cout << str;
}

Code Mastermind::humanGuess() {
    //reads a guess from the keyboard and returns a code object that represents the guess
    vector<int> guesses(0);
    int code_length = code.get_code_length();
    int guess;
    // cout << "Code Guess: [";
    for (int i = 0; i < code_length; i++) {
        cin >> guess;
        guesses.push_back(guess);
        // if (i != code_length - 1) {
        //     cout << ", ";
        // }
    }
    // cout << "]";
    Code guess_code(code_length, code.get_digit_range(), guesses);
    return guess_code;
}

Response Mastermind::getResponse(Code guess) {
    // assed one code (a guess code), and returns a response
    Response response(code.checkCorrect(guess), code.checkIncorrect(guess));
    return response;
}

bool Mastermind::isSolved(Response response) {
    // Passed a response and returns true if the response indicates that the board has been solved
    return response.get_num_correct() == code.get_code_length();
}

void Mastermind::playGame() {
    // initializes a random code, prints it to the screen, and then
    // iteratively gets a guess from the user and prints the response until either the codemaker
    // or the codebreaker has won
    print_secret_code();

    cout << "Welcome to Mastermind!" << endl << "Please enter your first guess below:" << endl;

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
        } else {
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