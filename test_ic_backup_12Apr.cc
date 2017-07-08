/* Test the initial process
"ic_new.cc"
13. March, 2017
Ting Wang
*/



#include <iostream>
#include <random>

#include <time.h> //timing


#include "myclass.h"
#include "ic.h"
//#include "pdf.h"
#include "field.h"

#include "obs.h"


#include<vector>


using namespace std;
    
 





int main () {


    /***************start timming***********/
    clock_t t_start, t_end; t_start=clock();
    /***************************************/

   
    
    double U=0;
    int nd=1;  

    //define the Probe and N bath particles GP
    Particle Probe;
    Particle *GP; GP=new Particle[N];


    /*****************/
    Stat gr; 
    /*****************/



    // initialize 
    
    for (int i=1;i<=5;i++)

       IC(GP,U,i);

       obs_gr(GP,f,i);

    IC(Probe);


    //void pdf(vector<double> &x, double x_min,double x_max,double dx, string file_name);

    vector<double> vx(N);
    vector<double> vy(N);
    vector<double> ang(N);
    vector<double> num(N,1.0);
    vector<double> num1(N,1.0/rho);

    vector< vector<double> >  r(N, vector<double> (2));
    vector< vector<double> >  v(N, vector<double> (2));

    

 
    for (int i=0;i<N;i++){
        vx[i]=GP[i].vel[0]/rho;
        vy[i]=GP[i].vel[1]/rho;


        r[i][0]=GP[i].pos[0];
        r[i][1]=GP[i].pos[1];
        v[i][0]=GP[i].vel[0]/rho;
        v[i][1]=GP[i].vel[1]/rho;
        ang[i]=GP[i].ang;
        
    }
 
    double sigma=sqrt(T);
    //pdf(vx, -10*sigma, 10*sigma, 0.1, "pdf_vx");
    //pdf(vy, -10*sigma, 10*sigma, 0.1, "pdf_vy");
    //pdf(ang, 0, 2*Pi, 0.1, "pdf_ang");
    

    
 

    //field (r, vx, vy, 0,  Lx, 0.005, 0,  Ly, 0.005, "current_field_2");
  
    // pdf(r, 0, Lx, 1, 0, Ly, 0.1,"pdf_r");    
    /*
    field (v, num,  -10*sigma,  10*sigma, 0.1, -10*sigma,  10*sigma, 0.1, "velocity_field");

    field (r, vx, vy, 0,  Lx, 0.01, 0,  Ly, 0.01, "current_field");

    field (v, num,  -10*sigma,  10*sigma, 0.1, -10*sigma,  10*sigma, 0.1, "velocity_field");
    
    field (vx, num1,  -10*sigma,  10*sigma, 0.1, "pdf_vx");
    */
    delete [] GP;

    /*****************end-timing**************************/
    t_end=clock();
    double time=(t_end-t_start)/CLOCKS_PER_SEC;
    cout<<"running time: "<<time<<" seconds."<<endl;

    return 0;

}

