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
	Vertex answer;
	Vector3D origin = (0,0,0);
	Vector3D ver;
	ver << v.x, v.y, v.z ;
	Vector3D dir = ver - origin;
	Vector3D normal;
	normal << plane[0], plane[1], plane[2];
	double dist = math.sqrt(plane[0]*2 + plane[1]*2 + plane[2]*2);
	normal = normal / dist;
	double dotprod = normal.dot(dir);
	Vector3D newnormal;
	newnormal = dotprod*normal;
	Vector3D projectedpoint;
	projectedpoint = ver - newnormal;
	answer.x = ver.x ;
	answer.y = ver.y ;
	answer.z = ver.z ;
	return answer;
}	

double relative (Vertex v, double plane[4]){
	///
	/// Mathematical function which computes the relative position of a point wrt a "plane" which has a,b,c,n stored where ax + by+ cz = d.r is the equation of the plane
	///
	int val; 
	Vector3D ver;
	ver << v.x, v.y, v.z ;
	Vector3D origin = (0,0,0);
	Vector3D dir = ver - origin;
	Vector3D normal;
	normal << plane[0], plane[1], plane[2];
	double dotprod = normal.dot(dir);
	val = dotprod; 
	return val;

}

bool create3D::rayCast(Vertex ver, vector<vertex> face){
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
	Vector3D pointVertex;
	pointVertex << ver.x, ver.y, ver.z ;
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
		//NAHI BANAYA ABHI TAK. :3
		i++;
	}

	
}

bool create3D::checkHiddenVertex(Vertex ver, vector<vertex> face, double plane[4]){
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
	if (rayCast(projectedpoint, face)){
		if (relative(ver, faceplane)*relative(projectedpoint,faceplane) > 0 ){ //shows relative position wrt a plane
			ans = false;
		}
		else {ans = true;}
	}
	return ans;
} 

bool create3D::checkHiddenEdge(Edge edge, std::vector<vertex> face, double plane[4]){
	///
    /// Function to evaluate if the Edge "edge", passed as parameter is hidden by the face, 
    /// which is passed in the parameter "face", the projection being taken on the plane "plane"
    ///
	


}
