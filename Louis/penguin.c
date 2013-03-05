#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "vect.h"
#include "penguin.h"

//physicsfuncs------------------------
void apply_forces(vect currentspeed, double mass, vect forces){
 mult_vect(mass, forces);
 add_vect(forces, currentspeed);
}

void friction_power(vect dst, vect currentspeed){
 add_vect(currentspeed, dst);
 mult_vect(-1, dst);
}

void mass_power(vect dst, double mass){
 dst = new_vect(0,-10*mass);
}

int main(){
 vect v;
 v = new_vect(4, 3) ;
 printf("size ; %f\n", modulo(v));
 destroy_vect(v);
 return 0;
}
    
