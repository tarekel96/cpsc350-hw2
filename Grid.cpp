#include "Grid.h"

Grid::Grid(){
  m_generation = 0;
  m_width = 3;
  m_height = 3;
  m_transition = 1;
  // dynamic allocation
  board = new Cell*[m_width];
  for(int i = 0; i < m_width; ++i){
      board[i] = new Cell[m_height];
  }
  // fill
  for(int i = 0; i < m_width; ++i){
    for(int j = 0; j < m_height; ++j){
      board[i][j].setValue('\0');
    }
  }
}
// Copy constructor
Grid::Grid(Grid &currentGrid){
  m_width = currentGrid.m_width;
  m_height = currentGrid.m_height;
  m_transition = currentGrid.m_transition;
  m_generation = currentGrid.m_generation;
  // cout << "generation " << m_generation << endl;
  // incrementGeneration();
  // cout << "generation " << m_generation << endl;
  // dynamic allocation
  board = new Cell*[m_width];
  for(int i = 0; i < m_width; ++i){
    board[i] = new Cell[m_height];
  }
  // fill - copy values from currentGrid
  for(int i = 0; i < m_width; ++i){
    for(int j = 0; j < m_height; ++j){
      board[i][j] = currentGrid.board[i][j];
    }
  }
}
Grid::Grid(string file, int transition){
  m_generation = 0;
  m_transition = transition;
  ifstream inFile;
  int rows;
  int columns;
  string line;
  bool first = true;
  bool second = false;
  inFile.open(file);
  string temp;
  while(getline(inFile, line)){
    temp = line;
    if(first){
      m_width = stoi(temp);
      first = false;
      second = true;
      continue;
    }
    if(second){
      m_height = stoi(temp);
      second = false;
      inFile.close();
      break;
    }
  }
  // dynamic allocation
  board = new Cell*[m_width];
  for(int i = 0; i < m_width; ++i){
      board[i] = new Cell[m_height];
  }
  inFile.open(file);
  string currentLine;
  int counter = 0;
  while(getline(inFile, currentLine)){
    if(currentLine.length() == 1){
      continue;
    }
    else {
      // fill
      for(int i = 0; i < currentLine.length(); ++i){
        board[counter][i].setValue(currentLine[i]);
      }
      counter += 1;
    }
  }
}
Grid::Grid(int width, int height, int transition){
  m_generation = 0;
  m_transition = transition;
  m_width = width;
  m_height = height;
  // dynamic allocation
  board = new Cell*[m_width];
  for(int i = 0; i < m_width; ++i){
      board[i] = new Cell[m_height];
  }
  // fill
  for(int i = 0; i < m_width; ++i){
    for(int j = 0; j < m_height; ++j){
      board[i][j].setValue('\0');
    }
  }
}
Grid::Grid(int width, int height, float populationDensity, int transition){
  m_generation = 0;
  m_transition = transition;
  float r; // random variable
  m_width = width;
  m_height = height;
  // dynamic allocation
  board = new Cell*[m_width];
  for(int i = 0; i < m_width; ++i){
      board[i] = new Cell[m_height];
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
string Grid::printGrid(){
  string grid = "";
  // print
  grid += "CLASSICAL MODE\n";
  grid += "GENERATION: ";
  grid += to_string(getGenerationNumber());
  grid += "\n";
  for(int i = 0; i < m_width; ++i){
    for(int j = 0; j < m_height; ++j){
      grid += board[i][j].getValue();
      grid += " ";
    }
    grid += "\n";
  }
  return grid;
}
string Grid::printPrevGrid(){
  string grid = "";
  // print
  grid += "CLASSICAL MODE\n";
  grid += "PREVIOUS GENERATION: ";
  grid += to_string((getGenerationNumber() - 1));
  grid += "\n";
  for(int i = 0; i < m_width; ++i){
    for(int j = 0; j < m_height; ++j){
      grid += prevBoard[i][j].getValue();
      grid += " ";
    }
    grid += "\n";
  }
  return grid;
}
Grid::~Grid(){
  delete board;
}
void Grid::incrementGeneration(){
  m_generation++;
}
int Grid::getRows(){
  return m_width;
}
int Grid::getColumns(){
  return m_height;
}
int Grid::getGenerationNumber(){
  return m_generation;
}
int Grid::getTransition(){
  return m_transition;
}
void Grid::setGeneration(int generation){
  m_generation = generation;
}
void Grid::setElement(int row, int col, char value){
  board[row][col].setValue(value);
}
char Grid::getElement(int row, int col){
  return board[row][col].getValue();
}
void Grid::setPrevBoard(Grid &currentBoard){
  int width = currentBoard.m_width;
  int height = currentBoard.m_height;
  int transition = currentBoard.m_transition;
  int generation = currentBoard.m_generation;
  // cout << "generation " << m_generation << endl;
  // incrementGeneration();
  // cout << "generation " << m_generation << endl;
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
int Grid::calculateNumberOfNeighbors(int row, int col, Grid &currentGrid){
  int count = 0;
  //cout << "Occupied : " << currentGrid.board[row][col].getOccupied() << endl;
  // top left case
  if(row == 0 && col == 0){
    if(currentGrid.board[row][col + 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row + 1][col].getOccupied()){
      count++;
    }
    if(currentGrid.board[row + 1][col + 1].getOccupied()){
      count++;
    }
  }
  // top right case
  else if(row == 0 && col == currentGrid.m_height - 1){
    if(currentGrid.board[row][col - 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row + 1][col].getOccupied()){
      count++;
    }
    if(currentGrid.board[row + 1][col - 1].getOccupied()){
      count++;
    }
  }
  // bottom left case
  else if(row == currentGrid.m_width - 1 && col == 0){
    if(currentGrid.board[row][col + 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row - 1][col].getOccupied()){
      count++;
    }
    if(currentGrid.board[row - 1][col + 1].getOccupied()){
      count++;
    }
  }
  // bottom right case
  else if(row == currentGrid.m_width - 1 && col == currentGrid.m_height - 1){
    if(currentGrid.board[row - 1][col].getOccupied()){
      count++;
    }
    if(currentGrid.board[row][col - 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row - 1][col - 1].getOccupied()){
      count++;
    }
  }
  // first row - middle
  else if(row == 0 && col != 0 && col != currentGrid.m_height - 1){
    if(currentGrid.board[row][col + 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row][col - 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row + 1][col].getOccupied()){
      count++;
    }
    if(currentGrid.board[row + 1][col + 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row + 1][col - 1].getOccupied()){
      count++;
    }
  }
  // last row - middle
  else if(row == currentGrid.m_width - 1 && col != 0 && col != currentGrid.m_height - 1){
    if(currentGrid.board[row][col + 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row][col - 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row - 1][col].getOccupied()){
      count++;
    }
    if(currentGrid.board[row - 1][col + 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row - 1][col - 1].getOccupied()){
      count++;
    }
  }
  // first col - middle
  else if(col == 0 && row != 0 && row != currentGrid.m_width - 1){
    if(currentGrid.board[row][col + 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row + 1][col].getOccupied()){
      count++;
    }
    if(currentGrid.board[row - 1][col].getOccupied()){
      count++;
    }
    if(currentGrid.board[row + 1][col + 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row - 1][col + 1].getOccupied()){
      count++;
    }
  }
  // last col - middle
  else if(col == currentGrid.m_height - 1 && row != 0 && row != currentGrid.m_width - 1){
    if(currentGrid.board[row][col - 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row + 1][col].getOccupied()){
      count++;
    }
    if(currentGrid.board[row - 1][col].getOccupied()){
      count++;
    }
    if(currentGrid.board[row + 1][col - 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row - 1][col - 1].getOccupied()){
      count++;
    }
  }
  // middle
  else {
    if(currentGrid.board[row][col + 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row][col - 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row + 1][col].getOccupied()){
      count++;
    }
    if(currentGrid.board[row - 1][col].getOccupied()){
      count++;
    }
    if(currentGrid.board[row - 1][col + 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row - 1][col - 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row + 1][col + 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row + 1][col - 1].getOccupied()){
      count++;
    }
  }
  return count;
}
void Grid::next(Grid &currentGrid){
  Grid* newGrid = new Grid(currentGrid);
  prevBoard = currentGrid.board;
  for(int i = 0; i < currentGrid.m_width; ++i){
    for(int j = 0; j < currentGrid.m_height; ++j){
      Cell currentCell = currentGrid.board[i][j];
      // cout << "Cell at " << "[" << i << "]" << "[" << j << "]" << " count: " << calculateNumberOfNeighbors(i,j, currentGrid) << endl;
      int numberOfNeighbors = calculateNumberOfNeighbors(i, j, currentGrid);
      if(numberOfNeighbors <= 1){
        newGrid->setElement(i, j, '-');
      }
      else if(numberOfNeighbors == 2){
        newGrid->setElement(i,j,currentGrid.board[i][j].getValue());
      }
      else if(numberOfNeighbors == 3){
        newGrid->setElement(i,j,'X');
      }
      else {
        newGrid->setElement(i, j, '-');
      }
    }
  }
  board = newGrid->board;
  incrementGeneration();
  cout << printGrid() << endl;
}
bool Grid::compareGenerations(){
  int count = 0;
  for(int i = 0; i < getRows(); ++i){
    for(int j = 0; j < getColumns(); ++j){
      if(board[i][j].getValue() != prevBoard[i][j].getValue()){
        count += 1;
        break;
      }
    }
  }
  return (count > 0 ? false : true);
}
