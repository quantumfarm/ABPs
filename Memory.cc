#include "Memory.h"
#include <iostream>
using namespace std;

Memory::Memory()
{
//cout<<"Memory constructed"<<endl;
}

/* int type data creating and destroying  */

int *Memory::create_1d_int(int n){
   int *array=new int[n];
   return array;
}

void Memory::destroy_1d_int(int* &p){
   if (p==NULL) return;
   delete []p;
   p=NULL;
}

int **Memory::create_2d_int(int n1, int n2){
   int *data=new int[n1*n2];
   int **array=new int*[n1];
   for (int i=0,j=0; i<n1; i++,j=j+n2)
      array[i]=&data[j];
   return array;
}

void Memory::destroy_2d_int(int** &p){
   if (p==NULL) return;
   delete []p[0];
   delete []p;
   p=NULL;
}

int ***Memory::create_3d_int(int n1, int n2, int n3){
   int *data=new int[n1*n2*n3];
   int **plane=new int*[n1*n2];
   int ***array=new int**[n1];

   for (int i1=0; i1<n1; i1++) {
      array[i1]=&plane[i1*n2];
      for (int i2=0; i2<n2; i2++) 
         plane[i1*n2+i2]=&data[(i1*n2+i2)*n3];
   }
   return array;
}

void Memory::destroy_3d_int(int*** &p){
   if (p==NULL) return;
   delete []p[0][0];
   delete []p[0];
   delete []p;
   p=NULL;
}

int ****Memory::create_4d_int(int n1, int n2, int n3, int n4){
   int *data=new int[n1*n2*n3*n4];
   int **volume=new int*[n1*n2*n3];
   int ***plane=new int**[n1*n2];
   int ****array=new int***[n1];

   for (int i1=0; i1<n1; i1++) {
      array[i1]=&plane[i1*n2];
      for (int i2=0; i2<n2; i2++) {
         plane[i1*n2+i2]=&volume[(i1*n2+i2)*n3];
         for (int i3=0; i3<n3; i3++) {
           int nn=i1*n2*n3+i2*n3+i3;
           volume[nn]=&data[nn*n4];
         }
      }
   }
   return array;
}

void Memory::destroy_4d_int(int**** &p){
   if (p==NULL) return;
   delete []p[0][0][0];
   delete []p[0][0];
   delete []p[0];
   delete []p;
   p=NULL;
}

/* long long int type data creating and destroying  */

long long int *Memory::create_1d_longint(int n){
   long long int *array=new long long int[n];
   return array;
}

void Memory::destroy_1d_longint(long long int* &p){
   if (p==NULL) return;
   delete []p;
   p=NULL;
}

long long int **Memory::create_2d_longint(int n1, int n2){
   long long int *data=new long long int[n1*n2];
   long long int **array=new long long int*[n1];
   for (int i=0,j=0; i<n1; i++,j=j+n2)
      array[i]=&data[j];
   return array;
}

void Memory::destroy_2d_longint(long long int** &p){
   if (p==NULL) return;
   delete []p[0];
   delete []p;
   p=NULL;
}

long long int ***Memory::create_3d_longint(int n1, int n2, int n3){
   long long int *data=new long long int[n1*n2*n3];
   long long int **plane=new long long int*[n1*n2];
   long long int ***array=new long long int**[n1];
   
   for (int i1=0; i1<n1; i1++) {
      array[i1]=&plane[i1*n2];
      for (int i2=0; i2<n2; i2++)
         plane[i1*n2+i2]=&data[(i1*n2+i2)*n3];
   }
   return array;
}

void Memory::destroy_3d_longint(long long int*** &p){
   if (p==NULL) return;
   delete []p[0][0];
   delete []p[0];
   delete []p;
   p=NULL;
}

/* double type data creating and destroying  */

double *Memory::create_1d_double(int n){
   double *array=new double[n];
   return array;
}

void Memory::destroy_1d_double(double* &p){
   if (p==NULL) return;
   delete []p;
   p=NULL;
}

double **Memory::create_2d_double(int n1, int n2){
   double *data=new double[n1*n2];
   double **array=new double*[n1];
   for (int i=0; i<n1; i++)
      array[i]=&data[i*n2];
   return array;
}

void Memory::destroy_2d_double(double** &p){
   if (p==NULL) return;
   delete []p[0];
   delete []p;
   p=NULL;
}

double ***Memory::create_3d_double(int n1, int n2, int n3){
   double *data=new double[n1*n2*n3];
   double **plane=new double*[n1*n2];
   double ***array=new double**[n1];

   for (int i1=0; i1<n1; i1++) {
      array[i1]=&plane[i1*n2];
      for (int i2=0; i2<n2; i2++) 
         plane[i1*n2+i2]=&data[(i1*n2+i2)*n3];
   }
   return array;
}

void Memory::destroy_3d_double(double*** &p){
   if (p==NULL) return;
   delete []p[0][0];
   delete []p[0];
   delete []p;
   p=NULL;
}

double ****Memory::create_4d_double(int n1, int n2, int n3, int n4){
   double *data=new double[n1*n2*n3*n4];
   double **volume=new double*[n1*n2*n3];
   double ***plane=new double**[n1*n2];
   double ****array=new double***[n1];

   for (int i1=0; i1<n1; i1++) {
      array[i1]=&plane[i1*n2];
      for (int i2=0; i2<n2; i2++) {
         plane[i1*n2+i2]=&volume[(i1*n2+i2)*n3];
         for (int i3=0; i3<n3; i3++) {
           int nn=i1*n2*n3+i2*n3+i3;
           volume[nn]=&data[nn*n4];
         }
      }
   }
   return array;
}

void Memory::destroy_4d_double(double**** &p){
   if (p==NULL) return;
   delete []p[0][0][0];
   delete []p[0][0];
   delete []p[0];
   delete []p;
   p=NULL;
}

double *****Memory::create_5d_double(int n1, int n2, int n3, int n4, int n5){
   double *data=new double[n1*n2*n3*n4*n5];
   double **volume=new double*[n1*n2*n3*n4];
   double ***plane=new double**[n1*n2*n3];
   double ****array=new double***[n1*n2];
   double *****dim5=new double****[n1];

   for (int i1=0; i1<n1; i1++) {
      dim5[i1]=&array[i1*n2];
      for (int i2=0; i2<n2; i2++) {
         array[i1*n2+i2]=&plane[(i1*n2+i2)*n3];
         for (int i3=0; i3<n3; i3++) {
           int nn=i1*n2*n3+i2*n3+i3;
           plane[nn]=&volume[nn*n4];
           for (int i4=0; i4<n4; i4++){
             int nn2=i1*n2*n3*n4+i2*n3*n4+i3*n4+i4;
             volume[nn2]=&data[nn2*n5];
           }
         }
      }
   }
   return dim5;
}

void Memory::destroy_5d_double(double***** &p){
   if (p==NULL) return;
   delete []p[0][0][0][0];
   delete []p[0][0][0];
   delete []p[0][0];
   delete []p[0];
   delete []p;
   p=NULL;
}

double ******Memory::create_6d_double(int n1, int n2, int n3, int n4, int n5, int n6){
   double *data=new double[n1*n2*n3*n4*n5*n6];
   double **volume=new double*[n1*n2*n3*n4*n5];
   double ***plane=new double**[n1*n2*n3*n4];
   double ****array=new double***[n1*n2*n3];
   double *****dim5=new double****[n1*n2];
   double ******dim6=new double*****[n1];

   for (int i1=0; i1<n1; i1++) {
      dim6[i1]=&dim5[i1*n2];
      for (int i2=0; i2<n2; i2++) {
         dim5[i1*n2+i2]=&array[(i1*n2+i2)*n3];
         for (int i3=0; i3<n3; i3++) {
           int nn=i1*n2*n3+i2*n3+i3;
           array[nn]=&plane[nn*n4];
           for (int i4=0; i4<n4; i4++){
             int nn2=i1*n2*n3*n4+i2*n3*n4+i3*n4+i4;
             plane[nn2]=&volume[nn2*n5];
             for (int i5=0; i5<n5; i5++){
             	int nn3=i1*n2*n3*n4*n5+i2*n3*n4*n5+i3*n4*n5+i4*n5+i5;
             	volume[nn3]=&data[nn3*n6];
             }
           }
         }
      }
   }
   return dim6;
}

void Memory::destroy_6d_double(double****** &p){
   if (p==NULL) return;
   delete []p[0][0][0][0][0];
   delete []p[0][0][0][0];
   delete []p[0][0][0];
   delete []p[0][0];
   delete []p[0];
   delete []p;
   p=NULL;
}

string *Memory::create_1d_string(int n){
   string *array=new string[n];
   return array;
}

void Memory::destroy_1d_string(string* &p){
   if (p==NULL) return;
   delete []p;
   p=NULL;
}

bool *Memory::create_1d_bool(int n){
   bool *array=new bool[n];
   return array;
}

void Memory::destroy_1d_bool(bool* &p){
   if (p==NULL) return;
   delete []p;
   p=NULL;
}

bool **Memory::create_2d_bool(int n1, int n2){
   bool *data=new bool[n1*n2];
   bool **array=new bool*[n1];
   for (int i=0,j=0; i<n1; i++,j=j+n2)
      array[i]=&data[j];
   return array;
}

void Memory::destroy_2d_bool(bool** &p){
   if (p==NULL) return;
   delete []p[0];
   delete []p;
   p=NULL;
}

bool ***Memory::create_3d_bool(int n1, int n2, int n3){
   bool *data=new bool[n1*n2*n3];
   bool **plane=new bool*[n1*n2];
   bool ***array=new bool**[n1];

   for (int i1=0; i1<n1; i1++) {
      array[i1]=&plane[i1*n2];
      for (int i2=0; i2<n2; i2++) 
         plane[i1*n2+i2]=&data[(i1*n2+i2)*n3];
   }
   return array;
}

void Memory::destroy_3d_bool(bool*** &p){
   if (p==NULL) return;
   delete []p[0][0];
   delete []p[0];
   delete []p;
   p=NULL;
}
