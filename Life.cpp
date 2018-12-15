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
  for(i = row - 1; i <= row + 1; i ++){
    for(j = col - 1; j <= col + 1; j ++){
      // user_says_yes();
      // cout << "row: " << i << ", column: "<< j << endl;
      count += grid[i][j];
    }
  }

  count -= grid[row][col];
  return count; 
}

bool Life::user_says_yes(){
  int c;
  bool initial_response = true;
  do{
    if(initial_response)
      cout << "(y, n)?" << endl;
    else
      cout << "Respond with either y or n: " << endl;
    do{
      c = cin.get();
    } while(c == '\n' || c == ' ' || c == '\t');
    initial_response = false;
  } while(c != 'y' && c!= 'Y' && c != 'n' && c!= 'N');
  return (c == 'y' || c == 'Y');
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
	cout << 'o';
      }
    
    }
    cout << endl;
  }
  cout << endl;
}

void Life::update(){
  int row, col;
  int new_grid[maxrow + 2][maxcol +2];
  for(row = 1; row <= maxrow; row++ ){
    for(col = 1; col <= maxcol; col++){
      switch(neighbor_count(row, col)){
      case 2:
	new_grid[row][col] = grid[row][col];
	break;
      case 3:
	new_grid[row][col] = 1;
	break;
      default:
	new_grid[row][col] = 0;
	break;
      }  
    }
  }
  for(row = 1; row <= maxrow; row++)
    for(col = 1; col <= maxcol; col++){
      grid[row][col] = new_grid[row][col];
    }
}

void Life::init(){
  int row, col;
  for(row = 0; row <= maxrow + 1; row++)
    for(col = 0; col <= maxcol; col++)
      grid[row][col] = 0;
  cout << "List the cooridinates for living cells" << endl;
  cout << "Terminate the list with the special pair -1 -1" << endl;
  cin >> row >> col;
  while(row != -1 || col != -1){
    if(row >= 1 && row <= maxrow)
      if(col >= 1 && col <= maxcol){
	cout << "place at "<< "row: " << row << ", col: " << col << endl;
	grid[row][col] = 1;
      }
      else
	cout << "Column " << col << " is out of range." << endl;
    else
      cout << "Row " << row << " is out of range." << endl;
    cin >> row >> col;
  }
}
