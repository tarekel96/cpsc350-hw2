#include "Cell.h"

Cell::Cell(){
  value = '\0';
  occupied = false;
  numberOfNeighbors = 0;
}
Cell::Cell(bool occupied, int numberOfNeighbors){
  occupied = occupied;
  numberOfNeighbors = numberOfNeighbors;
  if(occupied){
    value = 'X';
  }
  else {
    value = '\0';
  }
}
char Cell::getValue(){
  return value;
}
bool Cell::getOccupied(){
  return occupied;
}
int Cell::getNumberOfNeighbors(){
  return numberOfNeighbors;
}
void Cell::setValue(char value){
  value = value;
}
void Cell::setOccupied(bool occupied){
  occupied = occupied;
}
void Cell::setNumberOfNeighbors(int numberOfNeighbors){
  numberOfNeighbors = numberOfNeighbors;
}
