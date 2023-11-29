// // Group 11: Drew Balfour and Sean Vumbaco
// // Project 4 (parts a and b)

// // Contains class Board declaration for Sudoku

// #ifndef BOARD_H
// #define BOARD_H

// #include <iostream>
// #include <limits.h>
// #include "d_matrix.h"
// #include "d_except.h"
// #include <list>
// #include <fstream>

// typedef int ValueType; // The type of the value in a cell
// // const int Blank = -1; // Indicates that a cell is blank

// // const int SquareSize = 3; // The number of cells in a small square
//                             // (usually 3). The board has
//                             // SquareSize^2 rows and SquareSize^2
//                             // columns.
// // const int BoardSize = SquareSize * SquareSize;

// const int MinValue = 1;
// const int MaxValue = 9;

// class Board
// // Stores the entire Sudoku board
// {
//     public:
//         Board(int);
//         void clear();
//         void initialize(ifstream &fin);
//         void print();
//         bool isBlank(int, int);
//         ValueType getCell(int, int); 
//         void setCell(int, int, int);
//         void clearCell(int, int);
//         void printConflicts();
//         bool isSolved();
//     private:
//         // The following matrices go from 1 to BoardSize in each
//         // dimension, i.e., they are each (BoardSize+1) * (BoardSize+1)
//         matrix<ValueType> value;
// };

// #endif