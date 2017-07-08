#include "dyn.h"

Memory *memory2;  // using Memory.cc

void PB_particle (double x[]);





//void get_SP(Particle GP[], double F_SP[][D]){
void get_SP(Particle GP[], double **F_SP){

    for (int i=0;i<N;i++){

        double eta[D];
        Gaussian (eta[0],eta[1]);
        double omega=eta[0]*sqrt(2*Dr/h); //speed of the angle: d(theta)/dt=\sqrt(2Dr)*Gaussian  (over-damped)
      
        GP[i].omg=omega+GP[i].tau; 
        //GP[i].ang=GP[i].ang+h*omega;
        GP[i].ang=GP[i].ang+h*(GP[i].tau+omega);
        
        //GP[i].ang=fmod(GP[i].ang,2*Pi); 

        double e[D];
        e[0]=cos(GP[i].ang);
        e[1]=sin(GP[i].ang);

        for (int d=0;d<D;d++)
             F_SP[i][d]=gam*v0*e[d];

    }

}


//void get_BM(Particle GP[], double F_BM[][D]){
void get_BM(Particle GP[], double **F_BM){

  const double f0=sqrt(2*gam*T/h);

  for (int i=0;i<N;i++){

      double eta[D];
      Gaussian (eta[0],eta[1]);

      for (int d=0;d<D;d++){
          F_BM[i][d]=-gam*GP[i].vel[d]+f0*eta[d];
      }

  }


}


//get interaction between the probe and bath particles
//void get_PB(Particle GP[], Particle& Probe, double F_PB[][D]){
void get_PB(Particle GP[], Particle& Probe, double **F_PB){

// clean memory of Probe
    Probe.f[0]=0;
    Probe.f[1]=0;
    Probe.tau=0;


    for (int i=0;i<N;i++){
        Particle bath=GP[i];
        bath.f[0]=0;
        bath.f[1]=0;
        bath.tau=0;

        Interaction(Probe, bath);  // get interaction force between the probe and N bath particles!
        //Interaction(bath,Probe);  // get interaction force between the probe and N bath particles!
   
        GP[i].tau+=bath.tau;
   
        double fn=sqrt( pow(bath.f[0],2)+pow(bath.f[1],2) );
        //if ((bath.f[0]*bath.f[0]+bath.f[1]*bath.f[1])>0)
        if (fn>0)
           //Probe.n++;
           Probe.n+=fn;

        for (int d=0;d<D;d++){
            F_PB[i][d]=bath.f[d];  // force acting on the particle i from the probe.
        }

    }

}



/*************************************************************************************/
void Dyn(Particle GP[], Particle& Probe, double U){

    //double F_tol[N][D],F_BM[N][D], F_SP[N][D], F_PB[N][D];
    
    double **F_tol,**F_BM, **F_SP, **F_PB;
         F_tol=memory2->create_2d_double(N,D);
         F_BM =memory2->create_2d_double(N,D);
         F_SP =memory2->create_2d_double(N,D);
         F_PB =memory2->create_2d_double(N,D);


    double F_g[D];


    //if (B_B>0) get_Inter_force_B(GP);
   // else {
        for (int i=0;i<N;i++){
            for (int d=0;d<D;d++) GP[i].f[d]=0;
            //GP[i].tau=0;
        }
   // }
    

    get_PB(GP,Probe, F_PB);

    //cout<<GP[0].f[0]<<"\t"<<Probe.f[0]<<endl;
    //get_Inter_force_B(GP);  // get interaction force between bath particles
   // get_PB(GP, Probe);// get interaction force between the probe and bath particles


    get_BM(GP, F_BM);  // get Brownian force of the bath particles
    get_SP(GP, F_SP); // get self-propelled force of the bath particles




    //Effective Drag force of bath particles in the coordinate of the probe due to pulling
    F_g[0]=-gam*U; F_g[1]=0;


    for (int i=0;i<N;i++)
    for (int d=0;d<D;d++){
         // F_tol[i][d]=GP[i].f[d]+F_BM[i][d]+F_SP[i][d]+F_g[d];
          F_tol[i][d]=GP[i].f[d]+F_PB[i][d]+F_BM[i][d]+F_SP[i][d]+F_g[d];
    }


    // update (pos, vel)
    //over-damped
        for (int i=0;i<N;i++){
            for (int d=0;d<D;d++){
                GP[i].vel[d]=(F_tol[i][d]/gam)+GP[i].vel[d];
                GP[i].pos[d]+=GP[i].vel[d]*h;
            }
            PB_particle (GP[i].pos); // Periodical boundary condition
        }




    // update (pos, vel)
    //under-damped
      /*
        for (int i=0;i<N;i++){
            for (int d=0;d<D;d++){
                GP[i].vel[d]+=F_tol[i][d]*h;
                GP[i].pos[d]+=GP[i].vel[d]*h-0.5*F_tol[i][d]*h*h;
            }
            PB_particle (GP[i].pos); // Periodical boundary condition
        }

    */



        //--------------------------------------
        memory2->destroy_2d_double(F_tol);
        memory2->destroy_2d_double(F_BM);
        memory2->destroy_2d_double(F_SP);
        memory2->destroy_2d_double(F_PB);
        //--------------------------------------

}




/*================================PBC====================================================*/
void PB_particle (double x[]){

    double L[D]; L[0]=Lx; L[1]=Ly;
    for (int d=0;d<D;d++){
        x[d]=x[d]-(floor (x[d]/L[d]))*L[d];
    }

}
