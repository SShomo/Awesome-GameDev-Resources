#include <iostream>
#include <vector>

using namespace std;

int neighbors(vector<bool> vec, int x, int y, int row, int col)
{
  int numNeighbors = 0;
  col = col-1;
  if(x != col && vec[(y)*row+(x+1)])
    numNeighbors++;
  if(y != col && vec[(y+1)*row+x])
    numNeighbors++;
  if(x != col && y != col && vec[(y+1)*row+(x+1)])
    numNeighbors++;
  if(y != 0 && vec[(y-1)*row+x])
    numNeighbors++;
  if(x != 0 && vec[y*row+(x-1)])
    numNeighbors++;
  if(y != 0 && x != 0 && vec[(y-1)*row+(x-1)])
    numNeighbors++;
  if(y != col && x != 0 && vec[(y+1)*row+(x-1)])
    numNeighbors++;
  if(x != col && y != 0 && vec[(y-1)*row+(x+1)])
    numNeighbors++;

  return numNeighbors;
}

int main(){
  int col, line, turn;
  cin >> col >> line >> turn;

  vector<bool> grid, tempGrid;
  grid.resize(line*col);

  for(int y = 0; y < line; y++)
  {
    for(int x = 0; x < col; x++)
    {
      char c;
      cin >> c;
      if(c == '#')
        grid[y*line+x] = true;
      else if(c == '.')
        grid[y*line+x] = false;
    }
  }

  for(int i = 0; i < turn; i++)
  {
    tempGrid = grid;

    for(int y = 0; y < line; y++)
    {
      for(int x = 0; x < col; x++)
      {
        bool c = grid[y*line+x];
        int temp = neighbors(grid, x, y, line, col);
        if(c)
        {
          if(temp < 2)
            tempGrid[y*line+x] = false;
          if(temp == 2 || temp == 3)
            tempGrid[y*line+x] = true;
          if(temp > 3)
            tempGrid[y*line+x] = false;
        }
        else
            if(temp == 3)
          tempGrid[y*line+x] = true;
      }
    }
    grid = tempGrid;
  }

  for(int y =0; y < line; y++) {
    for (int x = 0; x < col; x++) {
      if (grid[y * line + x])
        cout << '#';
      else
        cout << '.';
    }
    cout << "\n";
  }


  return 0;
};