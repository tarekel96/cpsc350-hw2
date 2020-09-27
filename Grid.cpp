#include "Grid.h"

Grid::Grid(){
  width = 3;
  height = 3;
  // dynamic allocation
  array = new Cell*[width];
  for(int i = 0; i < width; ++i){
      array[i] = new Cell[height];
  }
}
//   // fill
//   for(int i = 0; i < width; ++i){
//     for(int j = 0; j < height; ++j){
//       array[i][j] = '-';
//     }
//   }
// }
// Grid::Grid(int width, int height){
//   array = new char[width][height];
//   for(int i = 0; i < width; ++i){
//     for(int j = 0; j < height; ++j){
//       array[width][height] = '-';
//     }
//   }
// }
string Grid::printGrid(){
  string grid = "";
  // print
  for(int i = 0; i < width; ++i){
    for(int j = 0; j < height; ++j){
      cout << " " << array[i][j].getValue() << " ";
    }
    cout << endl;
  }
  return grid;
}
Grid::~Grid(){
  delete array;
}
