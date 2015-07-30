#include "uti.h"


void force_fer(double s[], double F[])
{
int i;

for (i= 0 ; i < L; i++)
{
F[i] = -s[i] ;  // Negative sign for force from f = -dS/dx //
}
    
return;
}
