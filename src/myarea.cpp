#include "myarea.h"
#include <cairomm/context.h>
#include "vertex.h"
#include <string.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

MyArea::MyArea(std::string str,double a ,double b,double c)
{
xr=a;
yr=b; 
zr=c;
   file=str;
}

MyArea::~MyArea()
{
}


vertex projection (vertex v, double plane[4]){
	///
	/// Function which returns the projection of a vertex on the given "plane" which has a,b,c,n stored where ax + by+ cz = d.r is the equation of the plane
	///
	vertex origin; origin = *(new vertex(0,0,0));
	//vertex vert;
	vertex dir = v.sub(v,origin);
	//normal << plane[0], plane[1], plane[2];
	double a = plane[0];
	double b = plane[1];
	double c = plane[2];
	vertex projectedpoint = *(new vertex);
	double n = ((plane[3]-(a*v.x+b*v.y+c*v.z))/(a*a+b*b+c*c));
	projectedpoint.x = (v.x + a*n) ;
	projectedpoint.y = (v.y + b*n) ;
	projectedpoint.z = (v.z + c*n) ;
	return projectedpoint;
}	

bool relative (vertex v, std::vector<int>* face,vertex* ver[] ){
	///
	/// Mathematical function which computes the relative1 position of a point wrt a "plane" which has a,b,c,n stored where ax + by+ cz = d.r is the equation of the plane
	///
	 
	//Vector3D ver;
	//ver << v.x, v.y, v.z ;
        double xcr,ycr,zcr;
        bool ans=false;
        for(int i=0;i<face->size();i++){xcr+=ver[(face->at(i))]->x;ycr+=ver[(face->at(i))]->y;zcr+=ver[(face->at(i))]->z;}
        xcr=xcr/face->size();
        ycr=ycr/face->size();
        zcr=zcr/face->size();
        vertex vertex1;
        vertex vertex2;
	for(int i=0;i<face->size();i++){
        vertex1 = *ver[face->at(i)];
        vertex2 = *ver[(face->at(i)+1)%face->size()];
        ans = ans||((xcr-vertex1.x)*(vertex2.y -vertex1.y)- (ycr-vertex1.y)*(vertex2.x - vertex1.x))*((v.x-vertex1.x)*(vertex2.y - vertex1.y) - (v.y-vertex1.y)*(vertex2.x - vertex1.x))<=0;
        }
	//normal << plane[0], plane[1], plane[2]; 
	return ans;

}

bool checkHiddenVertex(vertex v, std::vector<int>* face, vertex* ver[]){
	///
	/// Given the view direction as z-axis, i.e. (0,0,1) to determine if the given face hides the vertex or not 
	///
	vertex viewingdirection = *(new vertex(0,0,10000)) ;
	// 
			vertex vertex1, vertex2, vertex3;
			vertex1 = *(ver[face->at(0)]);
			vertex2 = *(ver[face->at(1)]);
			vertex3 = *(ver[face->at(2)]);
			vertex direction1 = vertex2.sub(vertex2,vertex1);
			vertex direction2 = vertex3.sub(vertex3,vertex1);
			vertex perp = direction2.cross(direction2,direction1);
			//double d = std::sqrt(perp.x*perp.x + perp.y*perp.y + perp.z*perp.z);
			double n = perp.dot(vertex1);
			double plane[] = {perp.x, perp.y, perp.z, n}; 
                        double z = (plane[3] - plane[0]*v.x + plane[1]*v.y)/(plane[2]+0.0001) ;
	if (z>0){
		return false;
	}
	else return !relative(v, face,ver);

}


vector<int> hiddenVertex(vertex* ver[], vector<vector<int>*>* facelist,int num){
	///
	///given an int vector of vertices "vertex" with facelist being the list of all the faces and vertex 0 stored as 
	/// vector<vector<0>>.
	///
	
	vector<int>* hidden = new vector<int>();
	int numoffaces = facelist->size();
        std::vector<int>* face;
	vertex vertex1, vertex2, vertex3, direction1,direction2,perp;
        vertex v;
        double d, n , plane[4];
	//int hidden[] = new int[size]; //keeps track of hidden vertices
	//vector<(int,int)> vertexhiddenbyface = new vector<>(); //keeps track of which vertex is hidden by which face
	for (int i = 0; i < num; i++){
		int flag = 0;
		v = *(ver[i]);
		//double zcoordinate = v.z;
		
		for (int j = 0; j < numoffaces; j++){
 			face = facelist->at(j);;
			vertex1 = *(ver[face->at(0)]);
			vertex2 = *(ver[face->at(1)]);
			vertex3 = *(ver[face->at(2)]);
			direction1 = vertex2.sub(vertex2,vertex1);
			direction2 = vertex3.sub(vertex3,vertex1);
			perp = direction2.cross(direction2,direction1);
			d = std::sqrt(perp.x*perp.x + perp.y*perp.y + perp.z*perp.z + 0.1);
			n = perp.dot(vertex1);
			plane[0] = perp.x;
                        plane[1] = perp.y;
                        plane[2] = perp.z;
                        plane[3] = n;
			
			if (checkHiddenVertex(v, face, ver)){hidden->push_back(j);
							     flag = 1;
							     break;}
							      //vertexhiddenbyface.push_back((i,j));}
			else {continue;}		
		}
		if (flag == 0) {hidden->push_back(-1);}
		
	}	
	return *hidden;	
}




// int* hiddenVertex(vertex* ver[], vector<vector<int>*>* facelist,int num){
// 	///
// 	///given an array of vertices "vertex" with facelist being the list of all the faces and vertex 0 stored as 
// 	/// vector<vector<0>>.
// 	///
	
// 	int *hidden;
// 	int numoffaces = facelist->size();
//         std::vector<int>* face;
// 	vertex vertex1, vertex2, vertex3, direction1,direction2,perp;
//         vertex v;
//         double d, n , plane[4];
// 	//int hidden[] = new int[size]; //keeps track of hidden vertices
// 	//vector<(int,int)> vertexhiddenbyface = new vector<>(); //keeps track of which vertex is hidden by which face
// 	for (int i = 0; i < num; i++){
// 		v = *(ver[i]);
// 		//double zcoordinate = v.z;
		
// 		for (int j = 0; j < numoffaces; j++){
//  			face = facelist->at(j);;
// 			vertex1 = *(ver[face->at(0)]);
// 			vertex2 = *(ver[face->at(1)]);
// 			vertex3 = *(ver[face->at(2)]);
// 			direction1 = vertex2.sub(vertex2,vertex1);
// 			direction2 = vertex3.sub(vertex3,vertex1);
// 			perp = direction2.cross(direction2,direction1);
// 			d = std::sqrt(perp.x*perp.x + perp.y*perp.y + perp.z*perp.z);
// 			n = perp.dot(vertex1);
// 			plane[0] = perp.x;
//                         plane[1] = perp.y;
//                         plane[2] = perp.z;
//                         plane[3] = n;
			
// 			if (checkHiddenVertex(v, face, ver)){*(hidden+4*i) = j;
// 							       break;}
// 							      //vertexhiddenbyface.push_back((i,j));}
// 			else {continue;}		
// 		}
// 	}	
// 	return hidden;	
// }


/*void inter(vertex* hid, vertex* show,std::vector<int>* face, vertex* ver[], double* x, double* y){
 double b=show->x - hid->x;
 double a=hid->y - show->y;
 double c=b*(show->y)+a*(show->x);
 double a1,b1,c1;
 vertex vertex1,vertex2;
 for(int i=0;i<face->size();i++){
  //std::cout<<"popo"<<i<<face->at(i)<<"end";
  if(i==face->size()-1){
   vertex1=*ver[face->at(i)];
   vertex2=*ver[face->at(0)];
  }
  else{
   vertex1=*ver[face->at(i)];
   vertex2=*ver[face->at(i+1)];
  }
  //std::cout<<"   asas"<<vertex1.y<<vertex2.y<<"end   ";
  b1 = vertex1.x - vertex2.x;
  a1 = vertex2.y - vertex1.y;
  c1 = b1*(vertex1.y)+a1*(vertex1.x);
  if((a1*show->x + b1*show->y - c1)*(a1*hid->x + b1*hid->y - c1)<=0&&(a*vertex1.x + b*vertex1.y - c)*(a*vertex2.x + b*vertex2.y - c)<=0){
   //std::cout<<"   "<<"YUSS"<<i<<"end   ";
   *y = (c1*a - c*a1)/(b1*a-b*a1);
   *x = (c1*b - c*b1)/(a1*b-b1*a);
   //std::cout<<"   thus"<<*x<<*y<<"end   ";
  }
 } 
}*/


bool checkhid(vertex* mid, std::vector<std::vector<int>*>* faces, vertex* ver[]){
 bool hid=false;
 for(int i=0;i<faces->size();i++)
 {
  hid=hid||checkHiddenVertex(*mid,faces->at(i),ver);
 }return hid;
}


bool MyArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
  Gtk::Allocation allocation = get_allocation();
  const int width = allocation.get_width();
  const int height = allocation.get_height();

  // coordinates for the center of the window
  int xc, yc,is0;
/*bool edge[5][5];
  int num = 5;
  vertex* ver[num];
ver[0]=new vertex();
ver[1]=new vertex();
ver[2]=new vertex();
ver[3]=new vertex();
ver[4]=new vertex();
  ver[0]->x= 50;
  ver[0]->y= 50;
ver[1]->x= 50;
  ver[1]->y= 100;
ver[2]->x= 100;
  ver[2]->y= 50;
ver[3]->x= 100;
  ver[3]->y= 100;
ver[4]->x= 75;
  ver[4]->y= 75;
for(int i =0;i<5;i++){
for(int j=0;j<5;j++){
   edge[i][j]=true;
}}*/
  xc = width / 2;
  yc = height / 2;
  std::ifstream inFile;
	inFile.open(file);
  if (!inFile) {
    std::cout << "Unable to open file datafile.txt";
    exit(1);   // call system to stop
}
int num;
	inFile>>num;
	vertex* ver[num];
	bool adj_matrix[num][num];
        int edges[num][num];
        vector<int> hidden;
        double xint,yint;
        std::vector<std::vector<int>*>* faces = new std::vector<std::vector<int>*>;
	for(int i=0;i<num;i++){
ver[i]=new vertex();
		inFile>>ver[i]->x>>ver[i]->y>>ver[i]->z;
	}

for(int i=0;i<num;i++){
for(int j=0;j<num;j++){
inFile>>is0;
if(is0==1) adj_matrix[i][j]=true;
else adj_matrix[i][j]=false;}}

int val=0;
is0=0;
while(val>-1.5){
 faces->push_back(new std::vector<int>);
 while(val>-0.5){
  faces->back()->push_back(val);
  inFile>>val;
 }
 inFile>>val;
 is0++;
}
int num_faces=is0;
  cr->set_line_width(2.0);
inFile.close();
vertex* mid = new vertex;
  // draw red lines out from the center of the window
  cr->set_source_rgb(0, 0, 0);
if(zr<0.000001&&yr<0.000001&&zr>-0.000001&&yr>-0.000001)
{xr=xr*100000 + 1;yr=0.01;}

for(int i=0;i<num;i++){ver[i]->rotat(xr,yr,zr);}//*(hidden+4*i)= -1;}
hidden = hiddenVertex(ver, faces,num);
/*hidden.push_back(-1);
hidden.push_back(-1);
hidden.push_back(-1);
hidden.push_back(-1);
hidden.push_back(-1);*/
for(int i=0;i<num;i++){
 for(int j=i;j<num;j++){
  if(adj_matrix[i][j]==1){
   mid->x=(ver[i]->x+ver[j]->x)/2;
   mid->y=(ver[i]->y+ver[j]->y)/2;
   mid->z=(ver[i]->z+ver[j]->z)/2;
   std::cout<<"x   "<<mid->x<<"   "<<mid->y<<"  "<<mid->z;
   if(hidden.at(i)== -1 && hidden.at(j)== -1 && !checkhid(mid,faces,ver)){
    edges[i][j]=1;
    edges[j][i]=1;
   }/*
   else if(hidden.at(i)==-1&&  hidden.at(j)!=-1){
    edges[i][j]=2;
    edges[j][i]=3;
   }
   else if(hidden.at(i)!=-1&&  hidden.at(j)==-1){
    edges[i][j]=3;
    edges[j][i]=2;
   }*/
   else {
   edges[i][j]=4;
   edges[i][j]=4;
   }
  }
  else {edges[i][j]=0;edges[j][i]=0;}
 }
}
//for(int i=0;i<num;i++){std::cout<<i<<"is"<<hidden.at(i)<<"   ";}
std::vector<double> dash = *(new std::vector<double>);
dash.push_back(4); 
std::vector<double> dash1 = *(new std::vector<double>);
dash1.push_back(4); 
dash1.push_back(0); 
  for(int i=0;i<num;i++){
    for(int j=i;j<num;j++){
        //std::cout<<"   "<<edges[i][j];
        if(adj_matrix[i][j])
{
if(edges[i][j]==1){
cr->move_to(xc+ver[i]->x,yc+ver[i]->y);
cr->set_dash(dash1,0);
cr->line_to(xc+ver[j]->x,yc+ver[j]->y);
cr->stroke();
}
else if(edges[i][j]==2){
///find intersection
//inter(ver[j],ver[i],faces->at(hidden.at(j)),ver,&xint,&yint);
//std::cout<<xint<<yint;
cr->move_to(xc+ver[i]->x,yc+ver[i]->y);
cr->set_dash(dash1,0);
cr->line_to(xc+xint,yc+yint);
cr->stroke();
cr->set_dash(dash,1);
cr->move_to(xc+xint,yc+yint);
cr->line_to(xc+ver[j]->x,yc+ver[j]->y);
cr->stroke();
}
else if(edges[i][j]==3){
///find intersection
//inter(ver[i],ver[j],faces->at(hidden.at(i)),ver,&xint,&yint);
cr->move_to(xc+ver[j]->x,yc+ver[j]->y);
cr->set_dash(dash1,0);
cr->line_to(xc+xint,yc+yint);
cr->stroke();
cr->set_dash(dash,1);
cr->move_to(xc+xint,yc+yint);
cr->line_to(xc+ver[i]->x,yc+ver[j]->y);
cr->stroke();
}
else{
cr->set_dash(dash,1);
cr->move_to(xc+ver[i]->x,yc+ver[i]->y);
cr->line_to(xc+ver[j]->x,yc+ver[j]->y);
cr->stroke();
}
}
  }}
  cr->set_dash(dash1,0);
  cr->stroke();

  return true;
}
