#include <GL/glui.h>
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
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
             public: std::vector<face> faces;///Vector of all the faces possible(not all real)
             public: void xy (vertex v, double x, double y);///takes input from top view
             public: bool xz (vertex v, double z, double x);///takes input from side view
             public: bool yz (vertex v, double y, double z);/// takes input from front view
             public: static void main();
             public: std::vector<face> conversion(vertex ver,bool[][] adj_matrix); ///makes all the faces
             public: bool[][] findedgeloops(bool[][] adj);///removes impossible edges
             public: void create_3D(bool[][] edge,std::vector<face> faces);///final step 
}
