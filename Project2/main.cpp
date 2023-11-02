// Group 11: Drew Balfour and Sean Vumbaco
// Project 2 (parts a and b)

// main.cpp file for Flip
// Part a: Create deck object and print 4 times, shuffling in between
// Part b: Execute playFlip - simulates a game of Flip

#include <iostream>
#include <string>
#include <queue>

using namespace std;

#include "Deck.h"
// #include "Deck.cpp"

void printCards(queue<Card> cards) 
// Helper function: prints a queue filled with Card objects
// Takes a queue<Card> object but returns nothing
{
    while (cards.size() > 0) 
    {
        cout << cards.front() << endl;
        cards.pop();
    }
}

int updatedScore(int score, Card card) 
// Helper function: performs all logic for updating the player score based on drawn card
// Takes a score integer and a Card object
{
    int value = card.getValue();
    int extraPoint = 0;

    // Add 1 if suit is Hearts
    if (card.getSuit() == 2) 
    {
        extraPoint = 1;
    }

    // Add 10 for Ace, 5 for Jack-King, 0 for 8-10
    // /2 for 7, return 0 for 2-6
    if (value == 1) 
    {
        return score + 10 + extraPoint;
    } 
    else if (value >= 11 && value <= 13) 
    {
        return score + 5 + extraPoint;
    } 
    else if (value >= 8 && value <= 10) 
    {
        return score + extraPoint;
    } 
    else if (value == 7) 
    {
        return score / 2 + extraPoint;
    } 
    else 
    {
        return 0 + extraPoint;
    }
}

void playFlip(Deck deck) 
// Executes game of Flip - reads user input to either flip next card or end the game
// Continuously prints updated player score
// Prints player hand and cards left in deck for debugging purposes
// Takes a Deck object but returns nothing
// Assumes deck is not empty
{
    for (int i = 0; i < 3; i++) 
    // Shuffle deck 3x
    {
        deck.shuffle();
    }

    // Declare variables
    bool playGame = true;
    int playerInput;
    int playerScore = 0;
    queue<Card> playerHand;
    for (int i = 0; i < 24; i++) 
    // Assemble player hand
    {
        playerHand.push(deck.deal());
    }

    // Print the cards drawn
    cout << "Cards drawn:" << endl;
    printCards(playerHand);
    cout << endl;

    cout << "Welcome to Flip!\n\n";
    while (playGame) 
    {
        // Prompt player
        cout << "Enter your Move:" << endl;
        cout << "0: End the Game." << endl;
        cout << "1: Flip the Next Card." << endl;
        cin >> playerInput;

        if (playerInput) 
        // Player opted to flip a card
        {
            cout << endl << "Card: " << playerHand.front() << endl;
            playerScore = updatedScore(playerScore, playerHand.front());
            cout << "New Score: " << playerScore << endl;
            if (playerHand.size() > 0) 
            // Still cards in player's hand
            {
                cout << "The game continues!" << endl;
            } 
            else 
            // No cards left in player's hand
            {
                cout << "That ends the game!" << endl;
                playGame = false;
            }
            // Remove card from player's hand, replace in bottom of deck
            deck.replace(playerHand.front());
            playerHand.pop();
        } 
        else 
        // Player opted to end the game
        {
            cout << endl << "That ends the game!" << endl;
            playGame = false;
        }

        // Print the remaining cards in the deck
        cout << "Remaining cards in deck:" << endl;
        cout << deck << endl;

        // Print the player's hand
        cout << "Player's current hand:" << endl;
        printCards(playerHand);
    }
}

int main() 
{
    // PART B
    Deck deck = Deck();
    // Card c(1,1);
    // deck.replace(c);
    // cout << deck << endl;
    playFlip(deck);

    // PART A
    // Deck deck = Deck();
    // cout << deck << endl;
    // deck.shuffle();
    // cout << deck << endl;
    // deck.shuffle();
    // cout << deck << endl;
    // deck.shuffle();
    // cout << deck << endl;

    return 0;
}