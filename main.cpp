#include <fstream>
#include "Grid.h"
int main(int argv, char ** argc){
  Grid* g = new Grid(2,2);
  int response;
  cout << "Enter 1 if you like to randomly assign cell values or 2 if you would like to use a map" << endl;
  cin >> response;
  if(response == 1){

  }
  else if(response == 2){
    string file;
    ifstream inFile;
    int rows;
    int columns;
    string line;
    bool first = true;
    bool second = false;
    cout << "Enter the name of the map file?" << endl;
    cin >> file;
    inFile.open(file);
    string temp;
    while(getline(inFile, line)){
      temp = line;
      if(first){
        rows = stoi(temp);
        first = false;
        second = true;
        continue;
      }
      if(second){
        columns = stoi(temp);
        second = false;
        inFile.close();
        break;
      }
    }
    // string element;
    first = true;
    second = false;
    cout << "COLUMNS: " << columns << endl;
    Grid *g = new Grid(rows, columns);
    inFile.open(file);
    string currentLine;
    int counter = 0;
    while(getline(inFile, currentLine)){
      if(currentLine.length() == 1){
        continue;
      }
      else {
        for(int i = 0; i < currentLine.length(); ++i){
          cout << "HERE" << currentLine[i] << endl;
          g->setElement(counter, i, currentLine[i]);
        }
        counter += 1;
      }
      g->printGrid();
    }
  }
  else {
    cerr << "ERROR: Invalid Response ~ Please follow directions." << endl;
  }

  // int rows;
  // int columns;
  // cout << "Enter the number of rows your grid will have: " << endl;
  // cin >> rows;
  // cout << "Enter the number of columns your grid will have: " << endl;
  // cin >> columns;
  // // Grid* g = new Grid(rows, columns);
  // // g->printGrid();
  // int response;
  // cout << "Enter 1 for Classic Mode and 2 for Doughtnut mode: " << endl;
  // cin >> response;
  // // classic mode
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
  return 0;
}
