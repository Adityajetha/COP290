#include "vertex.h"
#include <stdio.h>

bool xz (vertex v, double z, double x){
         if(v.z != z) return false;
         if(v.x != x) return false;
         return true;
}
