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
  grid += getGenerationNumber();
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
