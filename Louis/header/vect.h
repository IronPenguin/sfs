#ifndef _VECT_H_
#define _VECT_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//typedef-----------------------------

struct svect{
 double x, y;
 };
 typedef struct svect* vect;

 struct sforce{
  vect app_point, power;
  };
  typedef struct sforce* force;

//funcdef-----------------------------
//cree un nouveau vecteur (x,y)
vect new_vect(double x, double y);
//detruit un vecteur
void destroy_vect(vect v);

//module du vecteur (captain obvious /o/)
double modulo(vect v);
//additionne le vecteur src au vecteur dst (modifie dst)
void add_vect(vect src, vect dst);
//multiplie le vecteur dst par val (modifie dst)
void mult_vect(double val, vect dst);

#endif
