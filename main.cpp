// Data class used to import data from data file.
#include "Data.cpp"
// Needed for console logging.
#include <iostream>

using namespace std;

int main () {

  string fileName;
  cout << "Enter the name of the file: ";
  cin >> fileName;

  // Make room.
  cout << endl;
  cout << fileName << endl;
  // Initialize and load data from file.
  Data data;
  // Print the header.
  data.header();
  // Run the contest and set the winner if found. It will be zero if not.
  int winner = data.run(fileName);
  // Make room.
  cout << endl;
  // Print the header.
  data.header();
  // Print out the totals.
  data.total();
  if (winner) {
    cout << endl << "Programmer " << winner + 1 << " has won the contest." << endl << endl;
    // Get the lowest amount of programmers starting with 1 to match winner's work.
    int k = data.getK(winner);
    if (k) {
      cout << "It took programmers 1 through " << k + 1 << " to produce more than the winner." << endl << endl;
    }
  } else {
    cout  << "No winner was selected for this contest." << endl << endl;
  }
  // Make room.
  cout << endl;

  return 0;
}
