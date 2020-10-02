#include "Doughnut.h"

Doughnut::Doughnut():Grid(){}
Doughnut::Doughnut(string file):Grid(file){}
Doughnut::Doughnut(int width, int height):Grid(width, height){}
Doughnut::Doughnut(int width, int height, float populationDensity):Grid(width, height, populationDensity){}
Doughnut::Doughnut(const Grid &currentGrid):Grid(currentGrid){}
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
      grid += array[i][j].getValue();
      grid += " ";
    }
    grid += "\n";
  }
  return grid;
}
