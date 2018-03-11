/* 
  Check by compiling and combining
*/

#include <stdio.h>
#include <math.h>
#include "edge.h"

edge::edge(vertex ver_1,vertex ver_2,bool[][] edge)
{
  v1(ver_1);
  v2(ver_2);
  
}

public::int num; //number of the vertices
edge::bool[][] edge = new bool[num_ver][num_ver] ;
edge::int n = 0;

edge:: void edgeinp()
{
	std::cout <<"Enter the number of all the vertices:"<< endl;
               std::cin>>num;

	std::cout << "Enter the number of edges:" << endl;
	std::cin >> n;
	bool point; // a parameter to define how the input is given
	cout << "Point to point entry?"<<endl;
	cin>>point;
	if (point = true){
	int l = 0;
	while (l < n) {
		int v1 = 0;
		int v2 = 0;
		std::cout << "Enter the first vertex:"<<endl;
		std::cin >> v1;
		std::cout << "Enter the second vertex:"<<endl;
		std::cin >> v2;
		edge[v1][v2] = true;
		edge[v2][v1] = true;
		l++;
	}
	}
	else
	{
	edge=new bool[num][num]
    	for(int i = 0;i<num;i++)
    	{
        	for(int j = 0;j<num;j++)
        	{
            	cin>>edge[i][j]; // Scaning from terminal
        	}
    	} 
	}
}

edge::public: static void main(string[] args){
	//xy
	public::bool[][] xy_edge = new bool[num][num];
	edgeinp();
	xy_edge = edge;
	//yz
	public::bool[][] yz_edge = new bool[num][num];
	edgeinp();
	yz_edge = edge;
	//zx
	public::bool[][] zx_edge = new bool[num][num];
	edgeinp();
	zx_edge = edge;

	// return edge;
}

