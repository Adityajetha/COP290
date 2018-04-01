#include <stdio.h>
#include "vertex.h"
#include "createedge.h"
#include "edgelist.h"
#include "two3.h"

class two3 {

public: bool opn;
public: int num;
public: vertex ver[];
public: std::vector<face> facelist;
public: std::vector<face> :: iterator iter;
public: std::vector<face> :: reverse_iterator iter_r;
two3: int num_faces;
public:
    static void main(char *args[]) {
        std::cin >> num >> std::end;
        double temp1,temp2;
        for (int i = 0; i < num; i++) {
            std::cin>>ver[i].x>>ver[i].y>>std::end;
        }
        for (int i = 0; i < num; i++) {
            std::cin>>temp1>>ver[i].z>>std::end;
            if(temp!=ver[i].y){
                ///error
            }
        }
        for (int i = 0; i < num; i++) {
            std::cin >> temp1 >> temp2 >> std::end;
            if (temp1 != ver[i].x && temp2 != ver[i].z) {
                ///error
            }
        }
        for (int i = 0; i < num; i++) {
            xz();
        }

        if (!two3::getopn)
            createedge(edge);///input does not contain the edges
        else
            edgelist(edge);///input contains the edges
        ///for each edge edge[ver_1][ver_2] is true
    }

two3 :: void detectEdge(){
  //How to incorporate hidden lines and edges
  two3:: int num = sizeof(ver)/sizeof(ver[0]); 
  public::bool[][] edge = new bool[num][num]; //Final adjacency matrix.
  //xy_edge, yz_edge, zx_edge
  for(int i =0; i< num; i++){
    for (int j=0; j< num; j++){
      edge[i][j] = xy_edge[i][j] * yz_edge[i][j] * zx_edge[i][j]; //checking if it is 1 in all the adjacency matrix
    }
  }
}

//ver[] is the vertex array and edge[][] is the adjacency matrix. So, we have detected the vertices and the edges

bool two3::checkLoop(int a, int b){ 
 
}
   
void two3::findedgeloop(){
  //finds the edgehoops
  bool[][] edge;
  vertex[] ver;
  sort(ver, ver + num); //sorts the vertices, but check if it will.
  for (int i = 0; i < ver.size(); i++){ 
   for(int j = 0; j < ver.size(); j++){
  {
   if (checkLoop(i,j) ) 
   {
      adj_matrix[i][j] = false; 
   }
    else 
    {continue;}
    //checks if its an edge loop or not
  }
  }

}

two3 :: void makeface(){
  std::vector<vector<vertex>> facelist;
  std::vector<vector<vertex>> :: iterator iter;
  std::vector<vector<vertex>> :: reverse_iterator iter_r;
  int num_faces = facelist.size();
  //finds the faces constructed using the actual edge list and the vertices

}
two3 :: void edgecount(Edge e){ //counts how many times it appears in the vector consisting of faces


}

two3:: void checkface(){ 

  //distinguishes between the real and pseudo elements
  //face is a vector of elements of the face type
  /*1 : When an edge is adjacent to more than two faces, at most two faces can be true.*/
  for(int i =0; i< num; i++){
    for (int j=0; j< num; j++){
      if (edge[i][j]==1) {
        for (int k =0; k < num_faces; k++){
          
        }       
      }
    }
  }

}
 
vector<vector<vertex>>* two3::makeWireframe(Projection myproj, vector<vector<vertex>> ){
///
  ///
  /// Input output taken care by Jetha. Make sure this is compatible.
  ///
        // we have top front side
        vector<vector<vertex>> frame;
    // my projection is the 2D projection.
        myproj.frontview = front;
        myproj.sideview = side;
        myproj.topview = top;
        // frontview is the front view.
        // topview is the top view
        // sideview is the side view
        frame = myproj.create3D();
        vector<vector<vertex>>* retFrame;
        retFrame = new vector<vector<vertex>>();
        
}

two3:: void isometricview(){
  //produce using 3D description an isometric drawing from any view direction
  /////
}

}
