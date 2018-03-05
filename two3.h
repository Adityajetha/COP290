#include <stdio.h>
#include "vertex.h"
#include "face.h"
#include <bits/stdc++.h>

public class two3{
             int num;///num is the number of vertices
             bool[][] adj_matrix///represents edges
             bool valid;///valid checks is the given orthographic projections are correct
             bool opn;///opn selects whether edges are given or not 
             vertex ver[] = new vertex[num];///array of all the vertices
             std::vector<face> faces;///Vector of the faces
             public: static void main();
             std::vector<face> conversion(vertex ver,bool[][] adj_matrix); ///makes all the faces
             bool[][] findedgeloops(bool[][] adj);///removes impossible edges
             void create_3D(bool[][] edge,std::vector<face> faces);///final step 
}
