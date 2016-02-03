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

void Data::runContest () {
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
