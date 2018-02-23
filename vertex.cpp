#include <stdio.h>
#include <math.h>

public class vertex{
                    public double x,y,z;
                    public rotat(double aq,double bq,double cq)
                    {
                        double d = sqrt(aq*aq+bq*bq+cq*cq);
                        double a = a/d;
                        double b = b/d;
                        double c = c/d;
                        double e = sqrt(b*b + c*c);
                        x = (e*e*x - a*b*y -a*c*z)/e;
                        y = (c*y/e) - (b*z/e);
                        z = 0;
                    }
