#ifndef __DYN_H_INCLUDED__
#define __DYN_H_INCLUDED__

#include <iostream>
#include <string>
#include <stdlib.h>

#include <cmath>

#include "myclass.h"
#include "interaction.h"

#include<random>


#include "gaussian.h"
#include "box.h"



using namespace std;

void get_Inter_force_B(Particle GP[]);
void Dyn(Particle GP[], Particle& Probe, double U);



#endif
