// Group 11: Drew Balfour & Sean Vumbaco
// Project 4 (parts a and b)

// Main program file for Project 4 Part A
// Reads each Sudoku board from the file one-by-one, print the
// board and conflict vectors to the screen, and check to see if the board has been solved (all
// boards will not be solved just by this program).

#include <iostream>
#include <limits.h>
#include "d_matrix.h"
#include "d_except.h"
#include <string>
#include <list>
#include <fstream>

using namespace std;

// Declare constant and global variables
typedef int ValueType;
const int Blank = -1;

const int SquareSize = 3;
const int BoardSize = SquareSize * SquareSize;
const int MinValue = 1;
const int MaxValue = 9;
int numSolutions = 0;
const int NoConflict = 0;
const int YesConflict = 1;

// Declaration of public and private members of Board class
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
        void updateConflicts(int, int, int, int);
        bool isConflict(int, int, int);
    private:
        // The following matrices go from 1 to BoardSize in each
        // dimension, i.e., they are each (BoardSize+1) * (BoardSize+1)
        matrix<ValueType> value;
        matrix<vector<ValueType>> conflicts;
};

// Class constructor for Board objects
Board::Board(int sqSize)
    : value(BoardSize+1, BoardSize+1),
        conflicts(BoardSize+1, BoardSize+1, vector<ValueType> (BoardSize, NoConflict))
{
    clear();
}

void Board::clear()
// Clears all cells in the Board object
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
// Read a Sudoku board from the input file and establish cell values
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
    {
        value[i][j] = newValue;
        updateConflicts(i, j, newValue, YesConflict);
    }
    else
        throw rangeError("bad value in getCell");
    // Update conflicts vectors
}

void Board::clearCell(int i, int j)
// Returns nothing - just clears cell value. Throws an exception
// if bad values are passed.
{
    if (i >= 1 && i <= BoardSize && j >= 1 && j <= BoardSize)
    {
        int val = value[i][j];
        value[i][j] = Blank;
        // Update conflicts vectors
        updateConflicts(i, j, val, NoConflict);
    }
    else
        throw rangeError("bad value in getCell");
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

bool Board::isConflict(int i, int j, int k)
// Returns whether k is in the same row, column, or square as cell <i, j>
{
    for (int p = 1; p <= BoardSize; p++)
    {
        if ((value[i][p] == k || value[p][j] == k) && k != Blank)
            return true;
    }
    int hStart = SquareSize * ((j - 1) / SquareSize) + 1;
    int vStart = SquareSize * ((i - 1) / SquareSize) + 1;
    for (int y = 0; y < SquareSize; y++)
    {
        for (int z = 0; z < SquareSize; z++)
        {
            if (value[vStart + y][hStart + z] == k && k != Blank)
                return true;
        }
    }
    return false;
}

void Board::updateConflicts(int i, int j, int k, int s)
// Updates the conflict vector of every ce
// the coordinates of the vector (i and j), the value that goes into or comes
// out of the cell (k), and what the status of the cell is being changed to (s)
// s is either a 0 or 1 where 0 represents no conflict and 1 represents a 
// conflict
{
    // cout << "Updating conflict list of " << "<" << i << ", " << j << ">" << endl;
    int hStart = SquareSize * ((j - 1) / SquareSize) + 1;
    int vStart = SquareSize * ((i - 1) / SquareSize) + 1;
    for (int x = 1; x <= BoardSize; x++)
    {
        if (s == YesConflict)
        {
            conflicts[x][j][k - 1] = s;
            conflicts[i][x][k - 1] = s;
        }
        if (s == NoConflict)
        {
            if (!isConflict(x, j, k))
                conflicts[x][j][k - 1] = s;
            if (!isConflict(i, x, k))
                conflicts[i][x][k - 1] = s;
        }
    }
    for (int y = 0; y < SquareSize; y++)
    {
        // conflicts[vStart + y][j][k - 1] = s;
        for (int z = 0; z < SquareSize; z++)
        {
            if (s == YesConflict || (s == NoConflict && !isConflict(vStart + y, hStart + z, k)))
                conflicts[vStart + y][hStart + z][k - 1] = s;
        }
    }
}

bool Board::isSolved()
// Checks to see if the board has been solved and prints the board as well
// as the number of recursive and backtracking calls it took to solve
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
            
            // For debugging purposes
            // cout << "Writing a 5 at position <2, 1>" << endl;
            // b1.setCell(2, 1, 5);
            // b1.print();
            // b1.printConflicts();

            // cout << "Clearing cell at position <2, 1>" << endl;
            // b1.clearCell(2, 1);
            // b1.print();
            // b1.printConflicts();

            if (b1.isSolved())
                cout << "Board is solved!" << endl;
            else
                cout << "Board is not solved!" << endl;
        }
    }
    catch (indexRangeError &ex)
    {
        cout << ex.what() << endl;
        exit(1);
    }
}