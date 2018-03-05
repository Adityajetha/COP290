#include <stdio.h>
#include "vertex.h"
#inlude "createedge.h"
#include "edgelist.h"
#include "conversion.h"

public class two3{
             int num;///num is the number of vertices
             bool adj_matrix = new bool[num][num];///represents edges
             bool valid;///valid checks is the given orthographic projections are correct
             bool opn;///opn selects whether edges are given or not 
             vertex ver[] = ver[num];///array of all the vertices
             public static void main(){
             /*
             for each vertex
             {
               xy();
               valid=valid && yz();
               valid=valid && xz();
             } */            
  if(!opn)
    createedge(adj_matrix);///input does not contain the edges
  else
    edgelist(adj_matrix);///input contains the edges
                         ///for each edge adj_matrix[ver_1][ver_2] is true
             }
  
  conversion(ver, adj_matrix); ///makes all the faces
}
