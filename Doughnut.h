/**
  * a class that reprents a Grid/Board (2D array) that is composed of pointers to Cell instances
  * follows the Doughnut Mode rules
  * @author Tarek El-Hajjaoui
  * @version 1.0
*/
#ifndef DOUGHNUT_H
#define DOUGHNUT_H
#include <string>
#include "Grid.h"
using namespace std;
class Doughnut: public Grid{
  /* public fields */
  public:
    /* Default Constructor */
    Doughnut();
    /* Overloaded Constructors */
    Doughnut(string file, int transition); // accepts a file (that contains a given grid)
    Doughnut(int rows, int columns, int transition);
    Doughnut(int rows, int columns, float populationDensity, int transition);
    /* Copy Constructor */
    Doughnut(Grid &currentGrid);
    /* Destructor */
    ~Doughnut();
    /* HELPER FUNCTIONS */
    string printGrid() override; // returns a string version of the current grid (board)
    int calculateNumberOfNeighbors(int row, int col, Doughnut &currentGrid); // calculates the number of neighbors a cell has - Doughnut Mode
    void next(Doughnut &currentGrid, bool print); // creates the board for the next generation - based on the current board (board)
  private:
};
#endif
