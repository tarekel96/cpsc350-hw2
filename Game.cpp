#include "Game.h"
#include "Mirror.h"
#include "Doughnut.h"
#include "FileError.h"
#include <unistd.h>
Game::Game(){
  int response = getResponse();
  if(response == 1){
    int rows = getRow();
    int columns = getCol();
    float populationDensity = getPopulationDensity();
    int mode = getMode();
    if(mode == 1){
      m_grid = new Grid(rows, columns, populationDensity);
      cout << m_grid->printGrid() << endl;
    }
    else if(mode == 2){
      m_grid = new Doughnut(rows, columns, populationDensity);
      cout << m_grid->printGrid() << endl;
    }
    else if(mode == 3){
      m_grid = new Mirror(rows, columns, populationDensity);
      cout << m_grid->printGrid() << endl;
    }
  }
  else if(response == 2){
      string file;
      int mode;
      while(true){
        file = getFileName();
        FileError* FE = new FileError(file);
        if(FE->pass())
          break;
        else
          continue;
        delete FE;
      }
      mode = getMode();
      if(mode == 1){
        m_grid = new Grid(file);
        cout << m_grid->printGrid() << endl;
      }
      else if(mode == 2){
        m_grid = new Doughnut(file);
        cout << m_grid->printGrid() << endl;
      }
      else if(mode == 3){
        m_grid = new Mirror(file);
        cout << m_grid->printGrid() << endl;
      }
  }
  else {
    cerr << "Invalid input" << endl;
  }
}
Game::~Game(){
  delete m_grid;
}
int Game::getResponse(){
  int response;
  bool correctInput = false;
  while (!correctInput){
    cout << "Enter 1 if you like to randomly assign cell values or 2 if you would like to use a map" << endl;
    cin >> response;
    if(response == 1 || response == 2){
      correctInput = true;
    }
    else {
      correctInput = false;
    }
  }
  return response;
}
int Game::getRow(){
  int rows;
  bool correctInput = false;
  while (!correctInput){
    cout << "Enter the number of rows your grid will have: " << endl;
    cin >> rows;
    if(rows >= 1){
      correctInput = true;
    }
    else {
      correctInput = false;
    }
  }
  return rows;
}
int Game::getCol(){
  int columns;
  bool correctInput = false;
  while (!correctInput){
    cout << "Enter the number of columns your grid will have: " << endl;
    cin >> columns;
    if(columns >= 1){
      correctInput = true;
    }
    else {
      correctInput = false;
    }
  }
  return columns;
}
float Game::getPopulationDensity(){
  float populationDensity;
  bool correctInput = false;
  while (!correctInput){
    cout << "Enter a decimal value (greater than 0 and less than or equal to 1) - represents the initial population density of the world: " << endl;
    cin >> populationDensity;
    if((populationDensity >= 0.0) && (populationDensity <= 1.0)){
      correctInput = true;
    }
    else {
      correctInput = false;
    }
  }
  return populationDensity;
}
int Game::getGenerationTransition(){
  int pause;
  bool correctInput = false;
  while(!correctInput){
    cout << "Enter 1 to include a brief pause, 2 to press Enter in between generations, or 3 to display results in a file: " << endl;
    cin >> pause;
    if(pause == 1 || pause == 2 || pause == 3)
      correctInput = true;
    else
      cerr << "ERROR: Invalid Input" << endl;
      continue;
  }
  return pause;
}
string Game::getFileName(){
  string file;
  cout << "Enter the name of the map file?" << endl;
  cin >> file;
  return file;
}
int Game::getMode(){
  int mode;
  bool correctInput = false;
  while(!correctInput){
    cout << "Enter 1 for Classic Mode, 2 for Doughnut Mode, and 3 for Mirror Mode" << endl;
    cin >> mode;
    if(mode == 1 || mode == 2 || mode == 3)
      correctInput = true;
    else
      cerr << "ERROR: Invalid Input" << endl;
      continue;
  }
  return mode;
}
