#include <iostream>
#include <fstream>

using namespace std;

#include "grid.h"

// You do not need to alter function indexof.
int grid::indexof (int row, int col) const {
  return row*cols+col;
}

// You do not need to alter function infected.
bool grid::infected(int row, int col) const {
  return (area->operator[](indexof(row, col)) == INFECTED);
}

// Checks if the cell was visited
bool grid::visited(int row, int col) const {
  return ((*visits)[indexof(row, col)] == true);
}

// You may need to alter the constructor
grid::grid (string file) {
  
  ifstream grid_file;

  grid_file.open (file.c_str());

  grid_file >> rows;
  grid_file >> cols;

  area = new vector<bool>(rows*cols, NOT_INFECTED);

  // Initializing
  visits = new vector<bool>(rows * cols, NOT_VISITED);

  while (true) { 
  
    int blob_row;
    int blob_col;

    grid_file >> blob_row;  
    grid_file >> blob_col;  

    if (grid_file.eof()) {
        break;
    }

    area->operator[](indexof(blob_row,blob_col)) = INFECTED;
  }
  
  grid_file.close();
}

// You may need to alter the destructor
grid::~grid () {
  delete area;

  // Clearing memory
  delete visits;
}

// You will need to alter this function to display the
// plus signs (+) next to the cells that belong to
// a counted colony.
ostream &operator<<(ostream &stream, const grid& ob) {

  for (int row=0; row < ob.rows; row++) { 
    
    for (int col=0; col < ob.cols; col++) {

		stream << ob.area->operator[](ob.indexof(row, col));

		// Printing that we counted this cell
		if (ob.visited(row, col)) {
			stream << "+  ";
		}
		else {
			stream << "   ";
		}
    }

    stream << endl;
  }

  stream << endl;
  return stream;
}

// Replace the return statement in this function with your
// recursive implementation of this method */
int grid::count (int row, int col) {

	// Checking for cell existence
	if (row < 0 || col < 0 || row >= rows || col >= cols) {
		return 0;
	}

	// Checking for infection or if it was visited
	if (!infected(row, col) || visited(row, col)) {
		return 0;
	}

	// Marking it
	visits->operator[](indexof(row, col)) = VISITED;

	// Checking all 8 neighbours and incrementing the counter for this cell
    return count(row - 1, col - 1) + count(row - 1, col) + count (row - 1, col + 1) + 
		count (row, col + 1) + count (row + 1, col + 1) + count (row + 1, col) + 
		count(row + 1, col - 1) + count (row, col - 1) + 1;
}


