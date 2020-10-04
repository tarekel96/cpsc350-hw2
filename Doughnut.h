#ifndef DOUGHNUT_H
#define DOUGHNUT_H
#include <string>
#include "Grid.h"
using namespace std;

class Doughnut: public Grid{
  public:
    Doughnut();
    Doughnut(string file, int transition);
    Doughnut(int width, int height, int transition);
    Doughnut(int width, int height, float populationDensity, int transition);
    Doughnut(Grid &currentGrid);
    ~Doughnut();
    string printGrid() override;
    int calculateNumberOfNeighbors(int row, int col, Doughnut &currentGrid);
  private:
};
#endif
