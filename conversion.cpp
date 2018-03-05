#include <stdio.h>
#include"findedgeloops.h"
#include"create_3D.h"
#include"makeface.h"

conversion(ver[],adj_matrix[][]){
  int num_common_vertex;
for each common vertex 
{
  makeface(); // returns face array containing all possible faces formed by edges 
  int num_face;
  face face_list[] = new face[num_face];
  
}
  for each face
  {
    findedgeloops(); 
    for all edge loop 
    {
      adj_matrix[ver_1][ver_2] = false;
    }
  }
  
  create_3D(adj_matrix[][],face_list[]);  
}
