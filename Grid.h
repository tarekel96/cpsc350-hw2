#include <iostream>
#include "Cell.h"
using namespace std;

class Grid{
  private:
    int m_width;
    int m_height;
    Cell **array;
  public:
    Grid();
    Grid(int width, int height);
    ~Grid();
    string printGrid();
    // accessors
    int getRows();
    int getColumns();
    char getElement(int row, int col);
    // mutators
    void setElement(int row, int col, char value);
};
