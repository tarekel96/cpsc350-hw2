#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "Grid.h"
#include "Doughnut.h"
#include "Mirror.h"
#include "FileError.h"
#include <unistd.h>
using namespace std;

class Game {
  private:
    Grid* m_grid;
    bool m_pause;
    string m_outFile;
  public:
    // default Constructor
    Game();
    // destructor
    ~Game();
    // prompt user for input
    int getResponse();
    int getRow();
    int getCol();
    float getPopulationDensity();
    int getGenerationTransition();
    string getFileName();
    int getMode();
};
#endif
