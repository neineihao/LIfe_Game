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

bool user_says_yes(){
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
    neighbor_number(configuration);
    wait_continue = user_says_yes();
  } while(wait_continue == true);    
}
