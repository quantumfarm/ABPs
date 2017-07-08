#include "ic.h"

void IC(Particle GP[], double U, int nd){

    // random generator    
    int seed;
    for (int lp=1;lp<=nd;lp++) seed=rand();
    mt19937   rng( seed );  // renew the seed! 
  
    uniform_real_distribution<double> uni_x(0,Lx);
    uniform_real_distribution<double> uni_y(0,Ly);
    uniform_real_distribution<double> uni_ang(0,2*Pi);
    normal_distribution<double> normal(0,1);    //mean, std derivation:sigma   e^{-(x-m)**2/2*sigma**2}
    /****************************************/
   

    for (int i=0;i<N;i++){

        double v[D]; v[0]=-U; v[1]=0;

          
        /**position distribution**/ 
        //uniform distr. of position, excluding the probe regime
        double x[D],r;
        do{
            x[0]=uni_x(rng);
            x[1]=uni_y(rng);
            r=sqrt( pow (x[0]-0.5*Lx,2) + pow (x[1]-0.5*Ly,2) );
        } while (r<2*R);

        GP[i].pos[0]=x[0];  
        GP[i].pos[1]=x[1]; 
        /************************/


 
        //clear force.
        for (int d=0;d<D;d++) GP[i].f[d]=0;
            
        //uniform angle      
        GP[i].ang=uni_ang(rng);

        GP[i].omg=0;
        GP[i].tau=0;

        GP[i].next=-1;
        GP[i].label=i;

        GP[i].r=R;
        GP[i].vn=0;
        GP[i].n=0;


        //thermal velocity with shift + self-propelled force       
        GP[i].vel[0]=sqrt(T)*normal(rng)-U+v0*cos(GP[i].ang);  // velocity relative to the probe
        GP[i].vel[1]=sqrt(T)*normal(rng)+v0*sin(GP[i].ang);



       // GP[i].vel[0]=-v0; GP[0].vel[1]=0;
       // GP[i].vel[0]=-v0; GP[1].vel[1]=0;
       // GP[i].ang=-Pi; 
       // GP[i].ang=-Pi; 
    } //loop i

}

       
 
void IC (Particle& Probe){

    Probe.pos[0]=Lx*0.5;
    Probe.pos[1]=Ly*0.5;
    Probe.r=R;
    Probe.n=0;
    Probe.omg=0;
    Probe.label=-1;

}
