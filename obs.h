#ifndef __HEATMAP_H_INCLUDED__
#define __HEATMAP_H_INCLUDED__

#include <iostream>
#include <sstream> // for stringstream class

#include <random>

#include <time.h> //timing
#include<vector>


#include "myclass.h"
#include "ic.h"
#include "field.h"


#include "pdf.h"



using namespace std;
    
void obs_gr (Particle GP[], Stat &gr, vector< vector<double> > &f, int num);

void obs_gr (Particle GP[], Particle Probe, int nd, double t);

void pdf (const  vector<double>  &point,  double x_min, double x_max, double dx, string file_name);


void Output (Particle GP[],int i, int W, double U);
void obs_current (Particle GP[], Stat &gr, vector< vector<double> > &f1,  vector< vector<double> > &f2,  int num);


void obs_Fcol (Particle &Probe, int i,int W, double U, ofstream& ofs);


#endif
