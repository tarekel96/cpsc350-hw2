#ifndef MIRROR_H
#define MIRROR_H
#include "Grid.h"
#include <string>

class Mirror: public Grid{
  public:
    Mirror();
    Mirror(string file);
    Mirror(int width, int height);
    Mirror(int width, int height, float populationDensity);
    Mirror(const Grid &currentGrid);
    ~Mirror();
    string printGrid() override;
  private:
};
#endif
