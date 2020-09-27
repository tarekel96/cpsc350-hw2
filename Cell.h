#include <iostream>
using namespace std;

class Cell{
  private:
    char value;
    bool occupied;
    int numberOfNeighbors;
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
    void setValue(char value);
};
