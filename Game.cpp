#include "Game.h"
Game::Game(){
  int response = getResponse();
  if(response == 1){
    int rows = getRow();
    int columns = getCol();
    float populationDensity = getPopulationDensity();
    int mode = getMode();
    if(mode == 1){
      int transition = getGenerationTransition();
      m_grid = new Grid(rows, columns, populationDensity, transition);
      cout << m_grid->printGrid() << endl;
      // Grid nextG = new Grid(*m_grid);
      // cout << m_grid->printGrid() << endl;
    }
    else if(mode == 2){
      int transition = getGenerationTransition();
      m_grid = new Doughnut(rows, columns, populationDensity, transition);
      cout << m_grid->printGrid() << endl;
    }
    else if(mode == 3){
      int transition = getGenerationTransition();
      m_grid = new Mirror(rows, columns, populationDensity, transition);
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
        int transition = getGenerationTransition();
        string userFile;
        ofstream outFile;
        if(transition == 3){
          cout << "Enter the name of the file where the results should be outputted: " << endl;
          cin >> userFile;
        }
        m_grid = new Grid(file, transition);
        cout << "INITIAL GRID: \n";
        cout << m_grid->printGrid() << endl;
        if(transition == 3){
          outFile.open(userFile);
          outFile << m_grid->printGrid();
          outFile.close();
        }
        Grid* tempGrid = new Grid(*m_grid);
        m_grid->next(*tempGrid);
        if(transition == 3){
          outFile.open(userFile, ios::out | ios::app);
          outFile << m_grid->printGrid();
          outFile.close();
        }
        while(m_grid->compareGenerations() == false){
          Grid* tempG = new Grid(*m_grid);
          if(m_grid->getTransition() == 1){
            sleep(1);
            m_grid->next(*tempG);
          }
          else if(m_grid->getTransition() == 2){
            cout << "Press Enter To Continue: " << endl;
            cin.get();
            m_grid->next(*tempG);
          }
          else if(m_grid->getTransition() == 3){
            m_grid->next(*tempG);
            outFile.open(userFile, ios::out | ios::app);
            outFile << m_grid->printGrid() << endl;
            outFile.close();
          }
          else {

          }
        }
      }
      else if(mode == 2){
        int transition = getGenerationTransition();
        m_grid = new Doughnut(file, transition);
        cout << m_grid->printGrid() << endl;
      }
      else if(mode == 3){
        int transition = getGenerationTransition();
        m_grid = new Mirror(file, transition);
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
  while(true){
    cout << "Enter 1 if you like to randomly assign cell values or 2 if you would like to use a map" << endl;
    cin >> response;
    if(response != 1 && response != 2)
      continue;
    else
      break;
  }
  return response;
}
int Game::getRow(){
  int rows;
  while(true){
    cout << "Enter the number of rows your grid will have: " << endl;
    cin >> rows;
    if(rows >= 1)
      break;
    else
      continue;
  }
  return rows;
}
int Game::getCol(){
  int columns;
  bool correctInput = false;
  while(true){
    cout << "Enter the number of columns your grid will have: " << endl;
    cin >> columns;
    if(columns >= 1)
      break;
    else
      continue;
  }
  return columns;
}
float Game::getPopulationDensity(){
  float populationDensity;
  while (true){
    cout << "Enter a decimal value (greater than 0 and less than or equal to 1) - represents the initial population density of the world: " << endl;
    cin >> populationDensity;
    if((populationDensity >= 0.0) && (populationDensity <= 1.0))
      break;
    else
      continue;
  }
  return populationDensity;
}
int Game::getGenerationTransition(){
  int pause;
  while(true){
    cout << "Enter 1 to include a brief pause, 2 to press Enter in between generations, or 3 to display results in a file: " << endl;
    cin >> pause;
    if(pause == 1 || pause == 2 || pause == 3)
      break;
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
  while(true){
    cout << "Enter 1 for Classic Mode, 2 for Doughnut Mode, and 3 for Mirror Mode" << endl;
    cin >> mode;
    if(mode == 1 || mode == 2 || mode == 3)
      break;
    else
      cerr << "ERROR: Invalid Input" << endl;
      continue;
  }
  return mode;
}
