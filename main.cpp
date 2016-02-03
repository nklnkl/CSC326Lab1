// Data class used to import data from data file.
#include "Data.cpp"
// Needed for console logging.
#include <iostream>

using namespace std;

int main () {

  // Initialize and load data from file.
  Data data;
  data.loadData();

  // Loop through data file.
  for (int i = 0; i < data.getSize(); i++) {
    cout << data.getLog(i).code << "\n";
  }

  return 0;
}
