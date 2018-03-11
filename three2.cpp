#include <iostream>
#include <string.h>
#include "vertex.h"
#include "three2.h"
three2::num=4;
three2::edge = new bool[num][num];
three2::ver = new vertex[num];
three2::edge;
three2::vertexinp()
{
    std::cin>>num;
    ///Fuction to take inputs of all the vertices
    ver = new vertex [num];
    for(int i =0;i<num; i++)
    {
        std::cin>>ver[i].x>>std::end;
        std::cin>>ver[i].y>>std::end;
        std::cin>>ver[i].z>>std::end;
    }
}
three2::edgeinp()
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
three2::planeinp(double* a,double* b,double* c)
{
    cin>>*a;
    cin>>*b;
    cin>>*c;
    ///Function to take the plane as input we want to draw the projection along
}
three2::main(char* args){

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
