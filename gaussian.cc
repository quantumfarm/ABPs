#include <iostream>
#include <fstream> // for output file
#include <sstream> // for stringstream class
#include <stdlib.h>
#include <cmath>
#include <time.h>

#include "gaussian.h"
using namespace std;

/*********************************************/
//Generator of Standard Gaussian Distribution Random Number N(nu=0,sigma=1) by Marsaglia polar method; 

//generate two independent random number with standard Gaussian distribtion N(0,1)
/*********************************************/

void Gaussian (double &x, double &y)// call by reference 
{
  double s;
  do
    {
      // rand () : get random integral number in the range between 0 and RAND_MAX
      x=rand()*2.0/RAND_MAX-1.0; 
      y=rand()*2.0/RAND_MAX-1.0;
      s=x*x+y*y;
    } while(s>=1.0);
    x=x*sqrt(-2*log(s)/s);
    y=y*sqrt(-2*log(s)/s);
    return ;
}
/***********************************************/
