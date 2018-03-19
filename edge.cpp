/* 
  Check by compiling and combining
*/

#include <stdio.h>
#include <math.h>
#include "edge.h"
#include <string.h>
#include "vertex.h"
#include <fstream>
using namespace std;
edge::edge(string file)
{
	ifstream inFile;
	inFile.open(file);
  if (!inFile) {
    cerr << "Unable to open file datafile.txt";
    exit(1);   // call system to stop
}
	inFile>>num;
	ver = new vector[num];
	adj_matrix = new bool[num][num];
	for(i=0;i<num;i++){
		inFile>>ver[i]->x>>ver[i]->y>>ver[i]->z;
	}
}
/* //number of the vertices
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
}*/

