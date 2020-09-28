#include "Grid.h"
int main(int argv, char ** argc){
  int response;
  cout << "Enter 1 if you like to randomly assign cell values or 2 if you would like to use a map" << endl;
  cin >> response;
  if(response == 1){
    int rows;
    int columns;
    float populationDensity;
    bool correctInput = false;
    int numberOfCells;
    cout << "Enter the number of rows your grid will have: " << endl;
    cin >> rows;
    cout << "Enter the number of columns your grid will have: " << endl;
    cin >> columns;
    while (correctInput == false){
      cout << "Enter a decimal value (greater than 0 and less than or equal to 1) - represents the initial population density of the world: " << endl;
      cin >> populationDensity;
      if((populationDensity >= 0.0) && (populationDensity <= 1.0)){
        correctInput = true;
      }
      else {
        correctInput = false;
      }
    }
    int mode;
    cout << "Enter 1 for Classic Mode, 2 for Doughtnut Mode, and 3 for Mirror Mode" << endl;
    cin >> mode;
    Grid* g = new Grid(rows, columns, populationDensity, mode);
    cout<< g->printGrid() << endl;
    g->simulate();
    // int betweenGenerations;
    // cout << "Would you like a brief pause, press the “enter” key, or to output to a file in between generations?" << endl;
    // cout << "Enter 0 for a brief pause, 1 for enter key, and 2 to output to a file: " << endl;
    // cin >> betweenGenerations;
    // g->printGrid();
    // // classic mode
    // int response;
    // cout << "Enter 1 for Classic Mode and 2 for Doughtnut mode: " << endl;
    // cin >> response;
    // if(response == 1){
    //   Grid* g = new Grid(rows, columns);
    //   g->printGrid();
    // }
    // // doughtnut mode
    // else if(response == 2){
    //
    // }
    // // mirror mode
    // else if(response == 3){
    //
    // }
    // else {
    //   cerr << "ERROR: Invalid Response ~ Please follow directions." << endl;
    // }
  }
  else if(response == 2){
    string file;
    int mode;
    cout << "Enter the name of the map file?" << endl;
    cin >> file;
    cout << "Enter 0 for Classic Mode, 1 for Doughtnut Mode, and 2 for Mirror Mode" << endl;
    cin >> mode;
    Grid *g = new Grid(file, mode);
    cout << g->printGrid() << endl;
  }
  else {
    cerr << "ERROR: Invalid Response ~ Please follow directions." << endl;
  }
  return 0;
}
