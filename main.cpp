#include "Game.h"

void promptQuit(){
  int response;
  while(true){
    cout << "ENTER 1 TO QUIT THE PROGRAM" << endl;
    cin >> response;
    if(cin.fail()){
      cerr << "ERROR: INVALID INPUT - PLEASE FOLLOW DIRECTIONS" << endl;
      cin.clear();
      cin.ignore(10000,'\n');
      continue;
    }
    else{
      if(response == 1)
        break;
      else{
        cerr << "ERROR: INVALID INPUT - PLEASE FOLLOW DIRECTIONS" << endl;
        continue;
      }
    }
  }
}

int main(int argv, char ** argc){
  Game* game = new Game();
  promptQuit();
  delete game;
  return 0;
}
