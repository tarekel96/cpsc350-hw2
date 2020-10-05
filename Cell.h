/**
  * a class that reprents a cell in 2D array/grid
  * @author Tarek El-Hajjaoui
  * @version 1.0
*/
#ifndef CELL_H
#define CELL_H
#include <iostream>
using namespace std;
class Cell{
  /* private fields */
  private:
    char m_value; // the char value of the cell
    bool m_occupied; // true = occupied and false = vacant
  /* public fields */
  public:
    /* Default Constructor */
    Cell();
    /* Overloaded Constructor */
    Cell(bool occupied);
    /* Destructor */
    ~Cell();
    /* ACCESSORS */
    bool getOccupied();
    char getValue();
    /* MUTATORS */
    void setOccupied(bool occupied);
    void setValue(char val);
};
#endif
