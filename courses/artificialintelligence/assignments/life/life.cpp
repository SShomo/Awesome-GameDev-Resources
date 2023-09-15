#include <iostream>
#include <vector>

using namespace std;

int neighbors(vector<vector<bool>> vec, int y, int x, int row, int col)
{
  int numNeighbors = 0;
  //col = col-1;

  if(x != col && vec[x+1][y])
    numNeighbors++;
  if(y != row && vec[x][y+1])
    numNeighbors++;
  if(x != col && y != row && vec[x+1][y+1])
    numNeighbors++;
  if(y != 0 && vec[x][y-1])
    numNeighbors++;
  if(x != 0 && vec[x-1][y])
    numNeighbors++;
  if(y != 0 && x != 0 && vec[x-1][y-1])
    numNeighbors++;
  if(y != row && x != 0 && vec[x-1][y+1])
    numNeighbors++;
  if(x != col && y != 0 && vec[x+1][y-1])
    numNeighbors++;

  return numNeighbors;
}

int main(){
  int col, line, turn;
  cin >> col >> line >> turn;

  vector<vector<bool>> grid(line, vector<bool>(col));
  vector<vector<bool>> tempGrid;

  for(int y = 0; y < line; y++)
  {
    for(int x = 0; x < col; x++)
    {
      char c;
      cin >> c;
      if(c == '#')
        grid[y][x] = true;
      else if(c == '.')
        grid[y][x] = false;
    }
  }

  for(int i = 0; i < turn; i++)
  {
    tempGrid = grid;

    for(int y = 0; y < line; y++)
    {
      for(int x = 0; x < col; x++)
      {
        bool c = grid[y][x];
        cout << c;
        int temp = neighbors(grid, x, y, line, col);
        if(c)
        {
          if(temp < 2)
            tempGrid[y][x] = false;
          if(temp == 2 || temp == 3)
            tempGrid[y][x] = true;
          if(temp > 3)
            tempGrid[y][x] = false;
        }
        else
          if(temp == 3)
            tempGrid[y][x] = true;
      }
      cout << endl;
    }
    grid = tempGrid;
  }

  for(int y =0; y < line; y++) {
    for (int x = 0; x < col; x++) {
      if (grid[y][x])
        cout << "#";
      else
        cout << ".";
    }
    cout << endl;
  }


  return 0;
};

