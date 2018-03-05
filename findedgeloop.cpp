#include <stdio.h>
#include<vector>
#include<edge.h>
vector<edge> findedgeloop() 
{
  num_of_edges;
  loop_edge = new vector<edge>;
  for all edge e
  {
   if checkLoop(e)  
   {loop_edge.assign(e);}
    else 
    {continue;}
    //checks if its an edge loop or not
  }
   // fill in all edges that are found to be looped
  return loop_edge;
}

