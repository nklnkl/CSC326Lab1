#include "Data.h"

// Constructor
Data::Data () {

  // Initialize work log values at zero.
  for (int i = 0; i < size; i++) {
    logs[i].code = 0;
    logs[i].comments = 0;
  }

}

log Data::getLog (int i) {
  return logs[i];
}

int Data::getSize () {
  return size;
}

int Data::getK() {
  for(int i = size; i)
}

void Data::loadData () {
  // Buffer for the input stream.
  string line;

  // Reference to the file.
  ifstream dataFile ("Data.txt");

  // When the file stream is available, iterate
  // through its contents and ..
  if (dataFile.is_open()) {
    // Used to remember which column we're in.
    int col = 0;
    // Used to remember which current participant we're working on for the current work log row.
    int index = 0;
    // Loop through the file stream word by word.
    while (dataFile >> line) {

      // Based upon which column we're currently working on.
      switch (col) {

        // In column 0,
        case 0:
          // Set the index (current participant) to the value given to us by column 0.
          index = atoi(line.c_str()) - 1;
          // Count to the next column.
          col++;
          break;

        // In column 1,
        case 1:
          // Set the number of code written for the current participant (which is set by index).
          logs[index].code += atoi(line.c_str());
          // Count to the next column.
          col++;
          break;

        // In column 2.
        case 2:
          // Set the number of comments written for the current participant (which is set by index).
          logs[index].comments += atoi(line.c_str());
          // Reset the column count.
          col = 0;
          break;
      }

    }
    // Close data file.
    dataFile.close();
  }
}

int Data::runContest () {
  // Buffer for the input stream.
  string line;

  // Reference to the file.
  ifstream dataFile ("Data.txt");

  // When the file stream is available, iterate
  // through its contents and ..
  if (dataFile.is_open()) {
    // Initialize winner to 0 to allow loop to run.
    int winner = 0;
    // Used to remember which column we're in.
    int col = 0;
    // Used to remember which current participant we're working on for the current work log row.
    int index = 0;
    // Used to determine which row of the data file we're in. Read as "work log entry".
    int row = 1;
    // Loop through the file stream word by word as long as a winner has not been declared.
    while (dataFile >> line && !winner) {

      // Based upon which column we're currently working on.
      switch (col) {

        // In column 0,
        case 0:
          // Set the index (current participant) to the value given to us by column 0.
          index = atoi(line.c_str()) - 1;
          // Count to the next column.
          col++;
          // Render result of this iteration.
          cout << "Programmer #" << index << " submitted ";
          break;

        // In column 1,
        case 1:
          // Set the number of code written for the current participant (which is set by index).
          logs[index].code += atoi(line.c_str());
          // Count to the next column.
          col++;
          // Render result of this iteration.
          cout << atoi(line.c_str()) << " lines of code and ";
          break;

        // In column 2.
        case 2:
          // Set the number of comments written for the current participant (which is set by index).
          logs[index].comments += atoi(line.c_str());
          // Reset the column count.
          col = 0;
          // Render result of this iteration.
          cout << atoi(line.c_str()) << " comments. ";
          // Print total for current programmer.
          cout << "Total so far. Code: " << logs[index].code << ", Comments: " << logs[index].comments << ".\n";
          // Count to next work log.
          row++;
          // Check if this current programmer has exceeded 1000 lines of code.
          if (logs[index].code > 1000) {
            // Break loop by setting winner if it does.
            winner = index;
          }
          break;
      }
    }
    // Close data file.
    dataFile.close();

    // If a winner was ever declared.
    if (winner != 0) {
      cout << "We have a winner!\n" << "Programmer #" << winner << " has reached lines " << logs[index].code << " of code.\n";
      return winner;
    }
    return 0;
  }
}
