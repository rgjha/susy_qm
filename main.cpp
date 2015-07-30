#include "uti.h"

/* Include header files */

#include "gauss.h"
#include "update.h"
#include "action.h"
using namespace std;


// Global variables //

double DT = 0.1;  /* for DT = 0.0, H is conserved completely */
int TRAJ_LEN = int(1/DT);
int GAP = 2;   /* Measurement gap */
int TOTAL = 50000; /* Total sweeps */
double m = 1.0;
double g = 1.0;  // potential parameters //
int reject=0;
double A=0.0;

/* The main loop */

int main ()
{
double x[L],Phi[L];
double S1,S2;
int sweeps;

for (int i = 0 ; i < L ; i ++){
x[i] = gauss();
Phi[i] = gauss();
}

ofstream myfile;
myfile.open ("B.dat");
ofstream myfile1;
myfile1.open ("F.dat");
    
for (sweeps = 0 ; sweeps < TOTAL ; sweeps ++){
update(x, Phi);
    
if (sweeps%GAP == 0)
    {
    action(x,Phi,S1,S2);
        myfile << S1 << endl ;
        myfile1 << S2 << endl ;
        
    }

}
cout << "acceptance: " << (sweeps-reject)/(double)sweeps << endl; 
cout << "mean Delta H/H: " << A/(double)sweeps << endl;
   
return 0 ;
}
