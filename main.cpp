#include "uti.h"


/* Include header files */

#include "gauss.h"
#include "update.h"
#include "action.h"
using namespace std;

#include <time.h>

// Timestamp // 
const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), " Date : %Y-%m-%d  Time : %X ", &tstruct);
    return buf;
}


// Global variables //

double DT = 0.1;
int TRAJ_LEN = int(1/DT);
int GAP = 2;   /* Measurement gap */
int TOTAL = 500; /* Total sweeps */
double m = 1.0;
double g = 1.0;  // potential parameters //
int reject=0;
double A=0.0;

/* The main loop */

int main ()
{


cout << "START" << currentDateTime() << endl;
cout << "-----------------------" << endl ; 
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
cout << "END" << currentDateTime() << endl;
cout << "-----------------------" << endl ; 
   
return 0 ;
}
