#include <iostream>
#include <fstream>
#include "Cell.h"
using namespace std;

class Grid{
  private:
    int m_width;
    int m_height;
    Cell **array;
    Cell **prevArray;
    Cell **nextArray;
    int m_generation;
    int m_mode;
  public:
    Grid();
    Grid(string file, int mode);
    Grid(int width, int height, int mode);
    Grid(int width, int height, float populationDensity, int mode);
    ~Grid();
    string printGrid();
    void incrementGeneration();
    // accessors
    int getRows();
    int getColumns();
    char getElement(int row, int col);
    int getMode();
    int getGenerationNumber();
    // mutators
    void setElement(int row, int col, char value);
    void setMode(int mode);
    // helper functions
    int calculateNumberOfNeighbors(int row, int col);
    void simulate();
};
