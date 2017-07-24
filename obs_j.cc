#include "obs.h"

double abs (const double x[], const double y[]);

inline bool exists_test0 (const string& name) {
            ifstream f(name.c_str());
                return f.good();
}


    if ((i==0)) {
        stringstream file_name;
        file_name<<"../obs/f/F"<<"_K"<<K<<"_T"<<T<<"_gam"<<gam<<"_phi"<<phi<<"_N"<<N<<"_L"<<Lx<<"_h"<<h<<"_Dr"<<Dr<<"_v"<<v0<<"_U"
<<U<<"_p"<<W;
        if ( exists_test0( file_name.str().c_str() ) )  remove( file_name.str().c_str() );
        ofs.open(file_name.str().c_str(),ofstream::app);
        ofs<<"#t\t"<<"F_x\t"<<"F_y\t"<<"Probe.n"<<endl;
   
        //Probe.n=0;
    }

void obs_j(Particle GP[], double U, int loop_i, int s, int num){

    if ( (loop_i==0) ){
        stringstream file_name;
        file_name<<"jx_pn_"<<"_K"<<K<<"_T"<<T<<"_gam"<<gam<<"_phi"<<phi<<"_N"<<N<<"_L"<<Lx<<"_h"<<h<<"_Dr"<<Dr<<"_v"<<v0<<"_U"
<<U<<"_p"<<W;
        if ( exists_test0( file_name.str().c_str() ) )  remove( file_name.str().c_str() );
        ofs.open(file_name.str().c_str(),ofstream::app);
        ofs<<"#t\t"<<"F_x\t"<<"F_y\t"<<"Probe.n"<<endl;
   
    }

    double x0=Lx/2.0;

    for (int i=0;i<N;i++){
        double vx=GP[i].vel[0]-U;
        double x=GP[i].pos[0];
        if ( (vx<0) && ( ( x-x0) >0 ) ){
            //check whether next step the particle passing through x0-plane (from x>x0 side)
            vx=(GP[i].f[0]/gam)+vx;
            if ( (x+vx*h)-x0  <0 ) s++;   
        }                 
    }
    //output 
    if ( loop_i%num ==0 ){
        

        s=0;        
    }
    

}


void obs_current (Particle GP[], Stat &gr, vector< vector<double> > &f1,  vector< vector<double> > &f2,  int num){
    
    vector< vector<double> >  point(N, vector<double> (2));

    for (int i=0;i<N;i++){
        point[i][0]=GP[i].pos[0];
        point[i][1]=GP[i].pos[1];
    }

    vector<double> value0 (N);  
    vector<double> value1 (N);  
    
    for (int i=0;i<N;i++){
        value0[i]=GP[i].vel[0]/rho;
        value1[i]=GP[i].vel[1]/rho;
    }

    stringstream fn;
    //fn<<"gr_"<<num*h<<"s_avg"<<gr.avg_n<<"_T"<<T<<"_Dr"<<Dr<<"_v"<<v0<<"_k"<<K<<"_N"<<N<<"_h"<<h<<"_old.txt";
    fn<<"current_"<<num*h<<"s_avg"<<gr.avg_n<<"_T"<<T<<"_Dr"<<Dr<<"_v"<<v0<<"_K"<<K<<"_N"<<N<<"_h"<<h<<"_dl"<<gr.dx<<"_left.txt";

    field ( point, value0, value1, gr, f1,f2, fn.str(), num);

}

