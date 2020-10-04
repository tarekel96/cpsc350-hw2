#include "Doughnut.h"

Doughnut::Doughnut():Grid(){}
Doughnut::Doughnut(string file, int transition):Grid(file, transition){}
Doughnut::Doughnut(int width, int height, int transition):Grid(width, height, transition){}
Doughnut::Doughnut(int width, int height, float populationDensity, int transition):Grid(width, height, populationDensity, transition){}
Doughnut::Doughnut(Grid &currentGrid):Grid(currentGrid){}
Doughnut::~Doughnut(){}
string Doughnut::printGrid(){
  string grid = "";
  // print
  grid += "DOUGHNUT MODE\n";
  grid += "GENERATION: ";
  grid += to_string(getGenerationNumber());
  grid += "\n";
  for(int i = 0; i < getRows(); ++i){
    for(int j = 0; j < getColumns(); ++j){
      grid += board[i][j].getValue();
      grid += " ";
    }
    grid += "\n";
  }
  return grid;
}
int Doughnut::calcNeighbors(int row, int col, Doughnut &currentGrid){
  int count = 0;
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
    if(currentGrid.board[row][currentGrid.getColumns() - 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row + 1][currentGrid.getColumns() - 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[currentGrid.getRows() - 1][col].getOccupied()){
      count++;
    }
    if(currentGrid.board[currentGrid.getRows() - 1][col + 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[currentGrid.getRows() - 1][currentGrid.getColumns() - 1].getOccupied()){
      count++;
    }
  }
  // top right case
  else if(row == 0 && col == currentGrid.getColumns() - 1){
    if(currentGrid.board[row][col - 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row + 1][col].getOccupied()){
      count++;
    }
    if(currentGrid.board[row + 1][col - 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row][0].getOccupied()){
      count++;
    }
    if(currentGrid.board[row + 1][0].getOccupied()){
      count++;
    }
    if(currentGrid.board[currentGrid.getRows() - 1][0].getOccupied()){
      count++;
    }
    if(currentGrid.board[currentGrid.getRows() - 1][col].getOccupied()){
      count++;
    }
    if(currentGrid.board[currentGrid.getRows() - 1][col - 1].getOccupied()){
      count++;
    }
  }
  // bottom left case
  else if(row == currentGrid.getRows() - 1 && col == 0){
    if(currentGrid.board[0][col].getOccupied()){
      count++;
    }
    if(currentGrid.board[row - 1][col].getOccupied()){
      count++;
    }
    if(currentGrid.board[row - 1][col + 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row][col + 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[0][col + 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[0][currentGrid.getColumns() - 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row][currentGrid.getColumns() - 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row - 1][currentGrid.getColumns() - 1].getOccupied()){
      count++;
    }
  }
  // bottom right case
  else if(row == currentGrid.getRows() - 1 && col == currentGrid.getColumns() - 1){
    if(currentGrid.board[0][0].getOccupied()){
      count++;
    }
    if(currentGrid.board[row - 1][col].getOccupied()){
      count++;
    }
    if(currentGrid.board[row - 1][col - 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row][col - 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row][0].getOccupied()){
      count++;
    }
    if(currentGrid.board[row - 1][0].getOccupied()){
      count++;
    }
    if(currentGrid.board[0][col].getOccupied()){
      count++;
    }
    if(currentGrid.board[0][col - 1].getOccupied()){
      count++;
    }
  }
  // first row - middle
  else if(row == 0 && col != 0 && col != currentGrid.getColumns() - 1){
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
    if(currentGrid.board[currentGrid.getRows() - 1][col - 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[currentGrid.getRows() - 1][col].getOccupied()){
      count++;
    }
    if(currentGrid.board[currentGrid.getRows() - 1][col + 1].getOccupied()){
      count++;
    }
  }
  // last row - middle
  else if(row == currentGrid.getRows() - 1 && col != 0 && col != currentGrid.getColumns() - 1){
    if(currentGrid.board[row][col - 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row][col + 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row - 1][col - 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row - 1][col].getOccupied()){
      count++;
    }
    if(currentGrid.board[row - 1][col + 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[0][col - 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[0][col].getOccupied()){
      count++;
    }
    if(currentGrid.board[0][col + 1].getOccupied()){
      count++;
    }
  }
  // first col - middle
  else if(col == 0 && row != 0 && row != currentGrid.getRows() - 1){
    if(currentGrid.board[row - 1][col].getOccupied()){
      count++;
    }
    if(currentGrid.board[row + 1][col].getOccupied()){
      count++;
    }
    if(currentGrid.board[row - 1][col + 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row][col + 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row + 1][col + 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row - 1][currentGrid.getColumns() - 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row][currentGrid.getColumns() - 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row + 1][currentGrid.getColumns() - 1].getOccupied()){
      count++;
    }
  }
  // last col - middle
  else if(col == currentGrid.getColumns() - 1 && row != 0 && row != currentGrid.getRows() - 1){
    if(currentGrid.board[row - 1][col - 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row][col - 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row + 1][col - 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row - 1][col].getOccupied()){
      count++;
    }
    if(currentGrid.board[row + 1][col].getOccupied()){
      count++;
    }
    if(currentGrid.board[row - 1][0].getOccupied()){
      count++;
    }
    if(currentGrid.board[row][0].getOccupied()){
      count++;
    }
    if(currentGrid.board[row + 1][0].getOccupied()){
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
void Doughnut::next(Doughnut &currentGrid, bool print){
  Doughnut* newGrid = new Doughnut(currentGrid);
  const int ROW = currentGrid.getRows();
  const int COL = currentGrid.getColumns();
  prevBoard = currentGrid.board;
  for(int i = 0; i < ROW; ++i){
    for(int j = 0; j < COL; ++j){
      int numberOfNeighbors = calcNeighbors(i, j, currentGrid);
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
  if(print)
    cout << printGrid() << endl;
}
