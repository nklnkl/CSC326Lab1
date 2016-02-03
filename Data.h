#ifndef _DATA
#define _DATA

// Needed for data file streaming.
#include <fstream>
// Needed for string -> int casting.
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
    int getSize ();
    void loadData ();
};
#endif
