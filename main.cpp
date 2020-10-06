#include "Game.h"
#include "Grid.h"
int main(int argv, char ** argc){
  // Grid* g = new Grid("assign2-testFile2.txt", 3);
  // cout << g->printGrid() << endl;
  // Grid* tempGrid = new Grid(*g);
  // g->next(*tempGrid, false);
  // cout << g->printGrid() << endl;
  // Grid* tempGrid2 = new Grid(*g);
  // g->next(*tempGrid2, false);
  // cout << g->printGrid() << endl;
  while(true){
    Game* game = new Game();
    cout << "The world has stabilized, press enter to exit the program" << endl;
    game->promptEnter();
    delete game;
    break;
  }
  return 0;
}
