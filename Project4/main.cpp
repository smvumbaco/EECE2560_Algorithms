// Group 11: Drew Balfour & Sean Vumbaco
// Project 4 (parts a and b)

// Main program file for Project 4, ...

#include <iostream>
#include <limits.h>
#include "Board.h"
#include "d_matrix.h"
#include "d_except.h"
#include <string>
#include <list>
#include <fstream>

using namespace std;

typedef int ValueType;
const int Blank = -1;

const int SquareSize = 3;
const int BoardSize = SquareSize * SquareSize;
const int MinValue = 1;
const int MaxValue = 9;
int numSolutions = 0;

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
    private:
        // The following matrices go from 1 to BoardSize in each
        // dimension, i.e., they are each (BoardSize+1) * (BoardSize+1)
        matrix<ValueType> value;
};

Board::Board(int sqSize)
    : value(BoardSize+1, BoardSize+1)
{
    clear();
}

void Board::clear()
{
    for (int i = 1; i <= BoardSize; i++)
        for (int j = 1; j <= BoardSize; j++)
            value[i][j] = Blank;
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
    if (i >= 1 && i <= BoardSize && j >= 1 && j <= BoardSize)
        value[i][j] = newValue;
    else
        throw rangeError("bad value in getCell");
    // Update conflicts vectors
}

void Board::clearCell(int i, int j)
// Returns nothing - just clears cell value. Throws an exception
// if bad values are passed.
{
    if (i >= 1 && i <= BoardSize && j >= 1 && j <= BoardSize)
        value[i][j] = Blank;
    else
        throw rangeError("bad value in getCell");
    // Update conflicts vectors
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
                cout << " ";
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

}

bool Board::isSolved()
// Checks to see if the board has been solved
{
    for (int i = 0; i < BoardSize; i++)
        for (int j = 0; j < BoardSize; j++)
        {
            if (value[i][j] == Blank)
                return false;
        }
    return true;
}

int main()
{
    ifstream fin;

    // Read the sample grid from the file.
    string fileName = "sudoku.txt";

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
            b1.printConflicts();
        }
    }
    catch (indexRangeError &ex)
    {
        cout << ex.what() << endl;
        exit(1);
    }
}