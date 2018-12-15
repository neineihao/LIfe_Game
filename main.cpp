#include<iostream>
#include "Life.h"
//#include "Life.c"
using namespace std;

//typedef int bool;
//const bool false = 0;
//const bool true = 1;

void instructions(){
  cout << "Welcome to Conway's game of Life." << endl;
  cout << "This is a grid of size "
       << maxrow << " by " << maxcol << " in which" << endl;
  cout << "each cell can either be occupied by an organism or not." << endl;
  cout << "The occupied cells change from generation to generation" << endl;
  cout << "accroding to the number of neighboring cells which are alive."
       << endl;
}




void neighbor_number(Life lifeobj){
  int row, col;
  for(row = 1; row <=maxrow; row++){
    for(col = 1; col <=maxcol; col++){
      cout << lifeobj.neighbor_count(row,col) << " ";
    }
  }
}


int main(){
  bool wait_continue = true;
  instructions();
  Life configuration;
  configuration.init();
  do{
    configuration.print();
    configuration.update();
    wait_continue = configuration.user_says_yes(); 
    // neighbor_number(configuration);
  } while(wait_continue == true);    
}
