#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "vect.h"

vect new_vect(double x, double y){
 vect v;
  v = malloc(sizeof(struct svect));
  v->x = x;
  v->y = y;
  return v;
}

void destroy_vect(vect v)
{free(v);}

double modulo(vect v){
 return sqrt((v->x)*(v->x)
    +(v->y)*(v->y));
}

void add_vect(vect src, vect dst){
 dst->x+= src->x;
 dst->y+= src->y;
}

void mult_vect(double val, vect dst){
 dst->x*=val;
 dst->y*=val;
}
