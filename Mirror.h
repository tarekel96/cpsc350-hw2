#ifndef MIRROR_H
#define MIRROR_H
#include "Grid.h"
#include <string>

class Mirror: public Grid{
  public:
    Mirror();
    Mirror(string file, int transition);
    Mirror(int width, int height, int transition);
    Mirror(int width, int height, float populationDensity, int transition);
    Mirror(Grid &currentGrid);
    ~Mirror();
    string printGrid() override;
  private:
};
#endif
