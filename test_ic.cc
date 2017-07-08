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
#include "dyn.h"

//#include "pdf.h"
#include "field.h"

#include "obs.h"


#include<vector>


using namespace std;

int main (){


    /***************start timming***********/
    clock_t t_start, t_end; t_start=clock();
    /***************************************/
 
    double U=0;
    int nd=1;  

    //define the Probe and N bath particles GP
    Particle Probe;
    Particle *GP; GP=new Particle[N];

    // reduced density calculation
    /*****************/
    Stat gr; 
    //gr.avg_n=1000; 
    gr.avg_n=10; 
    vector< vector<double> >  f(gr.Nx, vector<double> (gr.Ny));
    vector< vector<double> >  f1(gr.Nx, vector<double> (gr.Ny));
    vector< vector<double> >  f2(gr.Nx, vector<double> (gr.Ny));
    /*****************/

    // initialize 

    IC(GP,U,nd);
    IC(Probe);

    //int loop=int (running_length/h);
    int loop=10000;
    int dl=loop/100; 
    for (int i=0;i<=loop;i++){

    //    obs_gr(GP,gr,f,i);
        //obs_current(GP,gr,f1,f2,i);
        Dyn (GP,Probe,U);
        if ((i% (dl))==0){
            cout<< i/dl<<endl; 
            Output (GP,i, nd, U); 
        }
    }



    delete [] GP;
    /*****************end-timing**************************/
    t_end=clock();
    double time=(t_end-t_start)/CLOCKS_PER_SEC;
    cout<<"running time: "<<time<<" seconds."<<endl;

    return 0;


}

