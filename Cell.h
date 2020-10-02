#ifndef CELL_H
#define CELL_H
#include <iostream>
using namespace std;

class Cell{
  private:
    char m_value;
    bool m_occupied;
    int m_numberOfNeighbors;
  public:
    // default Constructor
    Cell();
    Cell(bool occupied, int numberOfNeighbors);
    // accessors
    bool getOccupied();
    int getNumberOfNeighbors();
    char getValue();
    // mutators
    void setOccupied(bool occupied);
    void setNumberOfNeighbors(int numberOfNeighbors);
    void setValue(char val);
};
#endif
