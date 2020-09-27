#include <iostream>
#include "Cell.h"
using namespace std;

class Grid{
  private:
    int width;
    int height;
    Cell **array;
  public:
    Grid();
    Grid(int width, int height);
    ~Grid();
    string printGrid();
};
