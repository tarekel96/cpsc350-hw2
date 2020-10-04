#ifndef FILERROR_H
#define FILERROR_H
#include <iostream>
#include <fstream>
using namespace std;

class FileError{
  private:
    string m_file;
    ifstream m_inFile;
  public:
    FileError();
    FileError(string file);
    ~FileError();
    string getFile();
    int checkFile();
    bool pass();
    // mutators
    void setFile(string file);
};
#endif
