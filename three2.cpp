#include <iostream>
#include <string.h>
#include "vertex.h"
#include "three.h"
#include "edge.h"
#include <vector>

int edge::countIntersections(Vector3d avertice,Vector3d bvertice,Vector3d dvertice,Vector3d evertice,Vector3d linevector){
    int retValue = 0;
    vertex abvector = bvertice - avertice;
    vertex acvector = linevector;
    vertex advector = dvertice - avertice;
    vertex aevector = evertice - avertice;
    vertex t1 = abvector.cross(abvector,acvector);
    vertex t2 = advector.cross(advector,acvector);
    vertex t3 = abvector.cross(abvector,advector);
    vertex t6 = aevector.cross(aevector,acvector);
    double t4 = t1.dot(t2);
    double t5 = t1.dot(t3);
    double t7 = t6.dot(t2);
    double abdotac = abvector.dot(acvector);
    if((t1.x==0&&t1.y==0&&t1.z==0) || (t2.x==0&&t2.y==0&&t2.z==0)){
        // Do Nothing
    }else if((t4<=0) && (t5>=0)){
        retValue = 1;
    }
    if((t1.x==0&&t1.y==0&&t1.z==0) && abdotac>0){
        if(t7<=0)
            retValue = 2;
        else
            retValue = 3;
    }
    return retValue;
}

bool edge::iscov(vertex v, vector<vertex> plane) {
    int n = plane.size();
    
    for(int i = 0; i < n; i++) {
        if(v.x==plane[i].x && v.y==plane[i].y  && v.z==plane[i].z )
            is = true;
    }
    if(is)
        return is;
    vertex ver0 = new vertex(v.x,v.y,v.z);
    int ni = 0;
  

  vertex zerovector= new vertex(0,0,0);
    vertex icap = new vertex(1,0,0);
    vertex jcap = new vertex(0,1,0);
    bool is = false;
    vertex one = new vertex(plane[0].x,plane[0].y,plane[0].z);
    vertex two = new vertex(plane[1].x,plane[1].y,plane[1].z);
    vertex three = new vertex(plane[2].x,plane[2].y,plane[2].z);
    one = one.sub(two,one);
    two = two.sub(three,two);
    one = one.cross(one,two);
    two = one.cross(one,vertex(1,0,0));

    double checkzero = linevector.dot(linevector);
    if(checkzero==0){
        linevector = perpendicular.cross(jcap);
    }
    // Vector3d linevector(1,1,0);
    int i=0;
    for(int j=0;j<n;j++){
        vertex vert = plane.get(j);
        vertex nex,pre;
        if(j==n-1){
            pre = plane.get(j-1);
            nex = plane.get(0);
        }else if(j==0){
            pre = plane.get(n-1);
            nex = plane.get(1);
        }else{
            pre = plane.get(j-1);
            nex = plane.get(j+1);
        }
        //Point nextone = *(it + 1);
        vertex ver1= new vertex(vert.x,vert.y,vert.z);
        vertex verp= new vertex(pre.x,pre.y,pre.z);
        vertex vern= new vertex(nex.x,nex.y,nex.z);
        int ci = countIntersections(ver0,vert,nex,pre,linevector);
        if(ci==0){
            // Do Nothing
        }else if(ci==1 || ci==2){
            ni = ni +1;
        }else if(ci==3){
            ni = ni + 2;            
        }
        i++;
    }
    // cout<< "numintersections is "<< numintersections<<endl;
    if(ni%2==1){
        return true;
    }else{
        return false;
    }
    
}



void edge::cre_hid(){
    for(i=0;i<n;i++){
      for(j=0;j<num_faces;j++){
          if(iscov(ver[i],facelist.get(j)){
             hid[i]=true; break;}
      }
  }
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
    che_hid();
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
                        ver = new vertex[n];
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
