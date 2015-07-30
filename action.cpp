
#include "uti.h"
#include "bderiv.h"
#include "potential.h"
#include "cg.h"


double action(double x[], double Phi[], double &S1, double &S2){
double E[L],P[L],s[L];
int i;

S1 = 0;
S2 = 0;

bderiv(x,E);
potential(x,P);
cg(x,Phi,s);
    
for (i = 0 ; i < L ; i++){
S1 += 0.5*(E[i] + P[i]) * (E[i] + P[i]);   /* Bosonic part */
S2 += 0.5*Phi[i]*s[i];}                    /* Pseudo-fermionic part */
   
//std::cout << "Action" << S1 << std::endl ;
return S1+S2;
}












