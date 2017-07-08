#include "obs.h"

   
double abs (const double x[], const double y[]);

void obs_gr (Particle GP[], Particle Probe, int nd, double t){
       vector<double> point (N);
       for (int i=0; i<N;i++) {

       if (GP[i].label !=-1)      point[i]=abs(GP[i].pos, Probe.pos);
       }

       
       stringstream fn;
       fn<<"gr_Dr"<<Dr<<"_K"<<K<<"_h"<<h<<"_p"<<nd<<"_t"<<t<<".txt";
       //fn="gr";
       pdf (point, 0, Lx*0.5, 0.01, fn.str() ); 

}


double abs (const double x[], const double y[]){
    
    double s=0;
    for (int i=0; i<D;i++){
        s+=pow( (x[i]-y[i]),2);
    }
    
    return sqrt(s);    

}





