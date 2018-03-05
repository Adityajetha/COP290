#include <stdio.h>
#include "two3.h"

void createedge(bool[][] edge)
{
  int num;///number of vertices
  bool[][] top = new bool[num][num];///edges in top view
  bool[][] front = new bool[num][num];///edges in front view
  bool[][] side = new bool[num][num];///edges in side view
  getedge(top);///gets the edges in top view
  getedge(front);///gets the edges in front view
  getedge(side);///gets the edges in side view
}
