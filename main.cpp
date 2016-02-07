// Data class used to import data from data file.
#include "Data.cpp"
// Needed for console logging.
#include <iostream>

using namespace std;

int main () {

  // Make room.
  cout << endl;

  // Initialize and load data from file.
  Data data;

  // Print the header.
  data.header();

  // Run the contest and set the winner if found. It will be zero if not.
  int winner = data.run();
  if (winner) {
    cout << endl << "Programmer " << winner + 1 << " has won the contest." << endl << endl;
  } else {
    cout  << "No winner was selected for this contest." << endl << endl;
  }

  // Print the header.
  data.header();
  // Print out the totals.
  data.total();

  // Make room.
  cout << endl;

  return 0;
}
