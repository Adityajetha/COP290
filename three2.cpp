#include <iostream.h>
#include "vertex.h"
#include "three2.h"
             three2::num=4;
             three2::bool[][] edge = new bool[num][num]; 
             three2::vertex[] ver = new vertex[num];
             three2::bool[][] edge;
             three2::vertexinp(vertex[] v)
             {
               std::cin>>num;
               ///Fuction to take inputs of all the vertices
               ver = new vertex [num]
                for(int i =0;i<num; i++)
                {
                  cin>>ver[i].x;
                  cin>>ver[i].y;
                  cin>>ver[i].z;
                }
             }
             three2::void edgeinp(bool[][] e)
             {
               edge=new bool[num][num]
                 for(int i = 0;i<num;i++)
                 {
                   for(int j = 0;j<num;j++)
                   {
                     cin>>edge[i][j];
                   }
                 }
               
              ///Fuction to take all the edges as input 
             }
             three2::void planeinp(int* a,int* b,int* c)
             {
               cin>>*a;
               cin>>*b;
               cin>>*c;
               ///Function to take the plane as input we want to draw the projection along
             }
             three2::public: static void main(string[] args){
               
             vertexinp(ver);
             edgeinp(edge);
             }
             
                    
                    
