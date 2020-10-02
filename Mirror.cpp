#include "Mirror.h"
Mirror::Mirror():Grid(){}
Mirror::Mirror(string file):Grid(file){}
Mirror::Mirror(int width, int height):Grid(width, height){}
Mirror::Mirror(int width, int height, float populationDensity):Grid(width, height, populationDensity){}
Mirror::Mirror(const Grid &currentGrid):Grid(currentGrid){}
Mirror::~Mirror(){}
string Mirror::printGrid(){
  string grid = "";
  // print
  grid += "MIRROR MODE\n";
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
