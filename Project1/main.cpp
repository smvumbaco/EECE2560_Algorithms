#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Code.h"
#include "Code.cpp"

int main()
{
    // Initializes a secret code and prints out th result of calling
    int n, m;
    cout << "How long will your code be?" << endl;
    cin >> n;
    cout << "What is the range of digits in your code?" << endl;
    cin >> m;
    Code answer(n, m);  
    
    // checkCorrect and checkIncorrect for 3 sample code guesses:
    // ((5, 0, 3, 2, 6), (2, 1, 2, 2, 2), (1, 3, 3, 4, 5))
    Code g1(n, m, { 5, 0, 3, 2, 6 });
    Code g2(n, m, { 2, 1, 2, 2, 2 });
    Code g3(n, m, { 1, 3, 3, 4, 5 });

    cout << "CheckCorrect for (5, 0, 3, 2, 6): " << answer.checkCorrect(g1) << endl;
    cout << "CheckIncorrect for (5, 0, 3, 2, 6): " << answer.checkIncorrect(g1) << endl;

    cout << "CheckCorrect for (2, 1, 2, 2, 2): " << answer.checkCorrect(g1) << endl;
    cout << "CheckIncorrect for (2, 1, 2, 2, 2): " << answer.checkIncorrect(g1) << endl;

    cout << "CheckCorrect for (1, 3, 3, 4, 5): " << answer.checkCorrect(g1) << endl;
    cout << "CheckIncorrect for (1, 3, 3, 4, 5): " << answer.checkIncorrect(g1) << endl;


    // Prints the secret code as well
    answer.print();
    
}