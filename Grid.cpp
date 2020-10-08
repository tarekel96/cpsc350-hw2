#include "Grid.h"
/* Default Constructor */
Grid::Grid(){
  /* init fields */
  m_generation = 1;
  m_rows = 3;
  m_columns = 3;
  m_transition = 1;
  // dynamic allocation
  board = new Cell*[m_rows];
  for(int i = 0; i < m_rows; ++i){
      board[i] = new Cell[m_columns];
  }
  // fill
  for(int i = 0; i < m_rows; ++i){
    for(int j = 0; j < m_columns; ++j){
      board[i][j].setValue('\0');
    }
  }
}
/* Copy Constructor */
/*
  * @param &currentGrid - repesents an instance of the Grid
*/
Grid::Grid(Grid &currentGrid){
  m_rows = currentGrid.m_rows;
  m_columns = currentGrid.m_columns;
  m_transition = currentGrid.m_transition;
  m_generation = currentGrid.m_generation;
  // dynamic allocation
  board = new Cell*[m_rows];
  for(int i = 0; i < m_rows; ++i){
    board[i] = new Cell[m_columns];
  }
  // fill - copy values from currentGrid
  for(int i = 0; i < m_rows; ++i){
    for(int j = 0; j < m_columns; ++j){
      board[i][j] = currentGrid.board[i][j];
    }
  }
}
/* Overload Constructor */
/* Builds a grid based on a file with a grid from the user */
/*
  * @param file - the name of the map file where the grid is
  * @param transition - the user's preference for handling transitions between generations
*/
Grid::Grid(string file, int transition){
  // cout << "in here " << endl;
  m_generation = 1;
  m_transition = transition;
  ifstream inFile;
  int rows;
  int columns;
  string line;
  bool first = true;
  bool second = false;
  inFile.open(file);
  string temp;
  /* get row and column numbers from user's file (the first 2 lines) */
  while(getline(inFile, line)){
    temp = line;
    if(first){
      m_rows = stoi(temp);
      first = false;
      second = true;
      continue;
    }
    if(second){
      m_columns = stoi(temp);
      second = false;
      inFile.close();
      break;
    }
  }
  // dynamic allocation
  board = new Cell*[m_rows];
  for(int i = 0; i < m_rows; ++i){
      board[i] = new Cell[m_columns];
  }
  inFile.open(file);
  string currentLine;
  getline(inFile, currentLine);
  getline(inFile, currentLine);
  int counter = 0;
  while(getline(inFile, currentLine)){
    if(currentLine.length() == 0)
      break;
    for(int i = 0; i < currentLine.length(); ++i){
      board[counter][i].setValue(currentLine[i]);
    }
    counter++;
  }
}
/* Overload Constructor */
/* Builds a grid based on user's row and column inputs */
/*
  * @param width - the width of the grid
  * @param height - the height of the grid
  * @param transition - the user's preference for handling transitions between generations
*/
Grid::Grid(int width, int height, int transition){
  m_generation = 1;
  m_transition = transition;
  m_rows = width;
  m_columns = height;
  // dynamic allocation
  board = new Cell*[m_rows];
  for(int i = 0; i < m_rows; ++i){
      board[i] = new Cell[m_columns];
  }
  // fill
  for(int i = 0; i < m_rows; ++i){
    for(int j = 0; j < m_columns; ++j){
      board[i][j].setValue('\0');
    }
  }
}
/* Overload Constructor */
/* Builds a grid based on user's row and column inputs */
/* The Cells are filled based on the populationDensity supplied from the user */
/*
  * @param width - the width of the grid
  * @param height - the height of the grid
  * @param populationDensity - the populationDensity of the grid
  * @param transition - the user's preference for handling transitions between generations
*/
Grid::Grid(int width, int height, float populationDensity, int transition){
  m_generation = 1;
  m_transition = transition;
  float r; // random variable
  m_rows = width;
  m_columns = height;
  // dynamic allocation
  board = new Cell*[m_rows];
  for(int i = 0; i < m_rows; ++i){
      board[i] = new Cell[m_columns];
  }
  // fill
  for(int i = 0; i < width; ++i){
    for(int j = 0; j < height; ++j){
      r = ((float)rand()/ (float)RAND_MAX);
      if(r <= populationDensity){
        board[i][j].setValue('X');
      }
      else {
        board[i][j].setValue('-');
      }
    }
  }
}
/* Destructor */
/* deletes the board and prevBoard fields that were allocated to the Heap */
Grid::~Grid(){
  delete board;
  delete prevBoard;
}
/* HELPER FUNCTIONS */
/* returns a string version of the initial grid (board) */
string Grid::printInitGrid(){
  string grid = "";
  grid += "0";
  grid += "\n";
  for(int i = 0; i < m_rows; ++i){
    for(int j = 0; j < m_columns; ++j){
      grid += board[i][j].getValue();
    }
    grid += "\n";
  }
  return grid;
}
/* HELPER FUNCTIONS */
/* returns a string version of the current grid (board) */
string Grid::printGrid(){
  string grid = "";
  grid += "generation ";
  grid += to_string(getGenerationNumber());
  grid += "\n";
  for(int i = 0; i < m_rows; ++i){
    for(int j = 0; j < m_columns; ++j){
      grid += board[i][j].getValue();
    }
    grid += "\n";
  }
  return grid;
}
/* returns a string version of the previous generation's grid (prevBoard) */
string Grid::printPrevGrid(){
  string grid = "";
  // print
  grid += "CLASSICAL MODE\n";
  grid += "PREVIOUS GENERATION: ";
  grid += to_string((getGenerationNumber() - 1));
  grid += "\n";
  for(int i = 0; i < m_rows; ++i){
    for(int j = 0; j < m_columns; ++j){
      grid += prevBoard[i][j].getValue();
      grid += " ";
    }
    grid += "\n";
  }
  return grid;
}
/* increments the m_generation field */
void Grid::incrementGeneration(){
  m_generation++;
}
/* calculates the number of neighbors a Cell in board has - it is based on the location of the Cell (Classical Mode) */
/*
  * @param row - the number of rows of the grid
  * @param col - the number of cols of the grid
  * @param &currentGrid - repesents an instance of the Grid
*/
int Grid::calculateNumberOfNeighbors(int row, int col, Grid &currentGrid){
  int count = 0;
  /* TOP LEFT CASE */
  if(row == 0 && col == 0){
    if(currentGrid.board[row][col + 1].getOccupied()) count++;
    if(currentGrid.board[row + 1][col].getOccupied()) count++;
    if(currentGrid.board[row + 1][col + 1].getOccupied()) count++;
  }
  /* TOP RIGHT CASE */
  else if(row == 0 && col == currentGrid.m_columns - 1){
    if(currentGrid.board[row][col - 1].getOccupied()) count++;
    if(currentGrid.board[row + 1][col].getOccupied()) count++;
    if(currentGrid.board[row + 1][col - 1].getOccupied()) count++;
  }
  /* BOTTOM LEFT CASE */
  else if(row == currentGrid.m_rows - 1 && col == 0){
    if(currentGrid.board[row][col + 1].getOccupied()) count++;
    if(currentGrid.board[row - 1][col].getOccupied()) count++;
    if(currentGrid.board[row - 1][col + 1].getOccupied()) count++;
  }
  /* BOTTOM RIGHT CASE */
  else if(row == currentGrid.m_rows - 1 && col == currentGrid.m_columns - 1){
    if(currentGrid.board[row - 1][col].getOccupied()) count++;
    if(currentGrid.board[row][col - 1].getOccupied()) count++;
    if(currentGrid.board[row - 1][col - 1].getOccupied()) count++;
  }
  /* FIRST ROW - NON CORNER */
  else if(row == 0 && col != 0 && col != currentGrid.m_columns - 1){
    if(currentGrid.board[row][col + 1].getOccupied()) count++;
    if(currentGrid.board[row][col - 1].getOccupied()) count++;
    if(currentGrid.board[row + 1][col].getOccupied()) count++;
    if(currentGrid.board[row + 1][col + 1].getOccupied()) count++;
    if(currentGrid.board[row + 1][col - 1].getOccupied()) count++;
  }
  /* LAST ROW - NON CORNER */
  else if(row == currentGrid.m_rows - 1 && col != 0 && col != currentGrid.m_columns - 1){
    if(currentGrid.board[row][col + 1].getOccupied()) count++;
    if(currentGrid.board[row][col - 1].getOccupied()) count++;
    if(currentGrid.board[row - 1][col].getOccupied()) count++;
    if(currentGrid.board[row - 1][col + 1].getOccupied()) count++;
    if(currentGrid.board[row - 1][col - 1].getOccupied()) count++;
  }
  /* FIRST COL - NON CORNER */
  else if(col == 0 && row != 0 && row != currentGrid.m_rows - 1){
    if(currentGrid.board[row][col + 1].getOccupied()) count++;
    if(currentGrid.board[row + 1][col].getOccupied()) count++;
    if(currentGrid.board[row - 1][col].getOccupied()) count++;
    if(currentGrid.board[row + 1][col + 1].getOccupied()) count++;
    if(currentGrid.board[row - 1][col + 1].getOccupied()) count++;
  }
  /* LAST COL - NON CORNER */
  else if(col == currentGrid.m_columns - 1 && row != 0 && row != currentGrid.m_rows - 1){
    if(currentGrid.board[row][col - 1].getOccupied()) count++;
    if(currentGrid.board[row + 1][col].getOccupied()) count++;
    if(currentGrid.board[row - 1][col].getOccupied()) count++;
    if(currentGrid.board[row + 1][col - 1].getOccupied()) count++;
    if(currentGrid.board[row - 1][col - 1].getOccupied()) count++;
  }
  /* ANYWHERE ELSE - NO EDGES OR CORNERS */
  else {
    if(currentGrid.board[row][col + 1].getOccupied()) count++;
    if(currentGrid.board[row][col - 1].getOccupied()) count++;
    if(currentGrid.board[row + 1][col].getOccupied()) count++;
    if(currentGrid.board[row - 1][col].getOccupied()) count++;
    if(currentGrid.board[row - 1][col + 1].getOccupied()) count++;
    if(currentGrid.board[row - 1][col - 1].getOccupied()) count++;
    if(currentGrid.board[row + 1][col + 1].getOccupied()) count++;
    if(currentGrid.board[row + 1][col - 1].getOccupied()) count++;
  }
  return count;
}
/* creates the board for the next generation - based on the current board (board) */
/*
  * @param &currentGrid - repesents an instance of the Grid
  * @param print - a boolean value that if true will print out the grid to the console after creating a new generation
*/
void Grid::next(Grid &currentGrid, bool print){
  Grid* newGrid = new Grid(currentGrid); // use Copy Constructor to create a copy of the current board
  prevBoard = currentGrid.board; // assign to prevBoard field what was copied
  for(int i = 0; i < currentGrid.m_rows; ++i){
    for(int j = 0; j < currentGrid.m_columns; ++j){
      /* Calculate the number of neighbors each Cell has to determine how the next generation grid will be like */
      int numberOfNeighbors = calculateNumberOfNeighbors(i, j, currentGrid);
      /* <= 1 Neighbors - Cell dies/stays empty */
      if(numberOfNeighbors <= 1){
        newGrid->setElement(i, j, '-');
      }
      /* == 2 Neighbors - Cell stabilizes (stays unchanged) */
      else if(numberOfNeighbors == 2){
        newGrid->setElement(i,j,currentGrid.board[i][j].getValue());
      }
      /* == 3 Neighbors - Cell is born/stays alive */
      else if(numberOfNeighbors == 3){
        newGrid->setElement(i,j,'X');
      }
      /* > 3 Neighbors - Cell dies/stays empty */
      else {
        newGrid->setElement(i, j, '-');
      }
    }
  }
  /* point the board field to the newGrid's board */
  board = newGrid->board;
  incrementGeneration(); /* update generation field */
  if(print)
    cout << printGrid();
}
bool Grid::isEmpty(){
  int count = 0;
  for(int i = 0; i < getRows(); ++i){
    for(int j = 0; j < getColumns(); ++j){
      /* if 1 Cell differs between the board and prevBoard - the Cells are not yet stable*/
      if(board[i][j].getOccupied()){
        count += 1;
        break;
      }
    }
  }
  return (count == 0);
}
/* compares board to prevBoard */
bool Grid::compareGenerations(){
  int count = 0;
  for(int i = 0; i < getRows(); ++i){
    for(int j = 0; j < getColumns(); ++j){
      /* if 1 Cell differs between the board and prevBoard - the Cells are not yet stable*/
      if(board[i][j].getValue() != prevBoard[i][j].getValue()){
        count += 1;
        break;
      }
    }
  }
  return (count == 0);
}
/* ACCESSORS */
int Grid::getRows(){
  return m_rows;
}
int Grid::getColumns(){
  return m_columns;
}
int Grid::getGenerationNumber(){
  return m_generation;
}
int Grid::getTransition(){
  return m_transition;
}
/* MUTATORS */
/*
  * @param generation - the generation that will be set for the Grid class/instance
*/
void Grid::setGeneration(int generation){
  m_generation = generation;
}
/*
  * @param row - the row of the element
  * @param col - the col of the element
  * @param value - the value that will be set for that element
*/
void Grid::setElement(int row, int col, char value){
  board[row][col].setValue(value);
}
/*
  * @param row - the row of the element
  * @param col - the col of the element
*/
char Grid::getElement(int row, int col){
  return board[row][col].getValue();
}
/*
  * @param &currentGrid - repesents an instance of the Grid
*/
/* sets the prevBoard field - very similar to the Copy Constructor */
void Grid::setPrevBoard(Grid &currentBoard){
  int width = currentBoard.m_rows;
  int height = currentBoard.m_columns;
  int transition = currentBoard.m_transition;
  int generation = currentBoard.m_generation;
  // dynamic allocation
  prevBoard = new Cell*[width];
  for(int i = 0; i < width; ++i){
    board[i] = new Cell[height];
  }
  // fill - copy values from currentBoard
  for(int i = 0; i < width; ++i){
    for(int j = 0; j < height; ++j){
      prevBoard[i][j] = currentBoard.board[i][j];
    }
  }
}
