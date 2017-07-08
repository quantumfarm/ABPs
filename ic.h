#ifndef __IC_H_INCLUDED__
#define __IC_H_INCLUDED__




#include <iostream>
#include <fstream>

#include <cmath>
#include <stdlib.h>

#include <random>



#include "myclass.h"
using namespace std;


//void IC (Particle GP[],Particle& Probe, double U,int nd);


void IC(Particle GP[], double U, int nd);
void IC (Particle& Probe);

#endif
