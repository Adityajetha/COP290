#include <GL/glui.h>
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#include <stdio.h>
#include "vertex.h"
#include "face.h"
#include <bits/stdc++.h>

public class two3{
             ///num is the number of vertices
             public: int num;
             ///represents edges
             public: bool[][] adj_matrix;
             ///valid checks is the given orthographic projections are correct
             public: bool valid;
             ///opn selects whether edges are given or not
             public: bool opn; 
             ///array of all the vertices
             public: vertex ver[] = new vertex[num];
             ///Vector of all the faces possible(not all real)
             public: std::vector<face> faces;
             ///takes input from top view
             public: void xy (vertex v, double x, double y);
             ///takes input from side view
             public: bool xz (vertex v, double z, double x);
             /// takes input from front view
             public: bool yz (vertex v, double y, double z);
             ///it takes input from all the views, when opn=0, and gives their intersection
             public: void createedge(bool[][] edge);
             ///it takes inputs from the users to give the edges, in case opn =1
             public: void edgelist(bool[][] edge);
             public: static void main();
             ///makes all the faces
             public: std::vector<face> makeface(int num,vertex[] ver,bool[][] edge);
             ///makes wireframe
             public: std::vector<face> conversion(vertex ver,bool[][] adj_matrix);
             ///removes impossible edges
             public: bool[][] findedgeloops(bool[][] adj);
             ///final step
             public: void create_3D(bool[][] edge,std::vector<face> faces); 
}
