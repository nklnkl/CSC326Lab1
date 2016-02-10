#include "Data.h"
// Constructor
Data::Data () {
  // Initialize work log values at zero.
  for (int i = 0; i < size; i++) {
    logs[i].code = 0;
    logs[i].comments = 0;
  }
  // Initialize column titles. and padding.
  column1 = "Programmer";
  column2 = "Lines of Code";
  column3 = "Lines of Comments";
  columnPadding = 3;
}

int Data::run (string file) {
  // Buffer for the input stream.
  string line;
  // Reference to the file based on given input 'i';
  ifstream dataFile (file.c_str());
  // A storage for the winner if it is ever declared.
  int winner = 0;

  // When the file stream is available, iterate
  // through its contents and ..
  if (dataFile.is_open()) {
    // Initialize winner to 0 to allow loop to run.
    int winner = 0;
    // Used to remember which column we're in.
    int col = 0;
    // Used to remember which current participant we're working on for the current work log row.
    int index = 0;

    // Loop through the file stream word by word as long as a winner has not been declared.
    while (dataFile >> line && !winner) {

      // Based upon which column we're currently working on.
      switch (col) {

        /* In column 0.
        Set index to keep track of which programmer we're working on for this line.
        Increment col and print out the programmer's number.
        */
        case 0:
          // When we set the index, we need to minus one since the array starts at 0.
          index = atoi(line.c_str()) - 1;
          col++;
          // When we print out the programmer's number, add 1 since the index count was decremented by one as shown above.
          cout << setw(column1.length() + columnPadding) << index + 1;
          break;
        /* In column 1.
        Using the current index, add the new amount of lines to the logs array.
        Increment col and print out the programmer's newest amount of work added.
        */
        case 1:
          logs[index].code += atoi(line.c_str());
          col++;
          cout << setw(column2.length() + columnPadding) << atoi(line.c_str());
          break;
        /* In column 2.
        Using the current index, add the new amount of lines to the logs array.
        Reset the col. Print out the programmer's newest amount of work added.
        If this current programmer's newest sum for lines of code exceeds 1000,
        break out of the loop by declaring winner.
        */
        case 2:
          logs[index].comments += atoi(line.c_str());
          col = 0;
          cout << setw(column3.length() + columnPadding) << atoi(line.c_str()) << endl;
          if (logs[index].code > 1000) {
            winner = index;
          }
          break;
      }
    }
    // Close data file.
    dataFile.close();
    // Return winner, if it was never selected, it should return 0;
    return winner;
  }
}

void Data::header () {
  // Set print alignment to the left;
  cout << left;
  // Print out a column set to the width of its content + extra spaces for padding.
  cout << setw(column1.length() + columnPadding) << column1;
  cout << setw(column2.length() + columnPadding) << column2;
  cout << setw(column3.length() + columnPadding) << column3 << endl;
}

void Data::total () {
  for (int i = 0; i < size; i++) {
    cout << setw(column1.length() + columnPadding) << i + 1;
    cout << setw(column2.length() + columnPadding) << logs[i].code;
    cout << setw(column3.length() + columnPadding) << logs[i].comments << endl;
  }
}

log Data::getLog (int i) {
  return logs[i];
}

int Data::getSize () {
  return size;
}

int Data::getK (int x) {
  // The integer to keep track of our sum as we add each programmer's lines.
  int sum = 0;
  for (int i = 0; i < size; i++) {
    // If the current programmer we're using isn't the one given.
    if (i != x) {
      sum += logs[i].code;
    }
    /* If the sum has surpassed the given programmer's total, break the loop
    by returning this current programmer's index.
    */
    if (sum > logs[x].code) return i;
  }

  /* If we haven't reached a conclusion (which shouldn't happen if this function
  was called after run() with the proper data).
  */
  return 0;
}
