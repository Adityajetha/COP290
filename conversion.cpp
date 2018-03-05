#include <stdio.h>
#include"findedgeloops.h"
#include"create_3D.h"
#include"makeface.h"

conversion(vertex[],bool[][]){
  int num_common_vertex;
  bool[][] adj_matrix;
for each common vertex 
{
  makeface(); // returns face array containing all possible faces formed by edges 
  int num_face;
  face face_list[] = new face[num_face];
  
}
  for each face
  {
    findedgeloops(adj_matrix[][]); 
  }
  
  create_3D(adj_matrix[][],face_list[]);  
}
