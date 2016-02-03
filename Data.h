#ifndef _DATA
#define _DATA

#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct log {
  int code;
  int comments;
};

class Data {
  private:
    int static const size = 10;
    log logs[size];
  public:
    Data ();
    log getLogs ();
    void loadData ();
};
#endif
