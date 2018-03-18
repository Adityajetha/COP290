#include "vertex.h"
#include <vector>

class edge{
                    public: edge(vertex vert[], bool adj_matri[][]);
                    public: vertex ver[];                       ///ver_1,ver_2 coordinates of vertex
                    public : bool adj_matrix[][]; /// adjacency matrix
                    public: vertex ord[];
  public: vector<vector<vertex>> faces;
  public: vector<vector<vertex>> facelist;
                    public: int solid[][];
                    public: bool iscov(vertex v, vector<vertex> plane);
                    public : bool che_hid(vertex v);///checks if vertex is hidden or not
                    public : void create();
             }; 
