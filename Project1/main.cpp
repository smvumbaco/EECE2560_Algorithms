// Project 1
// 
// Main program for Project 1a
//
// Sean Vumbaco and Drew Balfour
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Code.h"
#include "Response.h"
#include "Mastermind.h"


const int guess1_array[5] = {5, 0, 3, 2, 6};
const int guess2_array[5] = {2, 1, 2, 2, 2};
const int guess3_array[5] = {1, 3, 3, 4, 5};

const vector<int> guess1_vector(guess1_array, guess1_array + 5);
const vector<int> guess2_vector(guess2_array, guess2_array + 5);
const vector<int> guess3_vector(guess3_array, guess3_array + 5);

int main()
{
    // Part 1 main.cpp ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    // Initializes a secret code and prints out th result of calling
    int n, m;
    cout << "How long will your code be?" << endl;
    cin >> n;
    cout << "What is the range of digits in your code?" << endl;
    cin >> m;
    Code answer(n, m);  
    
    // checkCorrect and checkIncorrect for 3 sample code guesses:
    // ((5, 0, 3, 2, 6), (2, 1, 2, 2, 2), (1, 3, 3, 4, 5))
    Code guess1(n, m, guess1_vector);
    Code guess2(n, m, guess2_vector);
    Code guess3(n, m, guess3_vector);

    cout << "Code: " << answer << endl << endl;

    cout << "CheckCorrect for " << guess1 << ": " << answer.checkCorrect(guess1) << endl;
    cout << "CheckIncorrect for " << guess1 << ": " << answer.checkIncorrect(guess1) << endl;

    cout << "CheckCorrect for " << guess2 << ": " << answer.checkCorrect(guess2) << endl;
    cout << "CheckIncorrect for " << guess2 << ": " << answer.checkIncorrect(guess2) << endl;

    cout << "CheckCorrect for " << guess3 << ": " << answer.checkCorrect(guess3) << endl;
    cout << "CheckIncorrect for " << guess3 << ": " << answer.checkIncorrect(guess3) << endl;
    */

    // Part 2 main.cpp ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Mastermind game();
    game.playGame();

}
