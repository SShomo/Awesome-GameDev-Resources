#ifndef CAT_h
#define CAT_h
#include "IAgent.h"

struct Cat : public IAgent {
  std::pair<int,int> move(const std::vector<bool>& world, std::pair<int,int> catPos, int sideSize ) override{
    std::vector<std::pair<int,int>> newPos;
    int half = sideSize/2;
    int px = (half + catPos.first);
    int py = (half + catPos.second);
    int north = (half + catPos.second - 1);
    int south = (half + catPos.second + 1);
    int east = (half + catPos.first + 1);
    int west = (half + catPos.first - 1);

    if(py % 2 == 1)
    {
      if(!world[(north)*sideSize+east])
        newPos.emplace_back(catPos.first+1, catPos.second-1);
        //newPos.emplace_back(east, north);
      if(!world[(north)*sideSize+px])
        newPos.emplace_back(catPos.first, catPos.second-1);
        //newPos.emplace_back(px, north);
      if(!world[(py)*sideSize+east])
        newPos.emplace_back(catPos.first+1, catPos.second);
        //newPos.emplace_back(east, py);
      if(!world[(south)*sideSize+east])
        newPos.emplace_back(catPos.first+1, catPos.second+1);
        //newPos.emplace_back(east, south);
      if(!world[(south)*sideSize+px])
        newPos.emplace_back(catPos.first, catPos.second+1);
        //newPos.emplace_back(px, south);
      if(!world[(py)*sideSize+west])
        newPos.emplace_back(catPos.first-1, catPos.second);
        //newPos.emplace_back(west, py);
    }
    if(py % 2 == 0)
    {
      if(!world[(north)*sideSize+west])
        newPos.emplace_back(catPos.first-1, catPos.second-1);
        //newPos.emplace_back(west, north);
      if(!world[(north)*sideSize+px])
        newPos.emplace_back(catPos.first, catPos.second-1);
        //newPos.emplace_back(px, north);
      if(!world[(py)*sideSize+east])
        newPos.emplace_back(catPos.first+1, catPos.second);
        //newPos.emplace_back(east, py);
      if(!world[(south)*sideSize+px])
        newPos.emplace_back(catPos.first, catPos.second+1);
        //newPos.emplace_back(px, south);
      if(!world[(south)*sideSize+west])
        newPos.emplace_back(catPos.first-1, catPos.second+1);
        //newPos.emplace_back(west, south);
      if(!world[(py)*sideSize+west])
        newPos.emplace_back(catPos.first-1, catPos.second);
        //newPos.emplace_back(west, py);
    }
    return newPos.back();
  }
};

#endif