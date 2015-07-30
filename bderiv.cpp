
#include "uti.h"



void bderiv(double x[], double E[])
{
int i;

    for (i=0 ; i < L ; i++)
    {
        
    E[i] = x[i] - x[(i+L-1)%L];
    //E[i] = x[(i+1)%L] - x[i] ;
   
    }
    
    return;
    
    
}
