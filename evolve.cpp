#include "force_bos.h"
#include "uti.h"
#include "force_fermionic.h"
#include "cg.h" 


void evolve(double x[], double p[], double Phi[], double Pi[])
{
int i;
double s[L],f[L],F[L];

cg(x,Phi,s);
force_bos(x,s,f); /* Calculates f */
force_fer(s,F); /* Calculates F */
    
for (i = 0 ; i < L ; i++){
p[i] = p[i] + (DT/2)*f[i];
Pi[i] = Pi[i] + (DT/2)*F[i];
}
        
        
for (i = 0 ; i < L ; i++){
x[i] = x[i] + (DT)*p[i];
Phi[i] = Phi[i] + (DT)*Pi[i];}
        
cg(x,Phi,s);
force_bos(x,s,f);
force_fer(s,F);
        
for (i = 0 ; i < L ; i++){
p[i] = p[i] + (DT/2)*f[i];
Pi[i] = Pi[i] + (DT/2)*F[i];
}
  
return ;
}
