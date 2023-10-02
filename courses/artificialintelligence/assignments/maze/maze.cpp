#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <stack>

using namespace std;

struct node{
  bool visit = false;
  bool vert:1;
  bool hor:1;
};
vector<char> neighbors(const vector<node> vec, int x, int y, int col, int row){
  vector<char> numNeighbors; //Checks if the neighbors have been visited
  if(y > 0) //up
    if(!vec[((y - 1)*col+x)].visit)
      numNeighbors.push_back('u');
  if(y*col+(x+1) < row*col) //right
    if(!vec[y*col+(x + 1)].visit)
      numNeighbors.push_back('r');
  if((y+1)*col+x < row*col)//down
    if(!vec[(y + 1)*col+x].visit)
      numNeighbors.push_back('d');
  if(x > 0)//left
    if(!vec[(y*col+(x - 1))].visit)
      numNeighbors.push_back('l');
  return numNeighbors;
}

int main(){
  int rand[] = {72, 99, 56, 34, 43, 62, 31, 4, 70, 22, 6, 65, 96, 71, 29, 9, 98, 41, 90,
7, 30, 3, 97, 49, 63, 88, 47, 82, 91, 54, 74, 2, 86, 14, 58, 35, 89, 11, 10, 60, 28, 21,
52, 50, 55, 69, 76, 94, 23, 66, 15, 57, 44, 18, 67, 5, 24, 33, 77, 53, 51, 59, 20, 42, 80,
61, 1, 0, 38, 64, 45, 92, 46, 79, 93, 95, 37, 40, 83, 13, 12, 78, 75, 73, 84, 81, 8, 32, 27,
19, 87, 85, 16, 25, 17, 68, 26, 39, 48, 36};

  vector<node> maze;
  stack<node> mazeStack;

  unsigned int col, row, index;
  cin >> col >> row >> index;
  maze.resize(row*col);

  //initial maze box generation (All walls are up)
  for(int y = 0; y < col; y++)
  {
    for(int x = 0; x < row; x++) {
      maze[y * col + x].vert = true;
      maze[y * col + x].hor = true;
    }
  }

  //Add the top left cell to the stack;
  int tempX = 0, tempY = 0;
  mazeStack.push( maze[tempY * col + tempX]);
  while(!mazeStack.empty()){
    vector<char> numNeigh = neighbors(maze,tempX, tempY, col, row);
    if(!numNeigh.empty()){  //if  the stack top cell has visitable neighbors
      maze[tempY * col + tempX].visit = true; //Mark the top cell as visited;
      if(numNeigh.size() == 1){
        if(numNeigh[0] == 'u'){
          tempY -= 1;
          maze[tempY*col+tempX].hor = false;
          mazeStack.push(maze[(tempY)*col+tempX]);
        }
        else if(numNeigh[0] == 'd'){
          maze[tempY*col+tempX].hor = false;
          tempY += 1;
          mazeStack.push(maze[(tempY)*col+tempX]);
        }
        else if (numNeigh[0] == 'l'){
          tempX -= 1;
          maze[tempY*col+tempX].vert = false;
          mazeStack.push(maze[tempY*col+(tempX)]);
        }
        else if(numNeigh[0] == 'r'){
          maze[tempY*col+tempX].vert = false;
          tempX += 1;
          mazeStack.push(maze[tempY*col+(tempX)]);
        }
      }
      if(numNeigh.size() > 1){
        int temp = rand[index] % numNeigh.size();
        index++;
        if(index > 99)
          index = 0;

        if(numNeigh[temp] == 'u'){
          tempY -= 1;
          maze[tempY*col+tempX].hor = false;
          mazeStack.push(maze[(tempY)*col+tempX]);
        }
        if(numNeigh[temp] == 'r'){
          maze[tempY*col+tempX].vert = false;
          tempX += 1;
          mazeStack.push(maze[tempY*col+(tempX)]);
        }
        if(numNeigh[temp] == 'd'){
          maze[tempY*col+tempX].hor = false;
          tempY += 1;
          mazeStack.push(maze[(tempY)*col+tempX]);
        }
        if(numNeigh[temp] == 'l'){
          tempX -= 1;
          maze[tempY*col+tempX].vert = false;
          mazeStack.push(maze[tempY*col+(tempX)]);
        }
      }
    }
    else{ mazeStack.pop(); }//Remove the top cell from the stack, backtracking
  }
  // prints out the final maze
  for(int i = 0; i < col; i++)
    cout << " _";
  cout << "  " << endl;
  for(int y = 0; y < col; y++){
    cout << "|";
    for(int x = 0; x < row; x++){
      cout <<(maze[y*col+x].hor ? "_" : " ") << (maze[y*col+x].vert ? "|" : " ");
    }
    cout << " \n";
  }
  return 0;
}