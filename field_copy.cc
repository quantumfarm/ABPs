#include "field.h"


//2d scale field
void stat (vector< vector<double> > &f,  const vector < vector<double> > &point,  const vector<double>  &value,  double x_min, double x_max, double dx, double y_min, double y_max, double dy);

//2d vector field
void stat (vector< vector<double> > &fx, vector< vector<double> > &fy, const vector < vector<double> > &point,  const vector<double>  &value_x, const vector<double>  &value_y,  double x_min, double x_max, double dx, double y_min, double y_max, double dy);

//*********************************





//2d scale field
void field (const vector < vector<double> > &point, const vector<double> &value,  double x_min, double x_max, double dx, double y_min, double y_max, double dy, string file_name, int sample){

    
    //creat counting Box
    const int Nx =ceil ( (x_max-x_min) /dx );
    const int Ny =ceil ( (y_max-y_min) /dy );
  
 

    //counting
    stat (f, point, value, x_min,x_max,dx,y_min,y_max,dy);
    
    
    //output 
    ofstream ofs; 
    ofs.open(file_name.c_str(),ios::out);

    double dv=dx*dy;
    for (int i=0;i<Nx;i++)
    for (int j=0;j<Ny;j++){
        ofs
        <<x_min+i*dx+0.5*dx<<"\t" 
        <<y_min+j*dy+0.5*dy<<"\t" 
        <<f[i][j]/dv<<"\t"    
        <<endl; 
    }


}

//2d vector field
void field (const vector < vector<double> > &point, const vector<double> &value_x, const vector<double> &value_y,  double x_min, double x_max, double dx, double y_min, double y_max, double dy, string file_name){

    
    //creat counting Box
    const int Nx =ceil ( (x_max-x_min) /dx );
    const int Ny =ceil ( (y_max-y_min) /dy );
    vector < vector<double> >  fx(Nx, vector<double>(Ny) );  // automatically, f=0;
    vector < vector<double> >  fy(Nx, vector<double>(Ny) );  // automatically, f=0;
  
 

    //counting
    stat (fx,fy, point, value_x, value_y, x_min,x_max,dx,y_min,y_max,dy);
    
   
    
    //output 
    ofstream ofs; 
    ofs.open(file_name.c_str(),ios::out);

    double dv=dx*dy;
    int k=100; 
    for (int i=0;i<Nx;i=i+k)
    for (int j=0;j<Ny;j=j+k){
        ofs
        <<x_min+i*dx+0.5*dx<<"\t" 
        <<y_min+j*dy+0.5*dy<<"\t" 
        <<fx[i][j]/dv<<"\t"    
        <<fy[i][j]/dv<<"\t"    
        <<endl; 
    }


}








//stat for 2d scale field:  f(x0,x1) 
void stat (vector< vector<double> > &f,  const vector < vector<double> > &point,  const vector<double>  &value,  double x_min, double x_max, double dx, double y_min, double y_max, double dy){

    double X_min[2],X_max[2],dX[2];    
    X_min[0]=x_min;
    X_min[1]=y_min;
    X_max[0]=x_max;
    X_max[1]=y_max;
    dX[0]=dx;    
    dX[1]=dy;    


    int num=point.size();
    for (int i=0;i<num;i++){
        
        int n[2];

        for (int d=0;d<2;d++){
            double r=point[i][d];
            if ( (r>= X_min[d]) && (r<=X_max[d]) )
                n[d]=floor( (r-X_min[d])/dX[d]  );
            else return;
        }
     
        f[ n[0] ] [ n[1] ]+=value[i];

    } //i


}


//2d vector field
void stat (vector< vector<double> > &fx, vector< vector<double> > &fy, const vector < vector<double> > &point,  const vector<double>  &value_x, const vector<double>  &value_y,  double x_min, double x_max, double dx, double y_min, double y_max, double dy){


    double X_min[2],X_max[2],dX[2];    
    X_min[0]=x_min;
    X_min[1]=y_min;
    X_max[0]=x_max;
    X_max[1]=y_max;
    dX[0]=dx;    
    dX[1]=dy;    


    int num=point.size();
    for (int i=0;i<num;i++){
        
        int n[2];

        for (int d=0;d<2;d++){
            double r=point[i][d];
            if ( (r>= X_min[d]) && (r<=X_max[d]) )
                n[d]=floor( (r-X_min[d])/dX[d]  );
            else return;
        }
     
        fx[ n[0] ] [ n[1] ]+=value_x[i];
        fy[ n[0] ] [ n[1] ]+=value_y[i];

    } //i


}
