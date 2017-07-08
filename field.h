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



//2d scale field
void field (const vector < vector<double> > &point, const vector<double> &value, Stat & Box, vector < vector<double> > &f,  string file_name, int num);

//2d vector field
void field (const vector < vector<double> > &point, const vector<double> &value1, const vector<double> &value2, Stat & Box, vector < vector<double> > &f1, vector < vector<double> > &f2,  string file_name, int num);

//1d scale field
void field (const vector<double> &point, const vector<double> &value, Stat & Box, vector<double>  &f,  string file_name, int num);


#endif
