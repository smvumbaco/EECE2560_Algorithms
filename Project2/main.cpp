// Sean Work:
// deck constructor
// shuffle
// overloaded cout 
// destructor
// playFlip

// Drew Work:
// Card class
// make node a template
// deck's deal function
// deck's replace function

#include <iostream>
#include <string>
#include <queue>

using namespace std;

#include "Deck.h"
#include "Deck.cpp"

void printCards(queue<Card> cards) {
    while (cards.size() > 0) {
        cout << cards.front() << endl;
        cards.pop();
    }
}

int updatedScore(int score, Card card) {
    int value = card.getValue();
    int extraPoint = 0;
    if (card.getSuit() == 2) {
        extraPoint = 1;
    }
    if (value == 1) {
        return score + 10 + extraPoint;
    } else if (11 <= value <= 13) {
        return score + 5 + extraPoint;
    } else if (8 <= value <= 10) {
        return score + extraPoint;
    } else if (value == 7) {
        return score / 2 + extraPoint;
    } else {
        return 0;
    }
}
// plays the game by reading instructions from the
// keyboard (i.e., whether or not flip the next card) and printing the results (including but
// not limited to the card just flipped, the player’s current score, and whether or not the game
// is end) to the screen. You should print the top 24 cards and the remaining cards of the deck
// to the screen. Also, you should print the current hand after flipping a card to the screen.
// We’ll use the information to see if your program is working correctly
void playFlip(Deck deck) {
    for (int i = 0; i < 3; i++) {
        deck.shuffle();
    }

    bool playGame = true;
    int playerInput;
    int playerScore = 0;
    queue<Card> playerHand;
    for (int i = 0; i < 24; i++) {
        playerHand.push(deck.deal());
    }

    // Print the cards drawn
    cout << "Cards drawn:" << endl;
    printCards(playerHand);
    cout << endl;

    cout << "Welcome to Flip!\n\n";
    while (playGame) {
        cout << "Enter your Move:" << endl;
        cout << "0: Flip the next card." << endl;
        cout << "1: End the game." << endl;
        cin >> playerInput;

        // Potential pain point here (user input, datatypes, etc.)
        if (playerInput) {
            cout << endl << "Card: " << playerHand.front() << endl;
            playerScore = updatedScore(playerScore, playerHand.front());
            cout << "New Score: " << playerScore << endl;
            if (playerHand.size() > 0) {
                cout << "The game continues!" << endl;
            } else {
                cout << "That ends the game!" << endl;
                playGame = false;
            }
            deck.replace(playerHand.front());
            playerHand.pop();
        } else {
            cout << endl << "That ends the game!" << endl;
            playGame = false;
        }

        // Print the remaining cards in the deck
        cout << "Remaining cards in deck:" << endl;
        cout << deck << endl;
    }
}

int main() 
{
    Deck deck = Deck();
    playFlip(deck);

    // PART A
    // Deck deck = Deck();
    // cout << deck << endl;
    // deck.shuffle();
    // cout << endl << deck << endl;

    return 0;
}