class vertex{
                    public: vertex(double xt, double yt, double zt);
                    public: double x,y,z;                       ///x,y,z, coordinates of vertex
                    public: void rotat(double aq,double bq,double cq); ///To rotate the vertex for 3D to 2D projection.
                    public: vertex cross(vertex v,vertex u);
                    public: vertex sub(vertex v, vertex u);
             };       
