#include "Life.h"
#include <iostream>

using namespace std;

int Life::neighbor_count(int row, int col){
  /* Pre: The Life object contains a configuration, and the coordinates row and col defines 
     a cell inside its hedge
     Pro: The number of living neighbors of the specified cell is returne
  */
  int i, j;
  int count = 0;
  for(i = row - 1; i <= row + 1; row ++){
    for(j = col -1; j <= col + 1; col ++){
      count += grid[i][j];
    }
  }
  count -= grid[row][col];
  return count; 
}

void Life::print(){
  int row, col;
  cout << "\nThe current Life configuration is." << endl;
  for(row = 1; row <= maxrow; row++){
    for(col =1; col <= maxcol; col++){
      if(grid[row][col] == 1){
	cout << '*';
      }
      else{
	cout << ' ';
      }
    
    }
    cout << endl;
  }
  cout << endl;
}

void Life::update(){
  int row, col;
  int new_grid[maxrow + 2][maxcol +2];
  for(row = 1; row <= maxrow; row++ )
    for(col = 1; col <= maxcol; col++){
      switch(neighbor_count(row, col)){
      case2:
	new_grid[row][col] = grid[row][col];
	break;
      case3:
	new_grid[row][col] = 1;
	break;
      default:
	new_grid[row][col] = 0;
      }  
    }
  for(row = 1; row <= maxrow; row++)
    for(col = 1; col <= maxcol; col++){
      grid[row][col] = new_grid[row][col];
    }
}

