#include <iostream>
#include <vector>
#include <Eigen/Dense>
#include <gtkmm.h>
#include <fstream>
#include <math>

using namespace std;
using Eigen::MatrixXd;

Vertex projection (Vertex v, double plane[4]){
	///
	/// Function which returns the projection of a vertex on the given "plane" which has a,b,c,n stored where ax + by+ cz = d.r is the equation of the plane
	///
	Vector3D origin = (0,0,0);
	Vector3D ver;
	ver << v.x, v.y, v.z ;
	Vector3D dir = ver - origin;
	normal << plane[0], plane[1], plane[2];
	double a = plane[0];
	double b = plane[1];
	double c = plane[2];
	Vertex projectedpoint;
	double n = ((plane[3]-(a*v.x+b*v.y+c*v.z))/(a*a+b*b+c*c));
	projectedpoint.x = (ver.x + a*n) ;
	projectedpoint.y = (ver.y + b*n) ;
	projectedpoint.z = (ver.z + c*n) ;
	return projectedpoint;
}	

double relative (Vertex v, double plane[4]){
	///
	/// Mathematical function which computes the relative position of a point wrt a "plane" which has a,b,c,n stored where ax + by+ cz = d.r is the equation of the plane
	///
	 
	Vector3D ver;
	ver << v.x, v.y, v.z ;
	Vector3D origin = (0,0,0);
	Vector3D dir = ver - origin;
	Vector3D normal;
	normal << plane[0], plane[1], plane[2];
	double dotprod = normal.dot(dir);
	double val = (dotprod - plane[3])/ (v.x*v.x + v.y*v.y + v.z*v.z); 
	return val;

}

bool pointlies(Vertex ver, vector<Vertex> face){
	///
	/// Function to check if the Vertex "ver" lies in the parameter "face" or not
	///
	int flag = 0;
	int size = face.size();
	for (int i = 0 ; i < size; i++){
		if (ver.x == face[i].x && ver.y == face[i].y && ver.z == face[i].z){
			flag = 1;
			break;
		}
	}
	if (flag == 1) {return true;}
	Vector3D pointvertex;
	pointvertex << ver.x, ver.y, ver.z ;
	Vector3D startvertex;
	Vector3D next;
	Vector3D nextTonext;
	startvertex << face[0].x, face[0].y, face[0].z;
	next << face[1].x, face[1].y, face[1].z;
	nextTonext << face[2].x, face[2].y, face[2].z;
	Vector3D perpendicular;
	perpendicular = (next - startvertex).cross(nextTonext - next); //perpendicular to the face
	int i = 0;
	for (auto it = face.begin(); it!=face.end(); it++){
		Vertex current = *it;
		Vertex next, prev;
		if (i == size - 1){
			prev = *(it - 1);
			next = face.front();
		}
		else if (i == 0){
			prev = face.back();
			next = *(it + 1);
		}
		else {
			prev = *(it - 1);
			next = *(it + 1);
		}
		//
		//Code to check if the vertex lies using "current", "next" , "prev"
		//
		Vector3D currvector, prevvector, nextvector;
		currvector << currvector.x,  currvector.y,  currvector.z;
		prevvector << prevvector.x, prevvector.y, prevvector.z;
		nextvector << nextvector.x,  nextvector.y,  nextvector.z;
		Vector3D pointdotcurr << pointvetrex.dot(currvector);
		Vector3D 
		
		
		i++;
	}

	
}



bool checkHiddenVertex(Vertex ver, vector<Vertex> face, double plane[4]){
    ///
    /// Function to check if the Point passed as parameter "vertex" is hidden by the face, 
    /// which is passed in the parameter "face", the projection being taken on the plane "plane"
    ///
	bool ans = false;
	Vertex ver1 = face[0];
	Vertex ver2 = face[1];
	Vertex ver3 = face[2];
	Vector3D vertex1, vertex2, vertex3;
	vertex1 << ver1.x, ver1.y, ver1.z;
	vertex2 << ver2.x, ver2.y, ver2.z;
	vertex3 << ver3.x, ver3.y, ver3.z;
	Vector3D direction1 = vertex2 - vertex1;
	Vector3D direction2 = vertex3 - vertex1;
	Vector3D perp = direction2.cross(direction1);
	double faceplane[4] = {perp.x(), perp.y(), perp.z(), perp.dot(vertex1)};
	Vertex projectedpoint = projection(ver,plane); //make projection
	if (pointlies(projectedpoint, face)){
		if (relative(ver, faceplane)*relative(projectedpoint,faceplane) > 0 ){ //shows relative position wrt a plane
			ans = false;
		}
		else {ans = true;}
	}
	return ans;
} 

int[] hiddenVertex(Vertex vertex[], bool edgelist[][], vector<vector<vertex>> facelist){
	///
	///given an array of vertices "vertex" with facelist being the list of all the faces and vertex 0 stored as 
	/// vector<vector<0>>.
	///
	
	int size = vertex.size();
	int[] hidden = new int[size]; //keeps track of hidden vertices
	vector<(int,int)> vertexhiddenbyface = new vector<>(); //keeps track of which vertex is hidden by which face
	for (int i = 0; i < size; i++){
		Vertex v = vertex[i];
		//double zcoordinate = v.z;
		int numoffaces = facelist.size();
		for (int j = 0; j < numoffaces; j++){
 			Vector<vertex> face = facelist.at(j);;
			Vector3D vertex1, vertex2, vertex3;
			vertex1 << vertex[0].x, vertex[0].y, vertex[0].z;
			vertex2 << vertex[1].x, vertex[1].y, vertex[1].z;
			vertex3 << vertex[2].x, vertex[2].y, vertex[2].z;
			Vector3D direction1 = vertex2 - vertex1;
			Vector3D direction2 = vertex3 - vertex1;
			Vector3D perp = direction2.cross(direction1);
			double d = math.sqrt(perp.x*perp.x + perp.y*perp.y + perp.z*perp.z);
			double n = perp.dot(vertex1);
			Vector3D normal = perp / d;
			double[4] plane = new double[];
			plane = {perp.x, perp.y, perp.z, n}; 
			if (checkHiddenVertex(v, face, plane)){hidden[i] = j;
							       break;}
							      //vertexhiddenbyface.push_back((i,j));}
			else {continue;}		
		}
	}	
	return hidden;	
}

