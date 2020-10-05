#include "Game.h"
int main(int argv, char ** argc){
  while(true){
    Game* game = new Game();
    cout << "The world has stabilized, press enter to exit the program" << endl;
    game->promptEnter();
    delete game;
    break;
  }
  return 0;
}
