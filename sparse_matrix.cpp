#include "uti.h"

void sparse_matrix(double x[], double V[], double MV[])
{
int i;
for (i =0 ; i < L ; i++){
MV[i] = (m + 3*g*x[i]*x[i])*V[i] + V[i]-V[(i+L-1)%L] ; }

return;
}

