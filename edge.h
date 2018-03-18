#include "vertex.h"
#include <string.h>
#include <vector>

class edge{
  public: int num;
                    public: edge(string file);
                    public: vertex* ver[num];                       ///ver_1,ver_2 coordinates of vertex
                    public : bool adj_matrix[num][num]; /// adjacency matrix
                    public: vertex* ord[num];
  public: vector<vector<vertex>> facelist;
                    public: int solid[][];
                    public: bool iscov(vertex v, vector<vertex> plane);
                    public : bool che_hid(vertex v);///checks if vertex is hidden or not
                    public : void create();
             }; 
