#ifndef __HEATMAP_H_INCLUDED__
#define __HEATMAP_H_INCLUDED__

#include <iostream>
#include <fstream> // for output file
#include <sstream> // for stringstream class

#include <string>

#include <stdlib.h>

#include <cmath>

#include "Memory.h"


#include <vector>
using namespace std;


//void pdf(const vector<double> &data, double x_min,double x_max,double dx, string file_name);
//void pdf (const vector < vector<double> > &data, double x_min,double x_max,double dx,  double y_min,double y_max,double dy, string file_name);

// 2d scale field
void field (const vector < vector<double> > &point, const vector<double> &value,  double x_min, double x_max, double dx, double y_min, double y_max, double dy, string file_name,int sample);




//2d vector field
void field (const vector < vector<double> > &point, const vector<double> &value_x, const vector<double> &value_y,  double x_min, double x_max, double dx, double y_min, double y_max, double dy, string file_name);



//void field (const  vector<double>  &point, const vector<double> &value,  double x_min, double x_max, double dx, string file_name);


#endif
