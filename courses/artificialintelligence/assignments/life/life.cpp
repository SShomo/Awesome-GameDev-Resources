#include <iostream>
#include <vector>

using namespace std;

int neighbors(vector<bool> vec, int x, int y, int col, int row)
{
  int numNeighbors = 0;

  int north = (col + y - 1) % col;
  int south = (col + y + 1) % col;
  int east = (row + x + 1) % row;
  int west = (row + x - 1) % row;

  if(vec[(north)*row+east])
    numNeighbors++;
  if(vec[(north)*row+west])
    numNeighbors++;
  if(vec[(south)*row+east])
    numNeighbors++;
  if(vec[(south)*row+west])
    numNeighbors++;
  if(vec[((north)*row+x)])
    numNeighbors++;
  if(vec[(south)*row+x])
    numNeighbors++;
  if(vec[(y*row+east)])
    numNeighbors++;
  if(vec[(y*row+west)])
    numNeighbors++;

  return numNeighbors;
}

int main(){
  int col, line, turn;
  cin >> col >> line >> turn;

  vector<bool> grid, tempGrid;
  grid.resize(line*col);

  //fills in the grid
  for(int y = 0; y < line; y++)
  {
    for(int x = 0; x < col; x++)
    {
      char c;
      cin >> c;
      if(c == '#')
        grid[y*col+x] = true;
      else if(c == '.')
        grid[y*col+x] = false;
    }
  }

  for(int i = 0; i < turn; i++)
  {
    tempGrid = grid;
    for(int y = 0; y < line; y++)
    {
      for(int x = 0; x < col; x++)
      {
        bool c = grid[y*col+x];
        int temp = neighbors(grid, x, y, line, col);
        if(c)
        {
          if(temp < 2)
            tempGrid[y*col+x] = false;
          if(temp == 2 || temp == 3)
            tempGrid[y*col+x] = true;
          if(temp > 3)
            tempGrid[y*col+x] = false;
        }
        else
        {
          if(temp == 3)
            tempGrid[y*col+x] = true;
        }
      }
    }
  /*  for(int y =0; y < line; y++) {
      for (int x = 0; x < col; x++) {
        if (grid[y * line + x])
          cout << '#';
        else
          cout << '.';
      }
      cout << "\n";
    }*/
    grid = tempGrid;
  }

  //prints the output
  for(int y =0; y < line; y++) {
    for (int x = 0; x < col; x++) {
      if (grid[y * col + x])
        cout << '#';
      else
        cout << '.';
    }
    cout << "\n";
  }


  return 0;
};