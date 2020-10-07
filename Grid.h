/**
  * a class that reprents a Grid/Board (2D array) that is composed of pointers to Cell instances
  * follows the Classical Mode Rules
  * @author Tarek El-Hajjaoui
  * @version 1.0
*/
#ifndef GRID_H
#define GRID_H
#include <iostream>
#include <fstream>
#include "Cell.h"
#include <unistd.h>
using namespace std;
class Grid{
  /* private fields */
  private:
    int m_rows; // the number of rows board will have
    int m_columns; // the number of cols board will have
    int m_transition; // the user's preference for handling transitions between generations
    int m_generation; // the current generation of the Grid of Cells
  /* public fields */
  public:
    Cell **board; // 2D array of pointers to instances of Cells
    Cell **prevBoard; // the 2D array of pointers to instances of Cells from the previous generation
    /* Default Constructor */
    Grid();
    /* Overloaded Constructors */
    Grid(string file, int transition); // accepts a file (that contains a given grid)
    Grid(int rows, int columns, int transition);
    Grid(int rows, int columns, float populationDensity, int transition);
    /* Copy Constructor */
    Grid(Grid &currentGrid);
    /* Destructor */
    ~Grid();
    /* ACCESSORS */
    int getRows();
    int getColumns();
    int getTransition();
    int getGenerationNumber();
    char getElement(int row, int col);
    /* MUTATORS */
    void setElement(int row, int col, char value);
    void setGeneration(int generation);
    void setPrevBoard(Grid &currentBoard);
    /* HELPER FUNCTIONS */
    virtual string printGrid(); // returns a string version of the current grid (board)
    virtual string printInitGrid(); // returns the initial grid
    virtual string printPrevGrid(); // returns a string version of the previous generation grid (prevBoard)
    virtual void next(Grid &currentGrid, bool print); // creates the board for the next generation - based on the current board (board)
    virtual int calculateNumberOfNeighbors(int row, int col, Grid &currentGrid); // calculates the number of neighbors a cell has - Classical Mode
    void incrementGeneration(); // increments m_generation
    bool compareGenerations(); // compares board to prevBoard
    bool isEmpty(); // checks if every cell in the grid is dead
};
#endif // GRID_H
