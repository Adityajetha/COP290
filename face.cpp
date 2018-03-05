#include <stdio.h>
#include <math.h>
#include "face.h"

face::face(int num_of_edges,vector<edge> edge_list,bool hidden)
{
  n(num_of_edges);
  l(edge_list);
  b(hidden);
}
