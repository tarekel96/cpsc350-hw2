/**
  * a class that reprents the Game Of Life game
  * @author Tarek El-Hajjaoui
  * @version 1.0
*/
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
  /* private fields */
  private:
    Grid* m_grid; // the Grid/board of Cells for the game
    Doughnut* m_gridDoughnut; // the Doughnut grid/board of Cells for the game
    Mirror* m_gridMirror; // the Mirror Grid/board of Cells for the game
    bool m_pause; //
    string m_outFile; // the name file where results of the game can be outputted
  /* public fields */
  public:
    /* Default Constructor */
    Game();
    /* Destructor */
    ~Game();
    /* HELPER FUNCTIONS - PROMPTS USER FOR INPUTS */
    int getResponse();
    int getRow();
    int getCol();
    float getPopulationDensity();
    int getGenerationTransition();
    string getFileName();
    int getMode();
    void promptEnter();
    void promptQuit();
};
#endif
