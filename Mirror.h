/**
  * a class that reprents a Grid/Board (2D array) that is composed of pointers to Cell instances
  * follows the Mirror Mode rules
  * @author Tarek El-Hajjaoui
  * @version 1.0
*/
#ifndef MIRROR_H
#define MIRROR_H
#include "Grid.h"
#include <string>
class Mirror: public Grid{
  /* public fields */
  public:
    /* Default Constructor */
    Mirror();
    /* Overloaded Constructors */
    Mirror(string file, int transition); // accepts a file (that contains a given grid)
    Mirror(int rows, int columns, int transition);
    Mirror(int rows, int columns, float populationDensity, int transition);
    /* Copy Constructor */
    Mirror(Grid &currentGrid);
    /* Destructor */
    ~Mirror();
    /* HELPER FUNCTIONS */
    string printGrid() override;
    int calcNeighbors(int row, int col, Mirror &currentGrid);
    void next(Mirror &currentGrid, bool print);
  private:
};
#endif
