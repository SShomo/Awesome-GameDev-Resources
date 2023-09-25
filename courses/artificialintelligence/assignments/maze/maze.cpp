#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

struct node{
  bool vert:1;
  bool hor:1;
  bool visit;
};

int main(){
  int rand[] = {72, 99, 56, 34, 43, 62, 31, 4, 70, 22, 6, 65, 96, 71, 29, 9, 98, 41, 90,
7, 30, 3, 97, 49, 63, 88, 47, 82, 91, 54, 74, 2, 86, 14, 58, 35, 89, 11, 10, 60, 28, 21,
52, 50, 55, 69, 76, 94, 23, 66, 15, 57, 44, 18, 67, 5, 24, 33, 77, 53, 51, 59, 20, 42, 80,
61, 1, 0, 38, 64, 45, 92, 46, 79, 93, 95, 37, 40, 83, 13, 12, 78, 75, 73, 84, 81, 8, 32, 27,
19, 87, 85, 16, 25, 17, 68, 26, 39, 48, 36};

  vector<node> maze;
  unsigned int col, row, index;
  cin >> col >> row >> index;
  maze.resize(row*col);

  for(int x = 0; x <= col; x++)
  {
    for(int y = 0; y <= row; y++)
    {
      maze[y*col+x].vert = false;
      maze[y*col+x].hor = true;
      //maze[(((y*col+x)+1)*2)+1] = '|';
    }
  }

  for(int x = 0; x <= col; x++)
  {
    for(int y = 0; y <= row; y++)
    {
      //cout << maze[y*col+x].vert <<  maze[y*col+x].hor;
      if(!maze[y*col+x].vert)
        cout << "|";
      if( maze[y*col+x].hor)
        cout << "_";
    }
    cout << endl;
  }

  return 0;
}