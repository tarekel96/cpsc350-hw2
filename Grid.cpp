#include "Grid.h"

Grid::Grid(){
  m_width = 3;
  m_height = 3;
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
Grid::Grid(int width, int height){
  m_width = width;
  m_height = height;
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
string Grid::printGrid(){
  string grid = "";
  // print
  for(int i = 0; i < m_width; ++i){
    for(int j = 0; j < m_height; ++j){
      cout << array[i][j].getValue() << " ";
    }
    cout << endl;
  }
  return grid;
}
Grid::~Grid(){
  delete array;
}
int Grid::getRows(){
  return m_width;
}
int Grid::getColumns(){
  return m_height;
}
void Grid::setElement(int row, int col, char value){
  array[row][col].setValue(value);
}
char Grid::getElement(int row, int col){
  return array[row][col].getValue();
}
