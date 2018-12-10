#ifndef LIFE_H_
#define LIFE_H_

const int maxrow =20, maxcol = 60;

class Life{
 public:
  void init();
  void print();
  void update();
  int neighbor_count(int row, int col);
 private:
  int grid[maxrow + 2][maxcol + 2];

};

#endif
