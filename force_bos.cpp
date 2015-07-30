#include "uti.h"
#include "bderiv.h"
#include "sparse_matrix.h"
#include "sparse_matrix_transpose.h"
#include "potential.h"

void force_bos(double x[], double s[], double f[])
{
double P[L],E[L],N[L],MV[L];
int i;

sparse_matrix(x,s,MV);  // Acting M on a vector which is 'x' here, Mvector[i]//
    
potential(x,P);
bderiv(x,E);
for(i=0;i< L;i++){
N[i]=P[i]+E[i];}
sparse_matrix_transpose(x,N,f);

for (i = 0 ; i < L ; i++){
f[i] = -f[i] + 6*g*x[i]*s[i]*MV[i];}

return;
}
