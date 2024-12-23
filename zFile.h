#ifndef ZFILE_H
#define ZFILE_H

#include "zenote.h"

class zFile {
  public:
    void writeToFile(); //add .zn suffix
  private:
    FILE *fp;
    zenote zn;
}

#endif ZFILE_H
