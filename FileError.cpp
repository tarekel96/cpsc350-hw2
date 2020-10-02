#include "FileError.h"

FileError::FileError(){

}
FileError::FileError(string file){
  setFile(file);
}
FileError::~FileError(){

}
string FileError::getFile(){
  string file;
  cout << "Enter the name of the File: " << endl;
  cin >> file;
  return file;
};
int FileError::checkFile(){
  m_inFile.open(m_file);
  if(m_inFile.fail()){
    cerr << "Error in opening file.\nPlease make sure your file input is correct." << endl;
    return -1;
  }
  else {
    return 0;
  }
}
void FileError::setFile(string file){
  m_file = file;
}
bool FileError::pass(){
  return (checkFile() == 0);
}
