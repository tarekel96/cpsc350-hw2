// #ifndef HEADER_FILE
// #define HEADER_FILE
#include <iostream>
#include "Doughnut.h"
// #include "Mirror.h"
#include "Grid.h"
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
// #endif
