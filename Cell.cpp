#include "Cell.h"

Cell::Cell(){
  m_value = '\0';
  m_occupied = false;
  m_numberOfNeighbors = 0;
}
Cell::Cell(bool occupied, int numberOfNeighbors){
  m_occupied = occupied;
  m_numberOfNeighbors = numberOfNeighbors;
  if(occupied){
    m_value = 'X';
  }
  else {
    m_value = '\0';
  }
}
char Cell::getValue(){
  return m_value;
}
bool Cell::getOccupied(){
  return m_occupied;
}
int Cell::getNumberOfNeighbors(){
  return m_numberOfNeighbors;
}
void Cell::setValue(char value){
  m_value = value;
  if(value != '\0'){
    m_occupied = true;
  }
}
void Cell::setOccupied(bool occupied){
  m_occupied = occupied;
}
void Cell::setNumberOfNeighbors(int numberOfNeighbors){
  m_numberOfNeighbors = numberOfNeighbors;
}
