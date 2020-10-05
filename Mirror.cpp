#include "Mirror.h"
/* INHERITANCE */
Mirror::Mirror():Grid(){}
Mirror::Mirror(string file, int transition):Grid(file, transition){}
Mirror::Mirror(int rows, int columns, int transition):Grid(rows, columns, transition){}
Mirror::Mirror(int rows, int columns, float populationDensity, int transition):Grid(rows, columns, populationDensity, transition){}
Mirror::Mirror(Grid &currentGrid):Grid(currentGrid){}
Mirror::~Mirror(){}
/* HELPER FUNCTIONS */
/* @Override - returns a string version of the current grid (board) */
string Mirror::printGrid(){
  string grid = "";
  grid += "MIRROR MODE\n";
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
/* calculates the number of neighbors a Cell in board has - it is based on the location of the Cell (Mirror Mode) */
int Mirror::calcNeighbors(int row, int col, Mirror &currentGrid){
  int count = 0;
  /* TOP LEFT CASE */
  if(row == 0 && col == 0){
    if(currentGrid.board[row][col].getOccupied()){
      count += 3;
    }
    if(currentGrid.board[row][col + 1].getOccupied()){
      count += 2;
    }
    if(currentGrid.board[row + 1][col].getOccupied()){
      count += 2;
    }
    if(currentGrid.board[row + 1][col + 1].getOccupied()){
      count++;
    }
  }
  /* TOP RIGHT CASE */
  else if(row == 0 && col == currentGrid.getColumns() - 1){
    if(currentGrid.board[row][col].getOccupied()){
      count += 3;
    }
    if(currentGrid.board[row][col - 1].getOccupied()){
      count += 2;
    }
    if(currentGrid.board[row + 1][col].getOccupied()){
      count += 2;
    }
    if(currentGrid.board[row + 1][col - 1].getOccupied()){
      count++;
    }
  }
  /* BOTTOM LEFT CASE */
  else if(row == currentGrid.getRows() - 1 && col == 0){
    if(currentGrid.board[row][col].getOccupied()){
      count += 3;
    }
    if(currentGrid.board[row - 1][col].getOccupied()){
      count += 2;
    }
    if(currentGrid.board[row][col + 1].getOccupied()){
      count += 2;
    }
    if(currentGrid.board[row - 1][col + 1].getOccupied()){
      count++;
    }
  }
  /* BOTTOM RIGHT CASE */
  else if(row == currentGrid.getRows() - 1 && col == currentGrid.getColumns() - 1){
    if(currentGrid.board[row][col].getOccupied()){
      count += 3;
    }
    if(currentGrid.board[row - 1][col].getOccupied()){
      count += 2;
    }
    if(currentGrid.board[row][col - 1].getOccupied()){
      count += 2;
    }
    if(currentGrid.board[row - 1][col - 1].getOccupied()){
      count++;
    }
  }
  /* FIRST ROW - NON CORNER */
  else if(row == 0 && col != 0 && col != currentGrid.getColumns() - 1){
    if(currentGrid.board[row][col].getOccupied()){
      count++;
    }
    if(currentGrid.board[row + 1][col].getOccupied()){
      count++;
    }
    if(currentGrid.board[row][col - 1].getOccupied()){
      count += 2;
    }
    if(currentGrid.board[row][col + 1].getOccupied()){
      count += 2;
    }
    if(currentGrid.board[row + 1][col + 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row + 1][col - 1].getOccupied()){
      count++;
    }
  }
  /* LAST ROW - NON CORNER */
  else if(row == currentGrid.getRows() - 1 && col != 0 && col != currentGrid.getColumns() - 1){
    if(currentGrid.board[row][col].getOccupied()){
      count++;
    }
    if(currentGrid.board[row - 1][col].getOccupied()){
      count++;
    }
    if(currentGrid.board[row][col - 1].getOccupied()){
      count += 2;
    }
    if(currentGrid.board[row][col + 1].getOccupied()){
      count += 2;
    }
    if(currentGrid.board[row - 1][col - 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row - 1][col - 1].getOccupied()){
      count++;
    }
  }
  /* FIRST COL - NON CORNER */
  else if(col == 0 && row != 0 && row != currentGrid.getRows() - 1){
    if(currentGrid.board[row][col].getOccupied()){
      count++;
    }
    if(currentGrid.board[row][col + 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row - 1][col].getOccupied()){
      count += 2;
    }
    if(currentGrid.board[row + 1][col].getOccupied()){
      count += 2;
    }
    if(currentGrid.board[row - 1][col + 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row + 1][col + 1].getOccupied()){
      count++;
    }
  }
  /* LAST COL - NON CORNER */
  else if(col == currentGrid.getColumns() - 1 && row != 0 && row != currentGrid.getRows() - 1){
    if(currentGrid.board[row][col].getOccupied()){
      count++;
    }
    if(currentGrid.board[row][col - 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row - 1][col].getOccupied()){
      count += 2;
    }
    if(currentGrid.board[row + 1][col].getOccupied()){
      count += 2;
    }
    if(currentGrid.board[row - 1][col - 1].getOccupied()){
      count++;
    }
    if(currentGrid.board[row + 1][col - 1].getOccupied()){
      count++;
    }
  }
  /* ANYWHERE ELSE - NO EDGES OR CORNERS */
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
/* creates the board for the next generation - based on the current board (board) */
void Mirror::next(Mirror &currentGrid, bool print){
  Mirror* newGrid = new Mirror(currentGrid);
  const int ROW = currentGrid.getRows();
  const int COL = currentGrid.getColumns();
  prevBoard = currentGrid.board;
  for(int i = 0; i < ROW; ++i){
    for(int j = 0; j < COL; ++j){
      /* Calculate the number of neighbors each Cell has to determine how the next generation grid will be like */
      int numberOfNeighbors = calcNeighbors(i, j, currentGrid);
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
    cout << printGrid() << endl;
}
