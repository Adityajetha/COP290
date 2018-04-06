#include "myarea1.h"
#include <cairomm/context.h>
#include "vertex.h"
#include <string.h>
#include <fstream>
#include <iostream>
#include <cmath>
#include <glibmm/main.h>
using namespace std;


MyArea1::MyArea1(std::string str1,std::string str2,std::string str3)
{
   file1=str1;
   file2=str2;
   file3=str3;
   Glib::signal_timeout().connect( sigc::mem_fun(*this, &MyArea1::on_timeout), 100 );
}

MyArea1::~MyArea1()
{
}



vertex projection1 (vertex v, double plane[4]){
	///
	/// Function which returns the projection1 of a vertex on the given "plane" which has a,b,c,n stored where ax + by+ cz = d.r is the equation of the plane
	///
	vertex origin = *(new vertex(0,0,0));
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

double relative1 (vertex v, double plane[4]){
	///
	/// Mathematical function which computes the relative1 position of a point wrt a "plane" which has a,b,c,n stored where ax + by+ cz = d.r is the equation of the plane
	///
	 
	//Vector3D ver;
	//ver << v.x, v.y, v.z ;
	vertex origin = *(new vertex(0,0,0));
	vertex dir = v.sub(v,origin);
	vertex normal = *(new vertex(plane[0],plane[1],plane[2]));
	//normal << plane[0], plane[1], plane[2];
	double dotprod = normal.dot(dir);
	double val = (dotprod - plane[3])/ (v.x*v.x + v.y*v.y + v.z*v.z); 
	return val;

}

bool checkHiddenVertex1(vertex v, std::vector<int>* face, vertex* ver[]){
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
	if (v.x*plane[0] + v.y*plane[1] + v.z*plane[2] == plane[3]){
		return false;
	}
	if (relative1(v, plane) * relative1(viewingdirection, plane) >= 0) {
		return false;
	}
	else {return true;}

}


int* hiddenVertex1(vertex* ver[], vector<vector<int>*>* facelist,int num){
	///
	///given an array of vertices "vertex" with facelist being the list of all the faces and vertex 0 stored as 
	/// vector<vector<0>>.
	///
	
	int *hidden;
	int numoffaces = facelist->size();
        std::vector<int>* face;
	vertex vertex1, vertex2, vertex3, direction1,direction2,perp;
        vertex v;
        double d, n , plane[4];
	//int hidden[] = new int[size]; //keeps track of hidden vertices
	//vector<(int,int)> vertexhiddenbyface = new vector<>(); //keeps track of which vertex is hidden by which face
	for (int i = 0; i < num; i++){
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
			d = std::sqrt(perp.x*perp.x + perp.y*perp.y + perp.z*perp.z);
			n = perp.dot(vertex1);
			plane[0] = perp.x;
                        plane[1] = perp.y;
                        plane[2] = perp.z;
                        plane[3] = n;
			
			if (checkHiddenVertex1(v, face,ver)){*(hidden+4*i) = j;
							       break;}
							      //vertexhiddenbyface.push_back((i,j));}
			else {continue;}		
		}
	}	
	return hidden;	
}



void inter1(vertex* hid, vertex* show,std::vector<int>* face, vertex* ver[], double* x, double* y){
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
}

bool checkhid1(vertex* mid, std::vector<std::vector<int>*>* faces, vertex* ver[]){
 bool hid=false;
 for(int i=0;i<faces->size();i++)
 {
  hid=hid||checkHiddenVertex1(*mid,faces->at(i),ver);
 }
}

bool MyArea1::on_timeout()
{
    // force our program to redraw the entire clock.
    auto win = get_window();
    if (win)
    {
        Gdk::Rectangle r(0, 0, get_allocation().get_width(),
                get_allocation().get_height());
        win->invalidate_rect(r, false);
    }
    return true;
}



bool MyArea1::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
  Gtk::Allocation allocation = get_allocation();
  const int width = allocation.get_width();
  const int height = allocation.get_height();

  // coordinates for the center of the window
  int xc, yc,is0;
double temp1,temp2;

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
  std::ifstream inFilexy;
	inFilexy.open(file1);
  std::ifstream inFileyz;
	inFileyz.open(file2);
  std::ifstream inFilexz;
	inFilexz.open(file3);
  if (!inFilexy) {
    std::cout << "Unable to open file datafile.txt";
    exit(1);   // call system to stop
}
  if (!inFileyz) {
    std::cout << "Unable to open file datafile.txt";
    exit(1);   // call system to stop
}
  if (!inFilexz) {
    std::cout << "Unable to open file datafile.txt";
    exit(1);   // call system to stop
}
int num;
	inFilexy>>num;
	vertex* ver[num];
	bool adj_matrix1[num][num],adj_matrix2[num][num],adj_matrix3[num][num];
        int* hidden;
        int edges[num][num];
        double xint,yint;
        std::vector<std::vector<int>*>* faces = new std::vector<std::vector<int>*>;
	
	for(int i=0;i<num;i++){
ver[i]=new vertex();
		inFilexy>>ver[i]->x>>ver[i]->y;
	}

inFileyz>>temp1;
for(int i=0;i<num;i++){
		inFileyz>>temp1>>ver[i]->z;
                if((temp1-ver[i]->y>0.0001)||(ver[i]->y - temp1 >0.0001))
{///error
}
	}

inFilexz>>temp1;
for(int i=0;i<num;i++){
		inFilexz>>temp1>>temp2;
                if(((temp1 - ver[i]->x>0.0001)||(ver[i]->x - temp1 >0.0001))||((temp2 - ver[i]->z>0.0001)||(ver[i]->z - temp2 >0.0001))){}
///error
	}

for(int i=0;i<num;i++){
for(int j=0;j<num;j++){
inFilexy>>is0;
if(is0==1) adj_matrix1[i][j]=true;
else adj_matrix1[i][j]=false;}}


for(int i=0;i<num;i++){
for(int j=0;j<num;j++){
inFileyz>>is0;
if(is0==1) adj_matrix2[i][j]=true;
else adj_matrix2[i][j]=false;}}

for(int i=0;i<num;i++){
for(int j=0;j<num;j++){
inFilexz>>is0;
if(is0==1) adj_matrix3[i][j]=true;
else adj_matrix3[i][j]=false;}}

int val=0;
is0=0;
while(val>-1.5){
 faces->push_back(new std::vector<int>);
 while(val>-0.5){
  faces->back()->push_back(val);
  inFilexy>>val;
 }
 inFilexy>>val;
 is0++;
}
int num_faces=is0;


  cr->set_line_width(2.0);
inFilexy.close();
inFileyz.close();
inFilexz.close();
  // draw red lines out from the center of the window
  cr->set_source_rgb(0, 0, 0);
//while(k<10000){
bool adj_matrix[num][num];
for(int i=0;i<num;i++){
 for(int j=0;j<num;j++){
  adj_matrix[i][j]=adj_matrix1[i][j]&&adj_matrix2[i][j]&&adj_matrix3[i][j];
}
}
for(int i=0;i<num;i++){ver[i]->rotat(xr,yr,zr);*(hidden+4*i)=-1;}
///check hidden
//hidden[4]=4;
hidden = hiddenVertex1(ver, faces,num);
vertex* mid = new vertex;
for(int i=0;i<num;i++){
 for(int j=i;j<num;j++){
  if(adj_matrix[i][j]==1){
   mid -> x = (ver[i] -> x + ver[j] -> x )/2;
   mid -> y = (ver[i] -> y + ver[j] -> y )/2;
   mid -> z = (ver[i] -> z + ver[j] -> z )/2;
   if(*(hidden + 4*i)== -1 && *(hidden + 4*j)== -1 && !checkhid1(mid,faces,ver)){
    edges[i][j]=1;
    edges[j][i]=1;
   }
   else if(*(hidden + 4*i)==-1&& *(hidden + 4*j)!=-1){
    edges[i][j]=2;
    edges[j][i]=3;
   }
   else if(*(hidden + 4*i)!=-1&&*(hidden + 4*j)==-1){
    edges[i][j]=3;
    edges[j][i]=2;
   }
   else {
   edges[i][j]=4;
   edges[i][j]=4;
   }
  }
  else {edges[i][j]=0;edges[j][i]=0;}
 }
}

std::vector<double> dash = *(new std::vector<double>);
dash.push_back(4); 
std::vector<double> dash1 = *(new std::vector<double>);
dash1.push_back(4); 
dash1.push_back(0);
sleep(0.1);
  for(int i=0;i<num;i++){
    for(int j=i;j<num;j++){
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
inter1(ver[j],ver[i],faces->at(*(hidden+j*4)),ver,&xint,&yint);
std::cout<<xint<<yint;
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
inter1(ver[i],ver[j],faces->at(hidden[i]),ver,&xint,&yint);
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
cr->move_to(xc+ver[i]->x,yc+ver[i]->y);
//cr->line_to(xc+ver[j]->x,yc+ver[j]->y);
}
}

  }}
  cr->stroke();
t+=17.1;
s+=40;
zr=cos(t/180);
yr=sin(t/180);
xr=sin(s/180);
//k++;
return true;
//}
}
