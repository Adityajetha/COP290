#include <stdio.h>
#include "vertex.h"
#include "face.h"
#include <bits/stdc++.h>

public class two3{
             public: int num;///num is the number of vertices
             public: bool[][] adj_matrix///represents edges
             public: bool valid;///valid checks is the given orthographic projections are correct
             public: bool opn;///opn selects whether edges are given or not 
             public: vertex ver[] = new vertex[num];///array of all the vertices
             public: std::vector<face> faces;///Vector of the faces
             public: static void main();
             public: std::vector<face> conversion(vertex ver,bool[][] adj_matrix); ///makes all the faces
             public: bool[][] findedgeloops(bool[][] adj);///removes impossible edges
             public: void create_3D(bool[][] edge,std::vector<face> faces);///final step 
}
