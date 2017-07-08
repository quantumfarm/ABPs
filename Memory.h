#ifndef PHL_MEMORY_H
#define PHL_MEMORY_H
#include <string>

#include "myclass.h"



class Memory{
public:
   Memory();
  
   Particle *create_particle(int);
   void destroy_particle(int*&);

   int *create_1d_int(int);
   void destroy_1d_int(int*&);

   int **create_2d_int(int,int);
   void destroy_2d_int(int**&);

   int ***create_3d_int(int,int,int);
   void destroy_3d_int(int***&);

   int ****create_4d_int(int,int,int,int);
   void destroy_4d_int(int****&);

   long long int *create_1d_longint(int);
   void destroy_1d_longint(long long int*&);

   long long int **create_2d_longint(int,int);
   void destroy_2d_longint(long long int**&);

   long long int ***create_3d_longint(int,int,int);
   void destroy_3d_longint(long long int***&);

   double *create_1d_double(int);
   void destroy_1d_double(double*&);

   double **create_2d_double(int,int);
   void destroy_2d_double(double**&);

   double ***create_3d_double(int,int,int);
   void destroy_3d_double(double***&);

   double ****create_4d_double(int,int,int,int);
   void destroy_4d_double(double****&);

   double *****create_5d_double(int,int,int,int,int);
   void destroy_5d_double(double*****&);
   
   double ******create_6d_double(int,int,int,int,int,int);
   void destroy_6d_double(double******&);

   std::string *create_1d_string(int);
   void destroy_1d_string(std::string*&);
   
   bool *create_1d_bool(int);
   void destroy_1d_bool(bool*&);   
   
   bool **create_2d_bool(int,int);
   void destroy_2d_bool(bool**&);
   
   bool ***create_3d_bool(int,int,int);
   void destroy_3d_bool(bool***&);
};

#endif

