#ifndef __HEATMAP_H_INCLUDED__
#define __HEATMAP_H_INCLUDED__

#include <iostream>
#include <fstream> // for output file
#include <sstream> // for stringstream class

#include <string>

#include <stdlib.h>

#include <cmath>

#include "para.h"


#include <vector>

using namespace std;
//1d_pdf

void pdf (const  vector<double>  &point,  double x_min, double x_max, double dx, string file_name);


#endif
