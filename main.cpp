// Data class used to import data from data file.
#include "Data.cpp"
// Needed for console logging.
#include <iostream>

using namespace std;

int main () {

  cout << "\n\n";

  // Initialize and load data from file.
  Data data;
  int result = data.runContest();

  // If there is a winner
  if (result != 0) {

    // Print the table.
    cout << "\nResults\n";
    for (int i = 0; i < data.getSize(); i++) {
      // Print the current programmer.
      cout << "Programmer #" << i+1 << ", code: " << data.getLog(i).code << ", comments: " << data.getLog(i).comments << ". ";
      // Flag winner if possible.
      if (i == result) cout << "<<<WINNER\n";
      // Otherwise go to next line.
      else cout << "\n";
    }

    // Run the smallest k function;
  }

  return 0;
}
