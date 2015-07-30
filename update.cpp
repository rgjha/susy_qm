
#include "gauss.h"
#include "evolve.h"
#include "uti.h" 
#include "energy.h"
#include "action.h"


void update(double x[], double Phi[])
{
double p[L],Pi[L],x_old[L],Phi_old[L];
int i;
double H1,H2,S1,S2;

for (i = 0; i < L ; i++){
p[i] = gauss();
Pi[i] = gauss();
//Pi[i]=0.0;
}

for (i = 0 ; i < L ; i++){
x_old[i] = x[i];            // Keep a copy of old X's to return if HMC fails //
Phi_old[i] = Phi[i];}
    
    
H1 = energy(p, Pi) + action(x,Phi,S1,S2);
//cout << "initial E is " << H1 << endl;
    
for (int step = 0 ; step < TRAJ_LEN ; step++){
evolve(x,p,Phi, Pi);
}
    
H2 = energy(p, Pi) + action(x,Phi,S1,S2);
//cout << "final E is " << H2 << endl;
    
if (drand48() > exp(H1 - H2)){              // HMC Rejected ! //
for (i = 0; i < L ; i++)
{
x[i] = x_old[i];
Phi[i] = Phi_old[i];}
    
reject+= 1;

}
A += fabs((H2-H1)/(H1));
    
return;
}

