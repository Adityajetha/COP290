#include <stdio.h>
#include <math.h>

public class vertex{
                    public double x,y,z;
                    public rotat(double aq,double bq,double cq) ///To rotate the vertex for 3D to 2D projection.
                    {
                        double d = sqrt(aq*aq+bq*bq+cq*cq);  ///Normalisation constant
                        double a = aq/d;                     ///(a,b,c) is unit vector along the perpendicular to the normal
                        double b = bq/d;
                        double c = cq/d;
                        double e = sqrt(b*b + c*c);
                        x = (e*e*x - a*b*y -a*c*z)/e;
                        y = (c*y/e) - (b*z/e);
                        z = 0;
                    }
