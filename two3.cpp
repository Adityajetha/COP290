//
// Created by Aditya Jetha on 10-03-2018.
//

#include <stdio.h>
#include "vertex.h"
#include "createedge.h"
#include "edgelist.h"
#include "two3.h"

class two3 {

public: bool opn;
public: int num;
public: vertex ver[];
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
            createedge(adj_matrix);///input does not contain the edges
        else
            edgelist(adj_matrix);///input contains the edges
        ///for each edge adj_matrix[ver_1][ver_2] is true
    }

public: void conversion(vertex ver[],bool edges[][]){
        int num_common_vertex;
        bool adj_matrix[][];
        std::vector<face> faces;
    } ///makes all the faces
};
