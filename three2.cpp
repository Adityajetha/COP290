#include <iostream>
#include <string.h>
#include "vertex.h"
#include "three.h"
#include "edge.h"
#include "vector.h"

bool edge::iscov(vertex v, vector<vertex> plane) {
    int n = plane.size();
    bool is = false;
    vertex one = new vertex(plane[0].x,plane[0].y,plane[0].z);
    vertex two = new vertex(plane[1].x,plane[1].y,plane[1].z);
    vertex three = new vertex(plane[2].x,plane[2].y,plane[2].z);
    one = one.sub(two,one);
    two = two.sub(three,two);
    
}



bool edge::che_hid(vertex v){
  
}
void edge::create(){
  ord=ver;
   int i, j;
  vertex key = new vertex(0,0,0);
   for (i = 1; i < n; i++)
   {
       key = ord[i];
       j = i-1;
 
       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= 0 && ord[j].z > key.z)
       {
           ord[j+1] = ord[j];
           j = j-1;
       }
       ord[j+1] = key;
   }
  for(i=0;i<num;i++){
    hid[i]=che_hid(ver[i]);
  }
  for(i=0;i<num;i++){
    for(j=0;j<num;j++){
      if(hid[i]&&hid[j])
        solid[i][j]=0;
      else if((!hid[i])&&(!hid[j]))
        solid[i][j]=1;
      else if(hid[i]&&!hid[j])
        solid[i][j]=2;
      else
        solid[i][j]=3;
  }
  }
}

void three::three(int n){
                         num=n;
                         edge = new bool[n][n];
                        ver = new vertex[n]
                        }
void three::vertexinp()
{
    cin>>num;
    ///Fuction to take inputs of all the vertices
    ver = new vertex [num];
    for(int i =0;i<num; i++)
    {
        std::cin>>ver[i].x>>std::end;
        std::cin>>ver[i].y>>std::end;
        std::cin>>ver[i].z>>std::end;
    }
}
void three::edgeinp()
{
    edge=new bool[num][num];
    for(int i = 0;i<num;i++)
    {
        for(int j = 0;j<num;j++)
        {
            cin>>edge[i][j];
        }
    }

    ///Fuction to take all the edges as input
}
void three::planeinp(double* a,double* b,double* c)
{
    cin>>*a;
    cin>>*b;
    cin>>*c;
    ///Function to take the plane as input we want to draw the projection along
}

void three::createedge(bool edge[][])
{
}

void main(int argc,char* args[]){

    three maino = new three();
    vertexinp();
    edgeinp();
    bool next = false;
    bool nextd = false;
    bool another = true;
    while(!next)
    {
        if(another)
        {
            planeinp();
            for(int i =0;i<num;i++)
            {
                ver[i].rotat(*a,*b,*c);
            }
            ///store/print projection
        }
        std::cin>>nextd>>std::end;
        if(nextd/*next dabaya*/) next=true;
        else next= false;
    }
    /*here give the output*/
}
