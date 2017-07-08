#ifndef __MYCLASS_H_INCLUDED__
#define __MYCLASS_H_INCLUDED__

#include "para.h"
#include<vector>

#include <cmath>
#include <stdlib.h>

using namespace std;


class Particle {
    public:
        double pos[D];
        double vel[D];
        double f[D];
        
        double ang;
        double omg;
        double tau;

        int next;
        int label;
        double n;
        double vn;
        double fn;
       

        double r;
};


class Stat{

    public:

        const double x_min=0;
        const double x_max=Lx;

        const double y_min=0;
        const double y_max=Ly;

        const double dx=0.05;
        const double dy=0.05;

        const int Nx =ceil ( (x_max-x_min) /dx );
        const int Ny =ceil ( (y_max-y_min) /dy );
        
       // vector< vector<double> >  f(2, vector<double> (2));
       // vector< vector<double> >  f(2, vector<double> (2));

        //double f[2][2];

        int n=0;
        int avg_n;


};

class Stat2{

    public:

        const double x_min=0;
        const double x_max=Lx;

        const double y_min=0;
        const double y_max=Ly;

        const double dx=0.1;
        const double dy=0.1;

        const int Nx =ceil ( (x_max-x_min) /dx );
        const int Ny =ceil ( (y_max-y_min) /dy );
        
       // vector< vector<double> >  f(2, vector<double> (2));
       // vector< vector<double> >  f(2, vector<double> (2));

        //double f[2][2];

        int n=0;
        int avg_n;


};



#endif


