#include "Grid.h"

Grid::Grid(){
  m_generation = 0;
  m_width = 3;
  m_height = 3;
  m_mode = 1;
  // dynamic allocation
  array = new Cell*[m_width];
  for(int i = 0; i < m_width; ++i){
      array[i] = new Cell[m_height];
  }
  // fill
  for(int i = 0; i < m_width; ++i){
    for(int j = 0; j < m_height; ++j){
      array[i][j].setValue('\0');
    }
  }
}
// Copy constructor
Grid::Grid(const Grid &currentGrid){
  m_width = currentGrid.m_width;
  m_height = currentGrid.m_height;
  m_mode = currentGrid.m_mode;
  // dynamic allocation
  array = new Cell*[m_width];
  for(int i = 0; i < m_width; ++i){
    array[i] = new Cell[m_height];
  }
  // fill - copy values from currentGrid
  for(int i = 0; i < m_width; ++i){
    for(int j = 0; j < m_height; ++j){
      array[i][j] = currentGrid.array[i][j];
    }
  }
}
Grid::Grid(string file, int mode){
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
  array = new Cell*[m_width];
  for(int i = 0; i < m_width; ++i){
      array[i] = new Cell[m_height];
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
        array[counter][i].setValue(currentLine[i]);
      }
      counter += 1;
    }
  }
}
Grid::Grid(int width, int height, int mode){
  m_generation = 0;
  m_width = width;
  m_height = height;
  m_mode = mode;
  // dynamic allocation
  array = new Cell*[m_width];
  for(int i = 0; i < m_width; ++i){
      array[i] = new Cell[m_height];
  }
  // fill
  for(int i = 0; i < m_width; ++i){
    for(int j = 0; j < m_height; ++j){
      array[i][j].setValue('\0');
    }
  }
}
Grid::Grid(int width, int height, float populationDensity, int mode){
  m_mode = mode;
  m_generation = 0;
  float r; // random variable
  m_width = width;
  m_height = height;
  // dynamic allocation
  array = new Cell*[m_width];
  for(int i = 0; i < m_width; ++i){
      array[i] = new Cell[m_height];
  }
  // fill
  for(int i = 0; i < width; ++i){
    for(int j = 0; j < height; ++j){
      r = ((float)rand()/ (float)RAND_MAX);
      if(r <= populationDensity){
        array[i][j].setValue('X');
      }
      else {
        array[i][j].setValue('-');
      }
    }
    cout << endl;
  }
}
string Grid::printGrid(){
  string grid = "";
  // print
  grid += "GENERATION: ";
  grid += getGenerationNumber();
  grid += "\n";
  for(int i = 0; i < m_width; ++i){
    for(int j = 0; j < m_height; ++j){
      grid += array[i][j].getValue();
      grid += " ";
    }
    grid += "\n";
  }
  return grid;
}
Grid::~Grid(){
  delete array;
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
int Grid::getMode(){
  return m_mode;
}
void Grid::setMode(int mode){
  m_mode = mode;
}
void Grid::setElement(int row, int col, char value){
  array[row][col].setValue(value);
}
char Grid::getElement(int row, int col){
  return array[row][col].getValue();
}
int Grid::calculateNumberOfNeighbors(int row, int col, Grid const &currentGrid){
  int count = 0;
  //cout << "Occupied : " << currentGrid.array[row][col].getOccupied() << endl;
  // top left case
  if(row == 0 && col == 0){
    if(currentGrid.array[row][col + 1].getOccupied()){
      count++;
    }
    if(currentGrid.array[row + 1][col].getOccupied()){
      count++;
    }
    if(currentGrid.array[row + 1][col + 1].getOccupied()){
      count++;
    }
  }
  // top right case
  else if(row == 0 && col == currentGrid.m_height - 1){
    if(currentGrid.array[row][col - 1].getOccupied()){
      count++;
    }
    if(currentGrid.array[row + 1][col].getOccupied()){
      count++;
    }
    if(currentGrid.array[row + 1][col - 1].getOccupied()){
      count++;
    }
  }
  // bottom left case
  else if(row == currentGrid.m_width - 1 && col == 0){
    if(currentGrid.array[row][col + 1].getOccupied()){
      count++;
    }
    if(currentGrid.array[row - 1][col].getOccupied()){
      count++;
    }
    if(currentGrid.array[row - 1][col + 1].getOccupied()){
      count++;
    }
  }
  // bottom right case
  else if(row == currentGrid.m_width - 1 && col == currentGrid.m_height - 1){
    if(currentGrid.array[row - 1][col].getOccupied()){
      count++;
    }
    if(currentGrid.array[row][col - 1].getOccupied()){
      count++;
    }
    if(currentGrid.array[row - 1][col - 1].getOccupied()){
      count++;
    }
  }
  // first row - middle
  else if(row == 0 && col != 0 && col != currentGrid.m_height - 1){
    if(currentGrid.array[row][col + 1].getOccupied()){
      count++;
    }
    if(currentGrid.array[row][col - 1].getOccupied()){
      count++;
    }
    if(currentGrid.array[row + 1][col].getOccupied()){
      count++;
    }
    if(currentGrid.array[row + 1][col + 1].getOccupied()){
      count++;
    }
    if(currentGrid.array[row + 1][col - 1].getOccupied()){
      count++;
    }
  }
  // last row - middle
  else if(row == currentGrid.m_width - 1 && col != 0 && col != currentGrid.m_height - 1){
    if(currentGrid.array[row][col + 1].getOccupied()){
      count++;
    }
    if(currentGrid.array[row][col - 1].getOccupied()){
      count++;
    }
    if(currentGrid.array[row - 1][col].getOccupied()){
      count++;
    }
    if(currentGrid.array[row - 1][col + 1].getOccupied()){
      count++;
    }
    if(currentGrid.array[row - 1][col - 1].getOccupied()){
      count++;
    }
  }
  // first col - middle
  else if(col == 0 && row != 0 && row != currentGrid.m_width - 1){
    if(currentGrid.array[row][col + 1].getOccupied()){
      count++;
    }
    if(currentGrid.array[row + 1][col].getOccupied()){
      count++;
    }
    if(currentGrid.array[row - 1][col].getOccupied()){
      count++;
    }
    if(currentGrid.array[row + 1][col + 1].getOccupied()){
      count++;
    }
    if(currentGrid.array[row - 1][col + 1].getOccupied()){
      count++;
    }
  }
  // last col - middle
  else if(col == currentGrid.m_height - 1 && row != 0 && row != currentGrid.m_width - 1){
    if(currentGrid.array[row][col - 1].getOccupied()){
      count++;
    }
    if(currentGrid.array[row + 1][col].getOccupied()){
      count++;
    }
    if(currentGrid.array[row - 1][col].getOccupied()){
      count++;
    }
    if(currentGrid.array[row + 1][col - 1].getOccupied()){
      count++;
    }
    if(currentGrid.array[row - 1][col - 1].getOccupied()){
      count++;
    }
  }
  // middle
  else {
    if(currentGrid.array[row][col + 1].getOccupied()){
      count++;
    }
    if(currentGrid.array[row][col - 1].getOccupied()){
      count++;
    }
    if(currentGrid.array[row + 1][col].getOccupied()){
      count++;
    }
    if(currentGrid.array[row - 1][col].getOccupied()){
      count++;
    }
    if(currentGrid.array[row - 1][col + 1].getOccupied()){
      count++;
    }
    if(currentGrid.array[row - 1][col - 1].getOccupied()){
      count++;
    }
    if(currentGrid.array[row + 1][col + 1].getOccupied()){
      count++;
    }
    if(currentGrid.array[row + 1][col - 1].getOccupied()){
      count++;
    }
  }
  return count;
}
void Grid::next(Grid const& currentGrid){
  Grid* newGrid = new Grid(currentGrid);
  for(int i = 0; i < currentGrid.m_width; ++i){
    for(int j = 0; j < currentGrid.m_height; ++j){
      Cell currentCell = currentGrid.array[i][j];
      //cout << "Cell at " << "[" << i << "]" << "[" << j << "]" << " count: " << calculateNumberOfNeighbors(i,j, currentGrid) << endl;
      int numberOfNeighbors = calculateNumberOfNeighbors(i, j, currentGrid);
      if(numberOfNeighbors <= 1){
        newGrid->setElement(i, j, '-');
      }
      else if(numberOfNeighbors == 2){
        newGrid->setElement(i,j,currentGrid.array[i][j].getValue());
      }
      else if(numberOfNeighbors == 3){
        newGrid->setElement(i,j,'X');
      }
      else {
        newGrid->setElement(i, j, '-');
      }
    }
  }
}
void Grid::simulate(){
  bool occupied;
  for(int i = 0; i < m_width; ++i){
    for(int j = 0; j < m_height; ++j){
      occupied = array[i][j].getOccupied();
      if(occupied){
        int numberOfNeighbors;
        if(i == 0 && j == 0){
          if(array[i + 1][j].getOccupied()) numberOfNeighbors++;
          if(array[i][j+1].getOccupied()) numberOfNeighbors++;
          if(array[i+1][j+1].getOccupied()) numberOfNeighbors++;
        }
        else if(i == 0 && j == m_height - 1){
          if(array[i - 1][j].getOccupied()) numberOfNeighbors++;
          if(array[i][j + 1].getOccupied()) numberOfNeighbors++;
          if(array[i -1][j + 1].getOccupied()) numberOfNeighbors++;
        }
        else if(i == m_width - 1 && j == 0){
          if(array[i + 1][j].getOccupied()) numberOfNeighbors++;
          if(array[i][j-1].getOccupied()) numberOfNeighbors++;
          if(array[i+1][j-1].getOccupied()) numberOfNeighbors++;
        }
        else if(i == m_width - 1 && j == m_height - 1){
          if(array[i - 1][j].getOccupied()) numberOfNeighbors++;
          if(array[i][j - 1].getOccupied()) numberOfNeighbors++;
          if(array[i -1][j - 1].getOccupied()) numberOfNeighbors++;
        }
        else {
          if(array[i - 1][j].getOccupied()) numberOfNeighbors++;
          if(array[i + 1][j].getOccupied()) numberOfNeighbors++;
          if(array[i][j - 1].getOccupied()) numberOfNeighbors++;
          if(array[i + 1][j + 1].getOccupied()) numberOfNeighbors++;
          if(array[i + 1][j - 1].getOccupied()) numberOfNeighbors++;
          if(array[i - 1][j + 1].getOccupied()) numberOfNeighbors++;
          if(array[i - 1][j - 1].getOccupied()) numberOfNeighbors++;
        }
      }
    }
  }
}
