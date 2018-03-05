#include <stdio.h>
#include "vertex.h"
#include <bits/stdc++.h>

public class three2 {
             public : int num; ////num is the number of vertices
             public : int a,b,c; ////a,b,c are respectively the x,y and z coefficients of the direction vector perpendicular to the
                        ////plane we want to take the projection about
             public : vertex ver[] = new vertex[num];
                        ///aray of vertices
             public : bool edge[][] = new bool[num][num];
                        ///edge[i][j] is true if edge exists between the vertices i,j
             public : void vertexinp(vertex[] v)
             {
               ///Fuction to take inputs of all the vertices
             }
             public : void edgeinp(bool[][] e)
             {
              ///Fuction to take all the edges as input 
             }
             public : void planeinp(int* a,int* b,int* c)
             {
               ///Function to take the plane as input we want to draw the projection along
             }
             }
            
                    
