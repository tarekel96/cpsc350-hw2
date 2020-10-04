#include "Mirror.h"
Mirror::Mirror():Grid(){}
Mirror::Mirror(string file, int transition):Grid(file, transition){}
Mirror::Mirror(int width, int height, int transition):Grid(width, height, transition){}
Mirror::Mirror(int width, int height, float populationDensity, int transition):Grid(width, height, populationDensity, transition){}
Mirror::Mirror(Grid &currentGrid):Grid(currentGrid){}
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
      grid += board[i][j].getValue();
      grid += " ";
    }
    grid += "\n";
  }
  return grid;
}
