// // Group 11: Drew Balfour and Sean Vumbaco
// // Project 4 (parts a and b)

// // Contains class Board implementations for Sudoku

// #include <iostream>
// #include <limits.h>
// #include "Board.h"
// #include "d_matrix.h"
// #include "d_except.h"
// #include <list>
// #include <fstream>
// using namespace std;

// typedef int ValueType; // The type of the value in a cell
// const int Blank = -1; // Indicates that a cell is blank

// // const int SquareSize = 3; // The number of cells in a small square
//                             // (usually 3). The board has
//                             // SquareSize^2 rows and SquareSize^2
//                             // columns.
// //const int BoardSize = SquareSize * SquareSize;

// const int MinValue = 1;
// const int MaxValue = 9;

// Board::Board(int sqSize)
//     : value(BoardSize+1,BoardSize+1)
// // Board constructor
//     {
//         clear();
//     }

// void Board::clear()
// // Mark all possible values as legal for each board entry
// {
//     for (int i = 1; i <= BoardSize; i++)
//         for (int j = 1; j <= BoardSize; j++)
//             {
//                 value[i][j] = Blank;
//             }
// }

// void Board::initialize(ifstream &fin)
// // Read a Sudoku board from the input file.
// {
//     char ch;
//     clear();
//     for (int i = 1; i <= BoardSize; i++)
//         for (int j = 1; j <= BoardSize; j++)
//         {
//             fin >> ch;
            
//             // If the read char is not Blank
//             if (ch != '.')
//                 setCell(i,j,ch-'0'); // Convert char to int
//         }
// }

// ValueType Board::getCell(int i, int j)
// // Returns the value stored in a cell. Throws an exception
// // if bad values are passed.
// {
//     if (i >= 1 && i <= BoardSize && j >= 1 && j <= BoardSize)
//         return value[i][j];
//     else
//         throw rangeError("bad value in getCell");
// }

// void Board::setCell(int i, int j, int newValue)
// // Returns nothing - just updates cell value. Throws an exception
// // if bad values are passed.
// {
//     if (i >= 1 && i <= BoardSize && j >= 1 && j <= BoardSize)
//         value[i][j] = newValue;
//     else
//         throw rangeError("bad value in getCell");
//     // Update conflicts vectors
// }

// void Board::clearCell(int i, int j)
// // Returns nothing - just clears cell value. Throws an exception
// // if bad values are passed.
// {
//     if (i >= 1 && i <= BoardSize && j >= 1 && j <= BoardSize)
//         value[i][j] = Blank;
//     else
//         throw rangeError("bad value in getCell");
//     // Update conflicts vectors
// }

// bool Board::isBlank(int i, int j)
// // Returns true if cell i,j is blank, and false otherwise.
// {
//     if (i < 1 || i > BoardSize || j < 1 || j > BoardSize)
//         throw rangeError("bad value in setCell");

//     return (getCell(i,j) == Blank);
// }

// void Board::print()
// // Prints the current board.
// {
//     for (int i = 1; i <= BoardSize; i++)
//     {
//         if ((i-1) % SquareSize == 0)
//         {
//             cout << " -";
//             for (int j = 1; j <= BoardSize; j++)
//                 cout << "---";
//             cout << "-";
//             cout << endl;
//         }
//         for (int j = 1; j <= BoardSize; j++)
//         {
//             if ((j-1) % SquareSize == 0)
//                 cout << "|";
//             if (!isBlank(i,j))
//                 cout << " " << getCell(i,j) << " ";
//             else
//                 cout << " ";
//         }
//         cout << "|";
//         cout << endl;
//     }
//     cout << " -";
//     for (int j = 1; j <= BoardSize; j++)
//         cout << "---";
//     cout << "-";
//     cout << endl;
// }

// void Board::printConflicts()
// // Prints conflict vectors
// {

// }

// bool Board::isSolved()
// // Checks to see if the board has been solved
// {
//     for (int i = 0; i < BoardSize; i++)
//         for (int j = 0; j < BoardSize; j++)
//         {
//             if (value[i][j] == Blank)
//                 return false;
//         }
//     return true;
// }