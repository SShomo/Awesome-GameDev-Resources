#include <iostream>
#include <vector>

using namespace std;

int neighbors(vector<bool> vec, int x, int y, int row)
{
  int numNeighbors = 0;

  if(x !=vec.size() && vec[(y)*row+(x+1)])
    numNeighbors++;
  if(y !=vec.size() && vec[(y+1)*row+x])
    numNeighbors++;
  if(x !=vec.size() && y !=vec.size() && vec[(y+1)*row+(x+1)])
    numNeighbors++;
  if(y != 0 && vec[(y-1)*row+x])
    numNeighbors++;
  if(x != 0 && vec[y*row+(x-1)])
    numNeighbors++;
  if(y != 0 && x != 0 && vec[(y-1)*row+(x-1)])
    numNeighbors++;
  if(y !=vec.size() && x != 0 && vec[(y+1)*row+(x-1)])
    numNeighbors++;
  if(x !=vec.size() && y != 0 && vec[(y-1)*row+(x+1)])
    numNeighbors++;



  return numNeighbors;
}

int main(){
  int col, line, turn;
  cin >> col >> line >> turn;

  vector<bool> grid, tempGrid;
  grid.resize(line*col);

  for(int y =0; y < col; y++)
  {
    for(int x = 0; x < col; x++)
    {
      char c;
      cin >> c;
      if(c == '.')
        grid[y*line+x] = false;
      else
        grid[y*line+x] = true;
    }
  }

  tempGrid = grid;
  for(int y =0; y < col; y++)
  {
    for(int x = 0; x < col; x++)
    {
      bool c = grid[y*line+x];

      if(c)
      {
        int temp = neighbors(grid, x, y, line);
        if(temp < 2)
          tempGrid[y*line+x] = false;
        if(temp == 2 || temp == 3)
        {
          tempGrid[(y-1)*line+(x-1)] = true;
          tempGrid[y*line+x] = false;
        }
        if(temp == 3)
          tempGrid[y*line+x] = true;
        if(temp > 3)
          tempGrid[y*line+x] = false;
      }
    }
  }

  for(int y =0; y < col; y++) {
    for (int x = 0; x < col; x++) {
      cout << tempGrid[y*line+x] << " ";
    }
    cout << endl;
  }

  return 0;
};

