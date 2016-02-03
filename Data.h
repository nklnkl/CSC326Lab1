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
    log getLog (int);
    int getSize ();
    // Used to load data to logs. Does not monitor or console print anything.
    // Does not stop if a winner is decided, made this to prototype the actual
    // run contest() method.
    void loadData ();
    void runContest();
};
#endif
