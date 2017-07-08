#include "field.h"


//2d scale field
void Coarse_graining (const vector < vector<double> > &point, const vector<double>  &value, Stat &Box, vector < vector<double> > &f);
//*********************************
//1d scale field
void Coarse_graining (const vector<double> &point, const vector<double>  &value, Stat &Box, vector<double>  &f);



//1d scale field
void field (const vector<double> &point, const vector<double> &value, Stat & Box, vector<double>  &f,  string file_name, int num){

    //counting
    Coarse_graining (point, value, Box, f); // (point, value) --> (Box, f)  
    
     
    //output 
    double dv=Box.dx;
    //if (Box.n % Box.avg_n==0) {
    if (num % Box.avg_n==0) {
         
        ofstream ofs; 
        ofs.open(file_name.c_str(),ios::out);

        for (int i=0;i<Box.Nx;i++){
             
            double x=Box.x_min+i*Box.dx+0.5*Box.dx;
 
            ofs
            <<x<<"\t"; 
        
            if (num==0) 
               ofs<<f[i]/(dv*1.0)<<"\t"
                  <<endl; 

            if (num>0) 
                ofs<<f[i]/dv/Box.avg_n<<"\t"
                   <<endl; 
            

            f[i]=0;  

        }
    
    //    Box.n=0; // counting the sum of the samples; 
        
    }


}














//2d scale field
void field (const vector < vector<double> > &point, const vector<double> &value, Stat & Box, vector < vector<double> > &f,  string file_name, int num){

    //counting
    Coarse_graining (point, value, Box, f); // (point, value) --> (Box, f)  
    
     
//    Box.n++; // counting the sum of the samples; 
    //output 
    double dv=Box.dx*Box.dy;
    //if (Box.n % Box.avg_n==0) {
    if (num % Box.avg_n==0) {
         
        ofstream ofs; 
        ofs.open(file_name.c_str(),ios::out);

        for (int i=0;i<Box.Nx;i++)
        for (int j=0;j<Box.Ny;j++){
             
            double x=Box.x_min+i*Box.dx+0.5*Box.dx;
            double y=Box.y_min+j*Box.dy+0.5*Box.dy;
 
            double r=sqrt( pow(x-Lx*0.5,2)+pow(y-Ly*0.5,2) );
            double gr_theory;
            //double T_eff=v0*v0*gam/(2*Dr);
            //if (r<1) gr_theory= exp( -K*0.5* pow(r-1, 2)/T_eff ); 
            if (r>=1) gr_theory=1;
            ofs
            <<x<<"\t" 
            <<y<<"\t"; 
        
            if (num==0) 
               ofs<<f[i][j]/(dv*1.0)<<"\t"
                  <<gr_theory
                  <<endl; 

            if (num>0) 
                ofs<<f[i][j]/dv/Box.avg_n<<"\t"
                   <<gr_theory
                   <<endl; 
            

            f[i][j]=0;  

        }
    
    //    Box.n=0; // counting the sum of the samples; 
        
    }


}


//2d vector field   
void field (const vector < vector<double> > &point, const vector<double> &value1, const vector<double> &value2, Stat & Box, vector < vector<double> > &f1, vector < vector<double> > &f2,  string file_name, int num){
    //counting
    Coarse_graining (point, value1, Box, f1); // (point, value) --> (Box, f)  
    Coarse_graining (point, value2, Box, f2); // (point, value) --> (Box, f)  
    
     
//    Box.n++; // counting the sum of the samples; 
    //output 
    double dv=Box.dx*Box.dy;
    //if (Box.n % Box.avg_n==0) {
    if (num % Box.avg_n==0) {
         
        ofstream ofs; 
        ofs.open(file_name.c_str(),ios::out);

        for (int i=0;i<Box.Nx;i++)
        for (int j=0;j<Box.Ny;j++){
             
            double x=Box.x_min+i*Box.dx+0.5*Box.dx;
            double y=Box.y_min+j*Box.dy+0.5*Box.dy;
 
            ofs
            <<x<<"\t" 
            <<y<<"\t"; 
        
            if (num==0) 
               ofs
                  <<f1[i][j]/(dv*1.0)<<"\t"
                  <<f2[i][j]/(dv*1.0)<<"\t"
                  <<endl; 

            if (num>0) 
               ofs
                  <<f1[i][j]/(dv*1.0)<<"\t"
                  <<f2[i][j]/(dv*1.0)<<"\t"
                  <<endl; 

            f1[i][j]=0;  
            f2[i][j]=0;  

        }
    
        
    }


}



//stat for 2d scale field:  f(x0,x1) 
void Coarse_graining (const vector < vector<double> > &point, const vector<double>  &value, Stat &Box, vector < vector<double> > &f){

    double X_min[2],X_max[2],dX[2];    
    X_min[0]=Box.x_min;
    X_min[1]=Box.y_min;
    X_max[0]=Box.x_max;
    X_max[1]=Box.y_max;
    dX[0]=Box.dx;    
    dX[1]=Box.dy;    


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

//stat for 1d scale field:  f(x0) 
void Coarse_graining (const vector<double> &point, const vector<double>  &value, Stat &Box, vector<double>  &f){

    double X_min,X_max,dX;    
    X_min=Box.x_min;
    X_max=Box.x_max;
    dX=Box.dx;    


    int num=point.size();
    for (int i=0;i<num;i++){
        
        int n;

            double r=point[i];
            if ( (r>= X_min) && (r<=X_max) )
                n=floor( (r-X_min)/dX  );
            else return;
     
        f[ n ] +=value[i];

    } //i

}
