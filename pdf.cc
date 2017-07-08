/*************************************
// counting the probability distribution function  //

P(X) = dN/N /dX,

 
X=(x1,x2,..., xn) is a point in the n-dimension space, 
and the volume is dX=dx1*dx2*...dxn;

The total sampling is N. 
The number in the volume (x1, x2,..) , (x1+dx1, x2+dx2, ...,) is dN.

Ting Wang
23. June 2017
*************************************/

#include "pdf.h"
void stat (vector<int>  &Box, const vector<double>  &point,  double x_min, double x_max, double dx, int &n_samp);


//1d scale field
//input:   
//         data in point vector;  
//         stat range [x_min, dx, x_max]; 
//         file_name to store stat results. 

//output:  
//         stat results to fine_name 
void pdf (const  vector<double>  &point,  double x_min, double x_max, double dx, string file_name){

    
    //creat counting Box
    const int Nx =ceil ( (x_max-x_min) /dx );    //ceil (2.5)=3 ceil (-2.5)=-2
    vector<int>   Box(Nx);  // automatically, Box=0;
      

    //counting   x--->Box[i]
    int n_samp=0;
    stat (Box, point, x_min,x_max,dx, n_samp);
    
   
    
    //output 
    ofstream ofs; 
    ofs.open(file_name.c_str(),ios::out);

    int num=point.size();
    for (int i=0;i<Nx;i++){
        ofs
        <<x_min+i*dx+0.5*dx<<"\t" 
        <<Box[i]*1.0/n_samp/dx<<"\t"    
        <<Box[i]*1.0/n_samp/(dx* (2*Pi * (x_min+i*dx+0.5*dx)) )*Lx*Ly<<"\t"    
        <<endl; 
    }

}




//stat for 1d scale field:  f(x) 
void stat (vector<int>  &Box, const vector<double>  &point,  double x_min, double x_max, double dx, int &n_samp){


    int num=point.size();
  
    for (int i=0;i<num;i++){

            double r=point[i];  
            if ( (r>= x_min) && (r<=x_max) ){
                int n=floor( (r-x_min)/dx  );
                Box[ n ]++;
                n_samp++;
            }
    } //i


}






