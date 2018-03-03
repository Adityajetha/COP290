#include "vertex.h"
#include <stdio.h>

bool yz (vertex v, double z, double y){
         v.z = z;
         if(v.y == y) return true;
         return false;
}
