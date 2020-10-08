#include "Cell.h"
/* Default Constructor */
Cell::Cell(){
  /* init fields */
  m_value = '\0';
  m_occupied = false;
}
/* Overloaded Constructor */
/*
  * @param occupied - the bool value of whether a cell is occupied or not
*/
Cell::Cell(bool occupied){
  m_occupied = occupied;
  /* init value based on occupied parameter */
  if(occupied){
    m_value = 'X';
  }
  else {
    m_value = '\0';
  }
}
/* Destructor */
Cell::~Cell(){
  m_occupied = NULL;
  m_value = '\0';
}
/* ACCESSORS */
char Cell::getValue(){
  return m_value;
}
bool Cell::getOccupied(){
  if(m_value == '-'){
    m_occupied = false;
    return false;
  }
  return m_occupied;
}
/* MUTATORS */
/*
  * @param value - the value that would like to cell to
*/
void Cell::setValue(char value){
  if(value != '\0' && value != '-'){
    m_occupied = true;
  }
  m_value = value;
}
/*
  * @param occupied - the bool value of whether a cell is occupied or not
*/
void Cell::setOccupied(bool occupied){
  m_occupied = occupied;
}
