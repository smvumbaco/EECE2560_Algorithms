// Group 11: Drew Balfour & Sean Vumbaco
// Project 4 (parts a and b)

// Main program file for Project 4, ...

// Part b:
//Complete your program that solves Sudoku puzzles. Your algorithm should be based on
//recursion.
//Your algorithm should read each board from the text file, solve it, print the solution, and
//print the number of recursive iterations needed to solve that board. After all boards have
//been solved, print the average number of recursive calls needed to solve all the boards.
//Print the total number of your recursive calls.


#include <iostream>
#include <limits.h>
// #include "Board.h"
#include "d_matrix.h"
#include "d_except.h"
#include <string>
#include <list>
#include <fstream>
#include <stack>

using namespace std;

typedef int ValueType;
const int Blank = -1;

const int SquareSize = 3;
const int BoardSize = SquareSize * SquareSize;
const int MinValue = 1;
const int MaxValue = 9;
int numSolutions = 0;
const int NoConflict = 0;
const int YesConflict = 1;

const int numberOfBoards = 96;
int recursiveCalls = 0;
int totalRecursiveCalls = 0;
stack<vector<int>> guesses;

class Board
{
    public:
        Board(int);
        void clear();
        void initialize(ifstream &fin);
        void print();
        bool isBlank(int, int);
        ValueType getCell(int, int); 
        void setCell(int, int, int);
        void clearCell(int, int);
        void printConflicts();
        bool isSolved();
        void updateConflicts(int, int, int, ValueType);
        vector<int> getConflicts(int, int);
        ValueType getEmptyConflict(int, int, int);
        bool moreEmpty(int, int, ValueType);
    private:
        // The following matrices go from 1 to BoardSize in each
        // dimension, i.e., they are each (BoardSize+1) * (BoardSize+1)
        matrix<ValueType> value;
        matrix<vector<ValueType>> conflicts;
};

Board::Board(int sqSize)
    : value(BoardSize+1, BoardSize+1),
        conflicts(BoardSize+1, BoardSize+1, vector<ValueType> (BoardSize, NoConflict))
{
    clear();
}

void Board::clear()
{
    for (int i = 1; i <= BoardSize; i++)
        for (int j = 1; j <= BoardSize; j++)
        {
            value[i][j] = Blank;
            for (int k = 0; k < BoardSize; k++)
                conflicts[i][j][k] = NoConflict;
        }
}

void Board::initialize(std::ifstream &fin)
// Read a Sudoku board from the input file
{
    char ch;
    clear();
    for (int i = 1; i <= BoardSize; i++)
        for (int j = 1; j <= BoardSize; j++)
        {
            fin >> ch;
            if (ch!= '.')
                setCell(i, j, ch-'0');
        }
}

int squareNumber(int i, int j)
// Return the square number of cell i,j (counting from left to right,
// top to bottom. Note that i and j each go from 1 to BoardSize
{
// Note that (int) i/SquareSize and (int) j/SquareSize are the x-y
// coordinates of the square that i,j is in.
    return SquareSize * ((i - 1) / SquareSize) + (j - 1) / SquareSize + 1;
}

ostream &operator<<(ostream &ostr, vector<int> &v)
// Overloaded output operator for vector class.
{
    for (int i = 0; i < v.size(); i++)
        ostr << v[i] << " ";
    // cout << endl;
    ostr << endl;
    return ostr;
}

ValueType Board:: getCell(int i, int j)
// Return the value stored in a cell. Throws an exception if bad values are
// passed.
{
    if (i >= 1 && i <= BoardSize && j >= 1 && j <= BoardSize)
        return value[i][j];
    else
        throw rangeError("bad value in getCell");
}

void Board::setCell(int i, int j, int newValue)
// Returns nothing - just updates cell value. Throws an exception
// if bad values are passed.
{
    // if (newValue == 10)
    //     newValue -= 9;
    if (i >= 1 && i <= BoardSize && j >= 1 && j <= BoardSize)
        value[i][j] = newValue;
    else
        throw rangeError("bad value in getCell");
    // Update conflicts vectors
    updateConflicts(i, j, newValue, YesConflict);
}

void Board::clearCell(int i, int j)
// Returns nothing - just clears cell value. Throws an exception
// if bad values are passed.
{
    int val;
    if (i >= 1 && i <= BoardSize && j >= 1 && j <= BoardSize)
    {
        val = value[i][j];
        value[i][j] = Blank;
    }
    else
        throw rangeError("bad value in getCell");
    // Update conflicts vectors
    updateConflicts(i, j, val, NoConflict);
}

bool Board::isBlank(int i, int j)
// Returns true if cell i, j is blank, and false otherwise.
{
    if (i < 1 || i > BoardSize || j < 1 || j > BoardSize)
        throw rangeError("bad value in setCell");
    return (getCell(i, j) == Blank);
}

void Board::print()
// Prints the current board.
{
    for (int i = 1; i <= BoardSize; i++) {
        if ((i - 1) % SquareSize == 0) {
            cout << " -";
            for (int j = 1; j <= BoardSize; j++)
                cout << "---";
            cout << "-";
            cout << endl;
        }
        for (int j = 1; j <= BoardSize; j++) {
            if ((j - 1) % SquareSize == 0)
                cout << "|";
            if (!isBlank(i, j))
                cout << " " << getCell(i, j) << " ";
            else
                cout << "   ";
        }
        cout << "|";
        cout << endl;
    }
    cout << " -";
    for (int j = 1; j <= BoardSize; j++)
        cout << "---";
    cout << "-";
    cout << endl;
} // end print()

void Board::printConflicts()
// Prints conflict vectors
{
    for ( int i = 1; i <= BoardSize; i++)
        for ( int j = 1; j <= BoardSize; j++)
            cout << "Conflicts[" << i << "][" << j << "]: " << conflicts[i][j];
}

vector<int> Board::getConflicts(int i, int j)
// Returns the conflict vector for the square i, j
{
    return conflicts[i][j];
}

ValueType Board::getEmptyConflict(int i, int j, ValueType firstVal = 0)
// Returns first empty conflict vector for square i,j
{
    for ( int k = firstVal; k <= BoardSize - 1; k++) // Iterate from 0 to 8
    {
        if (conflicts[i][j][k] == NoConflict)
            return k + 1; 
    }
    return Blank;
}

void Board::updateConflicts(int i, int j, int k, int s)
{
    // cout << "Updating conflict list of " << "<" << i << ", " << j << ">" << endl;
    int hStart = SquareSize * ((j - 1) / SquareSize) + 1;
    int vStart = SquareSize * ((i - 1) / SquareSize) + 1;
    for (int x = 1; x <= BoardSize; x++)
    {
        conflicts[x][j][k - 1] = s;
        conflicts[i][x][k - 1] = s;
    }
    for (int y = 0; y < SquareSize; y++)
    {
        // conflicts[vStart + y][j][k - 1] = s;
        for (int z = 0; z < SquareSize; z++)
        {
            // cout << "(" << vStart + y << ", " << hStart + z << ")" << endl;
            conflicts[vStart + y][hStart + z][k - 1] = s;
        }
    }
}

bool Board::isSolved()
// Checks to see if the board has been solved
{
    for (int i = 1; i <= BoardSize; i++)
        for (int j = 1; j <= BoardSize; j++)
        {
            if (value[i][j] == Blank)
                return false;
        }
    print();
    cout << recursiveCalls << endl;
    totalRecursiveCalls += recursiveCalls;
    recursiveCalls = 0;
    while (!guesses.empty())
        guesses.pop();
    return true;
}

bool Board::moreEmpty(int i, int j, ValueType val)
{
    for (int k = val; k <= SquareSize; k++)
    {
        if (conflicts[i][j][k] == NoConflict)
            return true;
    }
    return false;
}

void solveBoard(Board& b, int i = 1, int j = 1, int k = 1) 
// Actively solves the Sudoku board
{
    // b.print();
    if (!b.isSolved())
    {
        recursiveCalls++;
        // Set i and j to that of the first NOT blank cell
        while (!b.isBlank(i, j))
        {
            if (i < 9) 
                i++;
            else
            {
                i = 1;
                j++;
            }
        }
        // cout << "board isn't solved: i = " << i << ", j = " << j << endl;
        // Set the value at that cell to the first possible value
        guesses.push({i, j});
        int valueToPlace = b.getEmptyConflict(i, j, k);
        // cout << "valueToPlace = " << valueToPlace << endl;
        if (valueToPlace == Blank) // There is no possible value
        {
            // backTrack(b, i, j);
            // cout << "I am backtracking" << endl;
            ValueType val = b.getCell(i,j);
            guesses.pop();
            int i_prev = guesses.top()[0];
            int j_prev = guesses.top()[1];
            b.clearCell(i, j);
            if(!b.moreEmpty(i, j, val))
            {
                b.clearCell(i_prev, j_prev);
                solveBoard(b, i_prev, j_prev, ++val);
            }
            else
                solveBoard(b, i, j, ++val);
        }
        else 
        {
            b.setCell(i, j, valueToPlace);
            // cout << "I set the Cell - making recursive call " << recursiveCalls << endl;
            if (i == 9)
                solveBoard(b, 1, j + 1);
            else
                solveBoard(b, i + 1, j);
        }
    }
}

// void backTrack(Board b, int i, int j)
// {
//     ValueType val = b.getCell(i,j);
//     guesses.pop();
//     int i_prev = guesses.top()[0];
//     int j_prev = guesses.top()[1];
//     b.clearCell(i, j);
//     if(!b.moreEmpty(i, j, val))
//     {
//         b.clearCell(i_prev, j_prev);
//         solveBoard(b, i_prev, j_prev, val++);
//     }
//     solveBoard(b, i, j, val++);
// }

int main()
{
    ifstream fin;

    // Read the sample grid from the file.
    string fileName = "sudoku1.txt";

    fin.open(fileName.c_str());
    if (!fin)
    {
        cerr << "Cannot open " << fileName << endl;
        exit(1);
    }
    try
    {
        Board b1(SquareSize);
        while (fin && fin.peek() != 'Z')
        {
            b1.initialize(fin);
            b1.print();
            //b1.printConflicts();
            if (b1.isSolved())
                cout << "Board is solved!" << endl;
            else
            {
                cout << "I start to solve the board" << endl;
                solveBoard(b1);
                cout << "Number of recursive calls made: " << recursiveCalls << endl;
            }
        }
        int averageRecursions = totalRecursiveCalls / numberOfBoards;
        cout << "Average Recursive Calls: " << averageRecursions << endl;
    }
    catch (indexRangeError &ex)
    {
        cout << ex.what() << endl;
        exit(1);
    }
}