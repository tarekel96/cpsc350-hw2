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
    int m_transition;
    int m_generation;
  public:
    Cell **board;
    Cell **prevBoard;
    Grid();
    Grid(string file, int transition);
    Grid(int width, int height, int transition);
    Grid(int width, int height, float populationDensity, int transition);
    Grid(Grid &currentGrid);
    ~Grid();
    virtual string printGrid();
    virtual string printPrevGrid();
    void incrementGeneration();
    // accessors
    int getRows();
    int getColumns();
    int getTransition();
    int getGenerationNumber();
    char getElement(int row, int col);
    // mutatorss
    void setElement(int row, int col, char value);
    void setGeneration(int generation);
    void setPrevBoard(Grid &currentBoard);
    // helper functions
    virtual void next(Grid &currentGrid, bool print);
    virtual int calculateNumberOfNeighbors(int row, int col, Grid &currentGrid);
    bool compareGenerations();
};
#endif // GRID_H
