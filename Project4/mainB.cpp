// Group 11: Drew Balfour & Sean Vumbaco
// Project 4 (parts a and b)

// Main program file for Project 4 Part B
// Reads each board from the sudoku.txt text file, recursively solves it, prints the solution, and
// prints the number of recursive iterations needed to solve that board. After all boards have
// been solved, prints the average number of recursive calls needed to solve all the boards.
// Prints the total number of your recursive calls.

#include <iostream>
#include <limits.h>
#include "d_matrix.h"
#include "d_except.h"
#include <cstdlib>
#include <string>
#include <list>
#include <fstream>
#include <stack>
#include <string>
#include <sstream>

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

const int numberOfBoards = 96;
int recursiveCalls = 0;
int backtrackCalls = 0;
int totalRecursiveCalls = 0;
int totalBacktrackCalls = 0;

// Declaration of public and private members of Board class
class Board
{
    public:
        Board(int);
        struct cell;
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
        cell getWorstCell();
        int getNumConflicts(int, int);
        bool isConflict(int, int, int);
        bool solveBoard();
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

// Struct to store cell row and column
struct Board::cell{
	// i = row# & j = column#
	int i, j;
};

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
        if (conflicts[i][j][newValue-1] == 1)
            cout << "Placed a value where there is a conflict!!!!!!!!" << endl;
        updateConflicts(i, j, newValue, YesConflict);
    }
    else
        throw rangeError("bad value in getCell");
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

Board::cell Board::getWorstCell()
// Returns the cell that has the most conflicts
{
    cell c;
    int constraint = 0;
	int temp;
	// scanning cells for min constraints
	for (int i = 1; i <= BoardSize; i++){
		for (int j = 1; j <= BoardSize; j++){
			if (value[i][j] == Blank){
				temp = getNumConflicts(i, j);
				if (temp > constraint){
					c.i = i;
					c.j = j;
					constraint = temp;
				}
			}
		}
	}
	if (constraint > 0){
		return c;
	}
    // if there are no more cells, set the cell dimensions to <-1, -1>
	c.i = -1;
	c.j = -1;
	return c;
} // end getWorstCell

bool Board::isConflict(int i, int j, int k)
// Returns whether k is in the same row, column, or square as cell <i, j>
{
    for (int p = 1; p <= BoardSize; p++)
    {
        if ((value[i][p] == k || value[p][j] == k) && k != Blank)
            return true;
    }
    // find the top right cell of the square the given cell resides in
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
} // end isConflict

void Board::updateConflicts(int i, int j, int k, int s)
// Updates the conflict vector of every ce
// the coordinates of the vector (i and j), the value that goes into or comes
// out of the cell (k), and what the status of the cell is being changed to (s)
// s is either a 0 or 1 where 0 represents no conflict and 1 represents a 
// conflict
{
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
        for (int z = 0; z < SquareSize; z++)
        {
            if (s == YesConflict || (s == NoConflict && !isConflict(vStart + y, hStart + z, k)))
                conflicts[vStart + y][hStart + z][k - 1] = s;
        }
    }
} // end updateConflicts

bool Board::isSolved()
// Checks to see if the board has been solved and prints the board as well
// as the number of recursive and backtracking calls it took to solve
{
    for (int i = 1; i <= BoardSize; i++)
        for (int j = 1; j <= BoardSize; j++)
        // checks to see if any cell in the board is blank
        {
            if (value[i][j] == Blank)
                return false;
        }
    print();
    cout << "Number of recursive calls made: " << recursiveCalls << endl;
    cout << "Number of Backtracking Calls: " << backtrackCalls << endl;
    totalRecursiveCalls += recursiveCalls;
    totalBacktrackCalls += backtrackCalls;
    recursiveCalls = 0;
    backtrackCalls = 0;
    return true;
}

int Board::getNumConflicts(int i, int j)
// Returns the number of conflicts a single cell has
{
    int total = 0;
    for (int k = 0; k < BoardSize; k++)
    {
        total += conflicts[i][j][k];
    }
    return total;
}

bool Board::solveBoard()
// Recursive function to solve the sudoku puzzle 
{
    bool status;
	cell c = getWorstCell();
    if (c.i == -1)
    // test if there are no more cells to fill
    {
        status = true;
    }
    else
    {
        status = false;
		for (int num = 1; num <= 9; num++){
			if (!isConflict(c.i, c.j, num)){
				// found a good solution
                setCell(c.i, c.j, num);
                // adding recursion counts
				recursiveCalls++; 
				if (!solveBoard())
                {
					// recursive step will backtrack if return false
                    clearCell(c.i, c.j);
                    // adding backtrack counts
					backtrackCalls++; 
				} 
                else
                    status = true;
			}
		}
	}
    return status;
} // end solveBoard

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
        // go through all sudoku boards
        {
            b1.initialize(fin);
            b1.print();
            if (b1.isSolved())
                cout << "Board is solved!" << endl;
            else
            // if board is not solved, solve board
            {
                cout << "I start to solve the board" << endl;
                if (b1.solveBoard() && b1.isSolved())
                    cout << "Board is solved!" << endl;
                else 
                    cout << "Cannot solve board." << endl;
            }
        }
        // after printing all boards, return total and average number of 
        // recursive and backtracking calls
        int averageRecursions = totalRecursiveCalls / numberOfBoards;
        int averageBacktrack = totalBacktrackCalls / numberOfBoards;
        cout << "Total Recursive Calls: " << totalRecursiveCalls << endl;
        cout << "Average Recursive Calls: " << averageRecursions << endl;
        cout << "Total Backtracking Calls: " << totalBacktrackCalls << endl;
        cout << "Average Backtracking Calls: " << averageBacktrack << endl;
    }
    catch (indexRangeError &ex)
    {
        cout << ex.what() << endl;
        exit(1);
    }
} // end main