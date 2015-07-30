
#include "uti.h"


double energy(double p[], double Pi[])
{
int i;
double H;

H = 0 ;
for (i = 0; i < L ; i++)
{
H += 0.5* p[i]*p[i] + 0.5*Pi[i]*Pi[i];
}
return H;
}
