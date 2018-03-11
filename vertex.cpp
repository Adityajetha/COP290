#include <stdio.h>
#include <math.h>
#include "vertex.h"

vertex::vertex(double xt,double yt,double zt)
{
    x(xt);
    y(yt);
    z(zt);
}

vertex::rotat(double aq,double bq,double cq)
{
    double d = sqrt(aq*aq+bq*bq+cq*cq);  ///Normalisation constant
    double a = aq/d;                     ///(a,b,c) is unit vector along the perpendicular to the normal
    double b = bq/d;
    double c = cq/d;
    double e = sqrt(b*b + c*c);
    x = (e*e*x - a*b*y -a*c*z)/e;
    y = (c*y/e) - (b*z/e);
    z = 0;
    ///To rotate the vertex
}
