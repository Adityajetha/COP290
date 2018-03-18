#include <stdio.h>
#include <math.h>
#include "vertex.h"

vertex::vertex(double xt,double yt,double zt)
{
    x(xt);
    y(yt);
    z(zt);
}

void vertex::rotat(double aq,double bq,double cq)
{
    double d = sqrt(aq*aq+bq*bq+cq*cq);  ///Normalisation constant
    double a = aq/d;                     ///(a,b,c) is unit vector along the perpendicular to the normal
    double b = bq/d;
    double c = cq/d;
    double e = sqrt(b*b + c*c);
    x = (e*e*x - a*b*y -a*c*z)/e;
    y = (c*y/e) - (b*z/e);
    z = a*x+b*y+c*z;
    ///To rotate the vertex
}

vertex vertex::cross(vertex v,vertex u)
{
    vertex ans = new vertex(0,0,0);
    ans.x = v.y * u.z - v.z * u.y;
    ans.y = v.z * u.x - v.x * u.z;
    ans.z = v.x * u.y - v.y * u.x;
    return ans;
}

vertex vertex::sub(vertex v, vertex u)
{
    vertex ans = new vertex(0,0,0);
    ans.x = v.x - u.x;
    ans.y = v.y - u.y;
    ans.z = v.z - u.z;
    return ans;
}

double vertex::dot(vertex v)
{
    return (x*v.X + y*v.y + z*v.z);
}

