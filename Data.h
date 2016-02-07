#ifndef _DATA
#define _DATA

// Needed for data file streaming.
#include <fstream>
// Needed for string -> int casting.
#include <stdlib.h>
// Needed for console output.
#include <iostream>
#include <string>
// Needed for output formatting.
#include <iomanip>

using namespace std;

struct log {
  int code;
  int comments;
};

class Data {
  private:
    // The amount of programmers.
    int static const size = 10;
    // Struct used to hold sums of lines for each programmer.
    log logs[size];
    // The titles for each column.
    string column1;
    string column2;
    string column3;
    // The amount of padding between each column.
    int columnPadding;
  public:
    Data();
    // Runs the contest.
    int run();
    // Prints the header.
    void header();
    // Prints out the totals.
    void total();
    // Gets the single struct element from the logs array.
    log getLog(int);
    // Gets the size of the array.
    int getSize();
    /*
      Returns the amount of programmers needed starting from 0 to match a given
      programmer's lines of code written. Returns 0 if never matched.
    */
    int getK(int);
};

#endif
