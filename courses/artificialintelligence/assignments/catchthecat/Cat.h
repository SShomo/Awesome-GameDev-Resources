#ifndef CAT_h
#define CAT_h
#include "IAgent.h"

struct Cat : public IAgent {
  std::pair<int,int> move(const std::vector<bool>& world, std::pair<int,int> catPos, int sideSize ) override{
    return {0,0}; // todo: change this
  }
};

std::pair<int,int> move(const std::vector<bool>& world, std::pair<int,int> catPos, int sideSize )
{
  std::pair<int,int> newPos;
  int px = (sideSize + catPos.first) % sideSize;
  int py = (sideSize + catPos.second) % sideSize;
  int north = (sideSize + catPos.second) % sideSize;
  int south = (sideSize + catPos.second) % sideSize;
  int east = (sideSize + catPos.first + 1) % sideSize;
  int west = (sideSize + catPos.first - 1) % sideSize;

  if(py % 2 == 1)
  {
    if(world.at())
    if(world.Get(Point2D(px, north)))
      neighbors++;
    if(world.Get(Point2D(east, north)))
      neighbors++;
    if(world.Get(Point2D(east, py)))
      neighbors++;
    if(world.Get(Point2D(east, south)))
      neighbors++;
    if(world.Get(Point2D(px, south)))
      neighbors++;
    if(world.Get(Point2D(west, py)))
      neighbors++;
  }
  if(py % 2 == 0)
  {
    if(world.Get(Point2D(west, north)))
      neighbors++;
    if(world.Get(Point2D(px, north)))
      neighbors++;
    if(world.Get(Point2D(east, py)))
      neighbors++;
    if(world.Get(Point2D(px, south)))
      neighbors++;
    if(world.Get(Point2D(west, south)))
      neighbors++;
    if(world.Get(Point2D(west, py)))
      neighbors++;
  }
  return newPos;
}
#endif