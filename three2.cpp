#include <stdio.h>
#include "vertex.h"
#include "three2.h"


public class three2 {
             int num ////num is the number of vertices
             int a,b,c; ////a,b,c are respectively the x,y and z coefficients of the direction vector perpendicular to the
                        ////plane we want to take the projection about
             vertex ver[] = new vertex[num];
                        ///aray of vertices
             bool edge[][] = new bool[num][num];
                        ///edge[i][j] is true if edge exists between the vertices i,j
             void vertexinp(vertex[] v)
             {
               ///Fuction to take inputs of all the vertices
             }
             void edgeinp(bool[][] e)
             {
              ///Fuction to take all the edges as input 
             }
             void planeinp(int* a,int* b,int* c)
             {
               ///Function to take the plane as input we want to draw the projection along
             }
             public static void main(string[] args){
             vertexinp(ver);
             edgeinp(edge);
             }
             
                    }
                    
