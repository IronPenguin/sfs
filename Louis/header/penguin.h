#ifndef _PENGUIN_H_
#define _PENGUIN_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//modifie la vitesse de l'element
void apply_forces(vect currentspeed, double mass, vect forces);
//met la force des frottements dans dst
void friction_power(vect dst, vect currentspeed);
//met la puissance du poids dans dst
void mass_power(vect dst, double mass);
//collision (contact) entre 2 elements -> 
//en fonction de la somme des autres forces appliquées à chacun
//la fonction l'ajoute à la somme des forces appliquées à chaque

#endif
