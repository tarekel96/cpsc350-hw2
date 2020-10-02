#ifndef DOUGHNUT_H
#define DOUGHNUT_H
#include <string>
#include "Grid.h"
using namespace std;

class Doughnut: public Grid{
  public:
    Doughnut();
    Doughnut(string file);
    Doughnut(int width, int height);
    Doughnut(int width, int height, float populationDensity);
    Doughnut(const Grid &currentGrid);
    ~Doughnut();
    string printGrid() override;
  private:
};
#endif
