// Group 11: Drew Balfour & Sean Vumbaco
// Project 1 (parts a and b)


// Main program file for Project 1, Executes a Mastermind game 
// for set inputs (part a) and for user-generated inputs (part b)

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Code.h"
#include "Code.cpp" // Check this later....
#include "Response.h"
#include "Response.cpp"
#include "Mastermind.h"
#include "Mastermind.cpp"


// Declare vectors for Part a
const int guess1_array[5] = {5, 0, 3, 2, 6};
const int guess2_array[5] = {2, 1, 2, 2, 2};
const int guess3_array[5] = {1, 3, 3, 4, 5};
const vector<int> guess1_vector(guess1_array, guess1_array + 5);
const vector<int> guess2_vector(guess2_array, guess2_array + 5);
const vector<int> guess3_vector(guess3_array, guess3_array + 5);

int main()
{
    // Part a main.cpp ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // // Initializes a secret code and prints out th result of calling
    // int n, m;
    // cout << "How long will your code be?" << endl;
    // cin >> n;
    // cout << "What is the range of digits in your code?" << endl;
    // cin >> m;
    // Code answer(n, m);  
    
    // // checkCorrect and checkIncorrect for 3 sample code guesses:
    // // ((5, 0, 3, 2, 6), (2, 1, 2, 2, 2), (1, 3, 3, 4, 5))
    // Code guess1(n, m, guess1_vector);
    // Code guess2(n, m, guess2_vector);
    // Code guess3(n, m, guess3_vector);

    // cout << "Code: " << answer << endl << endl;

    // cout << "CheckCorrect for " << guess1 << ": ";
    // cout << answer.checkCorrect(guess1) << endl;
    // cout << "CheckIncorrect for " << guess1 << ": ";
    // cout << answer.checkIncorrect(guess1) << endl;

    // cout << "CheckCorrect for " << guess2 << ": ";
    // cout << answer.checkCorrect(guess2) << endl;
    // cout << "CheckIncorrect for " << guess2 << ": ";
    // cout << answer.checkIncorrect(guess2) << endl;

    // cout << "CheckCorrect for " << guess3 << ": ";
    // cout << answer.checkCorrect(guess3) << endl;
    // cout << "CheckIncorrect for " << guess3 << ": ";
    // cout << answer.checkIncorrect(guess3) << endl;


    // Part b main.cpp ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Declare and play Mastermind game
    //initialize Mastermind object, run playGame(), and print secret code
    Mastermind game;
    game.playGame();

}
