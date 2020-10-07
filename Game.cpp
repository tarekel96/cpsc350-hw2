#include "Game.h"
/* Default Constructor */
Game::Game(){
  int response = getResponse();
  /* RANDOM ASSIGN CELL VALUES TO BOARD */
  if(response == 1){
    int rows = getRow();
    int columns = getCol();
    float populationDensity = getPopulationDensity();
    int mode = getMode();
    /* CLASSICAL MODE - RANDOM BOARD */
    if(mode == 1){
      int transition = getGenerationTransition();
      string userFile;
      ofstream outFile;
      if(transition == 3){
        cout << "Enter the name of the file where the results should be outputted: " << endl;
        cin >> userFile;
      }
      m_grid = new Grid(rows, columns, populationDensity, transition);
      if(transition == 3){
        outFile.open(userFile);
        outFile << m_grid->printInitGrid();
        outFile << m_grid->printGrid();
        outFile.close();
      }
      Grid* tempGrid = new Grid(*m_grid);
      if(transition == 3)
        m_grid->next(*tempGrid, false);
      else
        m_grid->next(*tempGrid, true);
      if(transition == 3){
        outFile.open(userFile, ios::out | ios::app);
        outFile << m_grid->printGrid();
        outFile.close();
      }
      while(m_grid->compareGenerations() == false && m_grid->isEmpty() == false){
        string input;
        Grid* tempG = new Grid(*m_grid);
        /* CLASSICAL - RANDOM BOARD - BRIEF PAUSES */
        if(m_grid->getTransition() == 1){
          sleep(1);
          m_grid->next(*tempG, true);
        }
        /* CLASSICAL - RANDOM BOARD - PRESS ENTER */
        else if(m_grid->getTransition() == 2){
          bool input = false;
          promptEnter();
          m_grid->next(*tempG, true);
        }
        /* CLASSICAL - RANDOM BOARD - WRITE TO ANOTHER FILE */
        else if(m_grid->getTransition() == 3){
          m_grid->next(*tempG, false);
          outFile.open(userFile, ios::out | ios::app);
          if(!m_grid->isEmpty()){
            outFile << m_grid->printGrid();
          }
          outFile.close();
        }
        else {

        }
      }
    }
    /* DOUGHNUT MODE - RANDOM BOARD */
    else if(mode == 2){
      int transition = getGenerationTransition();
      string userFile;
      ofstream outFile;
      if(transition == 3){
        cout << "Enter the name of the file where the results should be outputted: " << endl;
        cin >> userFile;
      }
      m_gridDoughnut = new Doughnut(rows, columns, populationDensity, transition);
      if(transition == 1 || transition == 2){
        cout << "INITIAL GRID: \n";
        cout << m_gridDoughnut->printGrid();
      }
      if(transition == 3){
        outFile.open(userFile);
        outFile << m_gridDoughnut->printInitGrid();
        outFile << m_gridDoughnut->printGrid();
        outFile.close();
      }
      Doughnut* tempGridDoughnut = new Doughnut(*m_gridDoughnut);
      if(transition == 3){
        m_gridDoughnut->next(*tempGridDoughnut, false);
        outFile.open(userFile, ios::out | ios::app);
        outFile << m_gridDoughnut->printGrid();
        outFile.close();
      }
      else{
        m_gridDoughnut->next(*tempGridDoughnut, true);
      }
      while(m_gridDoughnut->compareGenerations() == false && m_gridDoughnut->isEmpty() == false){
        Doughnut* tempG = new Doughnut(*m_gridDoughnut);
        /* DOUGHNUT - RANDOM BOARD - BRIEF PAUSES */
        if(m_gridDoughnut->getTransition() == 1){
          sleep(1);
          m_gridDoughnut->next(*tempG, true);
        }
        /* DOUGHNUT - RANDOM BOARD - PRESS ENTER */
        else if(m_gridDoughnut->getTransition() == 2){
          promptEnter();
          m_gridDoughnut->next(*tempG, true);
        }
        /* DOUGHNUT - RANDOM BOARD - WRITE TO ANOTHER FILE */
        else if(m_gridDoughnut->getTransition() == 3){
          m_gridDoughnut->next(*tempG, false);
          outFile.open(userFile, ios::out | ios::app);
          if(!m_gridDoughnut->isEmpty()){
            outFile << m_gridDoughnut->printGrid();
          }
          outFile.close();
        }
        else {

        }
      }
    }
    /* MIRROR MODE - RANDOM BOARD */
    else if(mode == 3){
      int transition = getGenerationTransition();
      string userFile;
      ofstream outFile;
      if(transition == 3){
        cout << "Enter the name of the file where the results should be outputted: " << endl;
        cin >> userFile;
      }
      m_gridMirror = new Mirror(rows, columns, populationDensity, transition);
      if(transition == 1 || transition == 2){
        cout << "INITIAL GRID: \n";
        cout << m_gridMirror->printGrid();
      }
      if(transition == 3){
        outFile.open(userFile);
        outFile << m_gridMirror->printInitGrid();
        outFile << m_gridMirror->printGrid();
        outFile.close();
      }
      Mirror* tempGridMirror = new Mirror(*m_gridMirror);
      if(transition == 3){
        m_gridMirror->next(*tempGridMirror, false);
        outFile.open(userFile, ios::out | ios::app);
        outFile << m_gridMirror->printGrid();
        outFile.close();
      }
      else{
        m_gridMirror->next(*tempGridMirror, true);
      }
      while(m_gridMirror->compareGenerations() == false && m_gridMirror->isEmpty() == false){
        Mirror* tempG = new Mirror(*m_gridMirror);
        /* MIRROR - RANDOM BOARD - BRIEF PAUSES */
        if(m_gridMirror->getTransition() == 1){
          sleep(1);
          m_gridMirror->next(*tempG, true);
        }
        /* MIRROR - RANDOM BOARD - PRESS ENTER */
        else if(m_gridMirror->getTransition() == 2){
          promptEnter();
          m_gridMirror->next(*tempG, true);
        }
        /* MIRROR - RANDOM BOARD - WRITE TO ANOTHER FILE */
        else if(m_gridMirror->getTransition() == 3){
          m_gridMirror->next(*tempG, false);
          outFile.open(userFile, ios::out | ios::app);
          if(!m_gridMirror->isEmpty()){
            outFile << m_gridMirror->printGrid();
          }
          outFile.close();
        }
        else {

        }
      }
    }
  }
  /* POPULATE BOARD FROM GIVEN FILE */
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
      /* CLASSICAL MODE - GIVEN BOARD */
      if(mode == 1){
        int transition = getGenerationTransition();
        string userFile;
        ofstream outFile;
        if(transition == 3){
          cout << "Enter the name of the file where the results should be outputted: " << endl;
          cin >> userFile;
        }
        m_grid = new Grid(file, transition);
        if(transition == 1 || transition == 2){
          cout << m_grid->printGrid();
        }
        if(transition == 3){
          outFile.open(userFile);
          outFile << m_grid->printInitGrid();
          outFile << m_grid->printGrid();
          outFile.close();
        }
        Grid* tempGrid = new Grid(*m_grid);
        if(transition == 3)
          m_grid->next(*tempGrid, false);
        else
          m_grid->next(*tempGrid, true);
        if(transition == 3){
          outFile.open(userFile, ios::out | ios::app);
          outFile << m_grid->printGrid();
          outFile.close();
        }
        while(m_grid->compareGenerations() == false && m_grid->isEmpty() == false){
          Grid* tempG = new Grid(*m_grid);
          /* CLASSICAL - GIVEN BOARD - BRIEF PAUSES */
          if(m_grid->getTransition() == 1){
            sleep(1);
            m_grid->next(*tempG, true);
          }
          /* CLASSICAL - GIVEN BOARD - PRESS ENTER */
          else if(m_grid->getTransition() == 2){
            promptEnter();
            m_grid->next(*tempG, true);
          }
          /* CLASSICAL - GIVEN BOARD - WRITE TO ANOTHER FILE */
          else if(m_grid->getTransition() == 3){
            m_grid->next(*tempG, false);
            outFile.open(userFile, ios::out | ios::app);
            if(!m_grid->isEmpty()){
              outFile << m_grid->printGrid();
            }
            outFile.close();
          }
          else {

          }
        }
      }
      /* DOUGHNUT - GIVEN BOARD */
      else if(mode == 2){
        int transition = getGenerationTransition();
        string userFile;
        ofstream outFile;
        if(transition == 3){
          cout << "Enter the name of the file where the results should be outputted: " << endl;
          cin >> userFile;
        }
        m_gridDoughnut = new Doughnut(file, transition);
        if(transition == 1 || transition == 2){
          cout << "INITIAL GRID: \n";
          cout << m_gridDoughnut->printGrid();
        }
        if(transition == 3){
          outFile.open(userFile);
          outFile << m_gridDoughnut->printInitGrid();
          outFile << m_gridDoughnut->printGrid();
          outFile.close();
        }
        Doughnut* tempGrid = new Doughnut(*m_gridDoughnut);
        if(transition == 3){
          m_gridDoughnut->next(*tempGrid, false);
          outFile.open(userFile, ios::out | ios::app);
          outFile << m_gridDoughnut->printGrid();
          outFile.close();
        }
        else{
          m_gridDoughnut->next(*tempGrid, true);
        }
        while(m_gridDoughnut->compareGenerations() == false && m_gridDoughnut->isEmpty() == false){
          Doughnut* tempG = new Doughnut(*m_gridDoughnut);
          /* DOUGHNUT - RANDOM BOARD - BRIEF PAUSES */
          if(m_gridDoughnut->getTransition() == 1){
            sleep(1);
            m_gridDoughnut->next(*tempG, true);
          }
          /* DOUGHNUT - RANDOM BOARD - PRESS ENTER */
          else if(m_gridDoughnut->getTransition() == 2){
            promptEnter();
            m_gridDoughnut->next(*tempG, true);
          }
          /* DOUGHNUT - RANDOM BOARD - WRITE TO ANOTHER FILE */
          else if(m_gridDoughnut->getTransition() == 3){
            m_gridDoughnut->next(*tempG, false);
            outFile.open(userFile, ios::out | ios::app);
            if(!m_gridDoughnut->isEmpty()){
              outFile << m_gridDoughnut->printGrid();
            }
            outFile.close();
          }
          else {

          }
        }
      }
      /* MIRROR - GIVEN BOARD */
      else if(mode == 3){
        int transition = getGenerationTransition();
        string userFile;
        ofstream outFile;
        if(transition == 3){
          cout << "Enter the name of the file where the results should be outputted: " << endl;
          cin >> userFile;
        }
        m_gridMirror = new Mirror(file, transition);
        if(transition == 1 || transition == 2){
          cout << "INITIAL GRID: \n";
          cout << m_gridMirror->printGrid();
        }
        if(transition == 3){
          outFile.open(userFile);
          outFile << m_gridMirror->printInitGrid();
          outFile << m_gridMirror->printGrid();
          outFile.close();
        }
        Mirror* tempGridMirror = new Mirror(*m_gridMirror);
        if(transition == 3){
          m_gridMirror->next(*tempGridMirror, false);
          outFile.open(userFile, ios::out | ios::app);
          outFile << m_gridMirror->printGrid();
          outFile.close();
        }
        else{
          m_gridMirror->next(*tempGridMirror, true);
        }
        while(m_gridMirror->compareGenerations() == false && m_gridMirror->isEmpty() == false){
          Mirror* tempG = new Mirror(*m_gridMirror);
          /* DOUGHNUT - RANDOM BOARD - BRIEF PAUSES */
          if(m_gridMirror->getTransition() == 1){
            sleep(1);
            m_gridMirror->next(*tempG, true);
          }
          /* DOUGHNUT - RANDOM BOARD - PRESS ENTER */
          else if(m_gridMirror->getTransition() == 2){
            promptEnter();
            m_gridMirror->next(*tempG, true);
          }
          /* DOUGHNUT - RANDOM BOARD - WRITE TO ANOTHER FILE */
          else if(m_gridMirror->getTransition() == 3){
            m_gridMirror->next(*tempG, false);
            outFile.open(userFile, ios::out | ios::app);
            if(!m_gridMirror->isEmpty()){
              outFile << m_gridMirror->printGrid();
            }
            outFile.close();
          }
          else {

          }
        }
      }
  }
  else {
    cerr << "Invalid input" << endl;
  }
}
/* Destructor */
Game::~Game(){
  delete m_grid;
  delete m_gridDoughnut;
  delete m_gridMirror;
}
/* HELPER FUNCTIONS - PROMPTS USER FOR INPUTS */
int Game::getResponse(){
  int response;
  while(true){
    cout << "Enter 1 if you like to randomly assign cell values or 2 if you would like to use a map" << endl;
    if(cin.fail()){
      cerr << "ERROR: INVALID INPUT - PLEASE FOLLOW DIRECTIONS" << endl;
      cin.clear();
      cin.ignore(10000,'\n');
      continue;
    }
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
    if(cin.fail()){
      cerr << "ERROR: INVALID INPUT - PLEASE FOLLOW DIRECTIONS" << endl;
      cin.clear();
      cin.ignore(10000,'\n');
      continue;
    }
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
    if(cin.fail()){
      cerr << "ERROR: INVALID INPUT - PLEASE FOLLOW DIRECTIONS" << endl;
      cin.clear();
      cin.ignore(10000,'\n');
      continue;
    }
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
    if(cin.fail()){
      cerr << "ERROR: INVALID INPUT - PLEASE FOLLOW DIRECTIONS" << endl;
      cin.clear();
      cin.ignore(10000,'\n');
      continue;
    }
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
    if(cin.fail()){
      cerr << "ERROR: INVALID INPUT - PLEASE FOLLOW DIRECTIONS" << endl;
      cin.clear();
      cin.ignore(10000,'\n');
      continue;
    }
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
  while(true){
    cout << "Enter the name of the map file?" << endl;
    cin >> file;
    if(cin.fail()){
      cerr << "ERROR: INVALID INPUT - PLEASE FOLLOW DIRECTIONS" << endl;
      cin.clear();
      cin.ignore(10000,'\n');
      continue;
    }
    else
      break;
  }
  return file;
}
int Game::getMode(){
  int mode;
  while(true){
    cout << "Enter 1 for Classic Mode, 2 for Doughnut Mode, and 3 for Mirror Mode" << endl;
    cin >> mode;
    if(cin.fail()){
      cerr << "ERROR: INVALID INPUT - PLEASE FOLLOW DIRECTIONS" << endl;
      cin.clear();
      cin.ignore(10000,'\n');
      continue;
    }
    if(mode == 1 || mode == 2 || mode == 3)
      break;
    else
      cerr << "ERROR: INVALID INPUT - PLEASE FOLLOW DIRECTIONS" << endl;
      continue;
  }
  return mode;
}
void Game::promptEnter(){
  while(true){
     string in;
     cout << "PRESS ENTER TO CONTINUE: ";
     getline(cin, in);
     if (in.empty())
      break;
     else{
       cerr << "ERROR: INVALID INPUT - PLEASE FOLLOW DIRECTIONS" << endl;
       continue;
     }
   }
}
void Game::promptQuit(){
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
