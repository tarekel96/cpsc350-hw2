#ifndef GRID_H
#define GRID_H
#include <iostream>
#include <fstream>
#include "Cell.h"
#include <unistd.h>
using namespace std;

class Grid{
  private:
    int m_width;
    int m_height;
    Cell **prevArray;
    Cell **nextArray;
    int m_generation;
    int m_mode;
  public:
    Grid();
    Grid(string file);
    Grid(int width, int height);
    Grid(int width, int height, float populationDensity);
    Grid(const Grid &currentGrid);
    ~Grid();
    Cell **array;
    virtual string printGrid();
    void incrementGeneration();
    // accessors
    int getRows();
    int getColumns();
    char getElement(int row, int col);
    int getGenerationNumber();
    // mutators
    void setElement(int row, int col, char value);
    void setGeneration(int generation);
    // helper functions
    void next(Grid const& currentGrid);
    int calculateNumberOfNeighbors(int row, int col, Grid const &currentGrid);
};
#endif // GRID_H
