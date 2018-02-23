#include <stdio.h>
#include <math.h>

public class vertex{
                    public double x,y,z;
                    public rotat(double a,double b,double c)
                    {
                        double d = 1/sqrt(a*a+b*b+c*c);
                        double ad = a/d;
                        double bd = b/d;
                        double cd = c/d;
                        x = ad*x - bd*y -cd*z;
                        y = (c*y/sqrt (b*b + c*c)) - (b*z/sqrt (b*b + c*c));
                        z = 0;
                    }

